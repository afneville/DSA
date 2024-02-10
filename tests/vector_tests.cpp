#include "../templates/vector.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

TEST(VectorTest, TestReserve) {
    Vector<int> l = {1,2,3,4,5,6};
    int capacity = l.capacity();
    l.reserve(100);
    ASSERT_GE(l.capacity(), capacity);
    ASSERT_EQ(l.capacity(), 100);
}

TEST(VectorTest, TestShrinkToFit) {
    Vector<int> l = {1,2,3,4,5,6};
    l.reserve(100);
    ASSERT_EQ(l.capacity(), 100);
    l.shrink_to_fit();
    ASSERT_EQ(l.capacity(), 6);
}
