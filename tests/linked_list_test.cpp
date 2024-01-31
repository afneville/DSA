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
// TEST(LinkedListTest, AppendMethod) {}
// TEST(LinkedListTest, PrependMethod) {}
// TEST(LinkedListTest, InsertMethod) {}
// TEST(LinkedListTest, DropMethod) {}
