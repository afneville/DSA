#include "../templates/linked_list.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

TEST(LinkedListTest, DefaultIntialisation) {
    LinkedList<int> l {};
    ASSERT_EQ(lengthOf(l), 0);
}
TEST(LinkedListTest, ListIntialisation) {
    LinkedList<int> l {3,4,5};
    ASSERT_EQ(lengthOf(l), 3);
}
TEST(LinkedListTest, SubscriptOperator) {
    LinkedList<int> l {3,4,5};
    ASSERT_EQ(l[0], 3);
    ASSERT_EQ(l[1], 4);
    ASSERT_EQ(l[2], 5);
    ASSERT_THROW(l[3], std::out_of_range);
}
TEST(LinkedListTest, CopyConstructor) {
    LinkedList<int> l1 {3,4,5};
    LinkedList<int> l2(l1);
    ASSERT_EQ(l1[0], l2[0]);
    l1[0] = 6;
    ASSERT_NE(l1[0], l2[0]);
}

TEST(LinkedListTest, MoveConstructor) {
    LinkedList<int> l1 {3,4,5};
    LinkedList<int> l2(std::move(l1));
    ASSERT_EQ(lengthOf(l2), 3);
    ASSERT_EQ(l2[0], 3);
    ASSERT_EQ(lengthOf(l1), 0);
    ASSERT_THROW(l1[0], std::out_of_range);
}

TEST(LinkedListTest, CopySwapMoveAssignment) {
    LinkedList<int> l1 {3,4,5};
    LinkedList<int> l2 {6,7,8,9};
    LinkedList<int> l3 {10,11,12,13,14};

    l1 = l2;
    ASSERT_EQ(lengthOf(l1), 4);
    ASSERT_EQ(l1[0], l2[0]);
    l1[0] = 7;
    ASSERT_NE(l1[0], l2[0]);

    l1 = std::move(l3);
    ASSERT_EQ(lengthOf(l1), 5);
    ASSERT_EQ(l1[3], 13);
    ASSERT_THROW(l3[0], std::out_of_range);
}


// TEST(LinkedListTest, AppendMethod) {}
// TEST(LinkedListTest, PrependMethod) {}
// TEST(LinkedListTest, InsertMethod) {}
// TEST(LinkedListTest, DropMethod) {}
