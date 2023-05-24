#include "pch.h"
#include "CppUnitTest.h"
#include "../AP_Lab12.7/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			Node* list1 = nullptr;
			Node* list2 = nullptr;

			insert(list1, 2);
			insert(list1, 3);

			bool t = search(list1, 2);
			Assert::AreEqual(t, true);
		}
	};
}
