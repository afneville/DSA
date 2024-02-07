#include "../templates/vector.hpp"
#include "../templates/deque.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

// Test Fixture
template <typename T> class StandardTemplateList : public testing::Test {
public:
};

// Type Paramaters
using ListImplementations = ::testing::Types<Vector<int>, Deque<int>>;
TYPED_TEST_SUITE(StandardTemplateList, ListImplementations);

// Tests
TYPED_TEST(StandardTemplateList, DefaultIntialisation) {
    TypeParam l{};
    ASSERT_EQ(l.size(), 0);
}

TYPED_TEST(StandardTemplateList, ListIntialisation) {
    TypeParam l{3, 4, 5};
    ASSERT_EQ(l.size(), 3);
}

TYPED_TEST(StandardTemplateList, SubscriptOperator) {
    TypeParam l{3, 4, 5};
    ASSERT_EQ(l[0], 3);
    ASSERT_EQ(l[1], 4);
    ASSERT_EQ(l[2], 5);
}

TYPED_TEST(StandardTemplateList, SafeSubscriptOperator) {
    TypeParam l{3, 4, 5};
    ASSERT_EQ(l.at(0), 3);
    ASSERT_EQ(l.at(1), 4);
    ASSERT_EQ(l.at(2), 5);
    ASSERT_THROW(l.at(3), std::out_of_range);
}


TYPED_TEST(StandardTemplateList, CopyConstructor) {
    TypeParam l1{3, 4, 5};
    TypeParam l2(l1);
    ASSERT_EQ(l1[0], l2[0]);
    l1[0] = 6;
    ASSERT_NE(l1[0], l2[0]);
}

TYPED_TEST(StandardTemplateList, MoveConstructor) {
    TypeParam l1{3, 4, 5};
    TypeParam l2(std::move(l1));
    ASSERT_EQ(l2.size(), 3);
    ASSERT_EQ(l2[0], 3);
    ASSERT_EQ(l1.size(), 0);
    ASSERT_THROW(l1.at(0), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, CopySwapMoveAssignment) {
    TypeParam l1{3, 4, 5};
    TypeParam l2{6, 7, 8, 9};
    TypeParam l3{10, 11, 12, 13, 14};

    l1 = l2;
    ASSERT_EQ(l1.size(), 4);
    ASSERT_EQ(l1[0], l2[0]);
    l1[0] = 7;
    ASSERT_NE(l1[0], l2[0]);

    l1 = std::move(l3);
    ASSERT_EQ(l1.size(), 5);
    ASSERT_EQ(l1[3], 13);
    ASSERT_THROW(l3.at(0), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, TestFrontReference) {
    TypeParam l1{3, 4, 5};
    ASSERT_EQ(l1.front(), 3);
}

TYPED_TEST(StandardTemplateList, TestBackReference) {
    TypeParam l1{3, 4, 5};
    ASSERT_EQ(l1.back(), 5);
}

TYPED_TEST(StandardTemplateList, TestPushBack) {
    TypeParam l1{3, 4, 5};
    l1.push_back(6);
    ASSERT_EQ(l1.back(), 6);
    ASSERT_EQ(l1.size(), 4);
}

TYPED_TEST(StandardTemplateList, TestPushFront) {
    TypeParam l1{3, 4, 5};
    l1.push_front(2);
    ASSERT_EQ(l1.front(), 2);
    ASSERT_EQ(l1.size(), 4);
}

TYPED_TEST(StandardTemplateList, TestPopBack) {
    TypeParam l1{3, 4, 5};
    l1.pop_back();
    ASSERT_EQ(l1.back(), 4);
    ASSERT_EQ(l1.size(), 2);
}

TYPED_TEST(StandardTemplateList, TestPopFront) {
    TypeParam l1{3, 4, 5};
    l1.pop_front();
    ASSERT_EQ(l1.front(), 4);
    ASSERT_EQ(l1.size(), 2);
}
// TYPED_TEST(StandardTemplateList, TestErase) {}
TYPED_TEST(StandardTemplateList, TestClear) {
    TypeParam l1{3, 4, 5};
    l1.clear();
    ASSERT_EQ(l1.size(), 0);
    ASSERT_THROW(l1.at(0), std::out_of_range);
}














//
// TYPED_TEST(StandardTemplateList, AppendMethod) {
//     TypeParam l1{};
//     ASSERT_EQ(lengthOf(l1), 0);
//     ASSERT_THROW(l1[0], std::out_of_range);
//     for (auto i : {0, 1, 2, 3, 4}) {
//         l1.append(i);
//         ASSERT_NO_THROW(l1[i]);
//         ASSERT_EQ(l1[i], i);
//         ASSERT_EQ(l1[i], i);
//         ASSERT_EQ(l1[i], i);
//     }
//     ASSERT_THROW(l1[5], std::out_of_range);
// }
//
// TYPED_TEST(ListTest, PrependMethod) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     l1.prepend(2);
//     ASSERT_EQ(lengthOf(l1), 6);
//     l1.prepend(1);
//     ASSERT_EQ(lengthOf(l1), 7);
//     ASSERT_EQ(l1[0], 1);
//     ASSERT_EQ(l1[1], 2);
// }
//
// TYPED_TEST(ListTest, InsertMiddle) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     l1.insert(3, 10);
//     ASSERT_EQ(lengthOf(l1), 6);
//     ASSERT_EQ(l1[3], 10);
// }
//
// TYPED_TEST(ListTest, InsertStart) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     l1.insert(0, 2);
//     ASSERT_EQ(lengthOf(l1), 6);
//     l1.insert(0, 1);
//     ASSERT_EQ(lengthOf(l1), 7);
//     ASSERT_EQ(l1[0], 1);
//     ASSERT_EQ(l1[1], 2);
// }
//
// TYPED_TEST(ListTest, InsertEnd) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     l1.insert(5, 8);
//     ASSERT_EQ(lengthOf(l1), 6);
//     ASSERT_EQ(l1[5], 8);
//     ASSERT_THROW(l1.insert(7, 10), std::out_of_range);
// }
//
// TYPED_TEST(ListTest, DropMiddle) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     ASSERT_EQ(l1.drop(2), 5);
//     ASSERT_EQ(lengthOf(l1), 4);
//     ASSERT_EQ(l1[1], 4);
//     ASSERT_EQ(l1[2], 6);
// }
//
// TYPED_TEST(ListTest, DropStart) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     ASSERT_EQ(l1.drop(0), 3);
//     ASSERT_EQ(lengthOf(l1), 4);
//     ASSERT_EQ(l1.drop(0), 4);
//     ASSERT_EQ(lengthOf(l1), 3);
//     ASSERT_EQ(l1[0], 5);
//     ASSERT_EQ(l1[1], 6);
// }
//
// TYPED_TEST(ListTest, DropEnd) {
//     TypeParam l1{3, 4, 5, 6, 7};
//     ASSERT_EQ(l1.drop(4), 7);
//     ASSERT_THROW(l1.drop(4), std::out_of_range);
//     ASSERT_EQ(lengthOf(l1), 4);
// }
//
// TYPED_TEST(ListTest, DropStartEnd) {
//     TypeParam l1{2};
//     ASSERT_EQ(l1.drop(0), 2);
//     ASSERT_EQ(lengthOf(l1), 0);
// }
