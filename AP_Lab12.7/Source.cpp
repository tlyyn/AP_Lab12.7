#include <iostream>
#include <fstream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Функція для додавання елементу до списку
void insert(Node*& head, int val) {
    Node* newNode = new Node;
    newNode->data = val;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newNode;
}

// Функція для виведення списку на екран
void printList(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Функція для пошуку елементу у списку
bool search(Node* head, int val) {
    Node* temp = head;

    while (temp != nullptr) {
        if (temp->data == val) {
            return true;
        }
        temp = temp->next;
    }

    return false;
}

// Функція для об'єднання двох списків
Node* setUnion(Node* list1, Node* list2) {
    Node* unionList = nullptr;

    Node* temp1 = list1;
    while (temp1 != nullptr) {
        insert(unionList, temp1->data);
        temp1 = temp1->next;
    }

    Node* temp2 = list2;
    while (temp2 != nullptr) {
        if (!search(unionList, temp2->data)) {
            insert(unionList, temp2->data);
        }
        temp2 = temp2->next;
    }

    return unionList;
}

// Функція для знаходження різниці двох списків
Node* setDifference(Node* list1, Node* list2) {
    Node* diffList = nullptr;

    Node* temp1 = list1;
    while (temp1 != nullptr) {
        if (!search(list2, temp1->data)) {
            insert(diffList, temp1->data);
        }
        temp1 = temp1->next;
    }

    return diffList;
}

// Функція для знаходження перетину двох списків
Node* setIntersection(Node* list1, Node* list2) {
    Node* interList = nullptr;

    Node* temp1 = list1;
    while (temp1 != nullptr) {
        if (search(list2, temp1->data)) {
            insert(interList, temp1->data);
        }
        temp1 = temp1->next;
    }

    return interList;
}

int main()
{
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    cout << "Enter 1 to read from file or 2 to read from console:" << endl;
    int choice;
    cin >> choice;

    if (choice == 1) {
        ifstream file1("Numbers.txt");

        ifstream file2("Numbers2.txt");

        int val;
        while (file1 >> val) {
            insert(list1, val);
        }

        while (file2 >> val) {
            insert(list2, val);
        }

        file1.close();
        file2.close();

    }
    else if (choice == 2) {
        cout << "Enter values for the first list: (enter 0 to stop)" << endl;
        int val;
        while (true) {
            cin >> val;
            if (val == 0) {
                break;
            }
            insert(list1, val);
        }

        cout << "Enter values for the second list: (enter 0 to stop)" << endl;
        int val2;
        while (true) {
            cin >> val2;
            if (val2 == 0) {
                break;
            }
            insert(list2, val2);
        }
    }
    else {
        cout << "Invalid choice" << endl;
        return 1;
    }

    cout << endl;

    cout << "Union: ";
    printList(setUnion(list1, list2));
    cout << "Difference: ";
    printList(setDifference(list1, list2));
    cout << "Intersection: ";
    printList(setIntersection(list1, list2));

    return 0;
}
