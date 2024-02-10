// #include "../templates/deque.hpp"
#include "../templates/vector.hpp"
#include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

// Test Fixture
template <typename T> class StandardTemplateList : public testing::Test {
public:
    T l1{1, 2, 3};
    T l2{4, 5, 6, 7};
    T l3{8, 9, 10, 11, 12};
};

// Type Paramaters
using ListImplementations = ::testing::Types<Vector<int>>;
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
    ASSERT_EQ(this->l1[0], 1);
    ASSERT_EQ(this->l1[1], 2);
    ASSERT_EQ(this->l1[2], 3);
}

TYPED_TEST(StandardTemplateList, SafeSubscriptOperator) {
    ASSERT_EQ(this->l1.at(0), 1);
    ASSERT_EQ(this->l1.at(1), 2);
    ASSERT_EQ(this->l1.at(2), 3);
    ASSERT_THROW(this->l1.at(3), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, CopyConstructor) {
    TypeParam l4(this->l1);
    ASSERT_EQ(l4[0], this->l1[0]);
    this->l1[0] = 6;
    ASSERT_NE(this->l1[0], l4[0]);
}

TYPED_TEST(StandardTemplateList, MoveConstructor) {
    int expected_size = this->l1.size();
    int expected_element = this->l1[0];
    TypeParam l4(std::move(this->l1));
    ASSERT_EQ(l4.size(), expected_size);
    ASSERT_EQ(l4[0], expected_element);
    ASSERT_EQ(this->l1.size(), 0);
    ASSERT_THROW(this->l1.at(0), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, CopyAssignment) {
    this->l1 = this->l3;
    ASSERT_EQ(this->l1.size(), this->l3.size());
    ASSERT_EQ(this->l1[0], this->l3[0]);
    this->l1[0] += 999; // change the value of the element
    ASSERT_NE(this->l1[0], this->l3[0]);
}

TYPED_TEST(StandardTemplateList, MoveAssignment) {
    int expected_size = this->l2.size();
    int expected_element = this->l2[0];
    this->l1 = std::move(this->l2);
    ASSERT_EQ(this->l1.size(), expected_size);
    ASSERT_EQ(this->l1[0], expected_element);
    ASSERT_EQ(this->l2.size(), 0);
    ASSERT_THROW(this->l2.at(0), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, FrontReference) {
    ASSERT_EQ(this->l1.front(), this->l1[0]);
    this->l1.front() = 100;
    ASSERT_EQ(this->l1[0], 100);
}

TYPED_TEST(StandardTemplateList, BackReference) {
    ASSERT_EQ(this->l1.back(), this->l1[this->l1.size() - 1]);
    this->l1.back() = 100;
    ASSERT_EQ(this->l1[this->l1.size() - 1], 100);
}

TYPED_TEST(StandardTemplateList, PushBack) {
    int test_element = 4;
    int expected_length = 4;
    this->l1.push_back(4);
    ASSERT_EQ(this->l1.back(), test_element);
    ASSERT_EQ(this->l1.size(), expected_length);
}

TYPED_TEST(StandardTemplateList, PushFront) {
    int test_element = 0;
    int expected_length = 4;
    this->l1.push_front(test_element);
    ASSERT_EQ(this->l1.front(), test_element);
    ASSERT_EQ(this->l1.size(), expected_length);
}

TYPED_TEST(StandardTemplateList, PopBack) {
    int expected_length = 2;
    int expected_element = 2;
    this->l1.pop_back();
    ASSERT_EQ(this->l1.back(), 2);
    ASSERT_EQ(this->l1.size(), 2);
}

TYPED_TEST(StandardTemplateList, PopFront) {
    int expected_length = 2;
    int expected_element = 2;
    this->l1.pop_front();
    ASSERT_EQ(this->l1.front(), 2);
    ASSERT_EQ(this->l1.size(), 2);
}

TYPED_TEST(StandardTemplateList, Clear) {
    this->l1.clear();
    ASSERT_EQ(this->l1.size(), 0);
    ASSERT_THROW(this->l1.at(0), std::out_of_range);
}

TYPED_TEST(StandardTemplateList, Erase) {
    int expected_length = this->l3.size();
    this->l3.erase(this->l3.size() - 1);
    ASSERT_EQ(this->l3.size(), --expected_length);
    this->l3.erase(0);
    ASSERT_EQ(this->l3.size(), --expected_length);
    this->l3.erase(1);
    ASSERT_EQ(this->l3.size(), --expected_length);
    ASSERT_EQ(this->l3.front(), 9);
    ASSERT_EQ(this->l3.back(), 11);
}

TYPED_TEST(StandardTemplateList, BeginIterator) {
    ASSERT_EQ(*(this->l3.begin()), this->l3.front());
}

TYPED_TEST(StandardTemplateList, EndIterator) {
    ASSERT_EQ(*(--(this->l3.end())), this->l3.back());
}

TYPED_TEST(StandardTemplateList, ReverseBeginIterator) {
    ASSERT_EQ(*(this->l3.rbegin()), this->l3.back());
}

TYPED_TEST(StandardTemplateList, ReverseEndIterator) {
    ASSERT_EQ(*(--(this->l3.end())), this->l3.back());
}

TYPED_TEST(StandardTemplateList, ForwardIterator) {
    int expected_element = this->l3.front();
    for (auto element : this->l3) {
        ASSERT_EQ(element, expected_element++);
    }
}

TYPED_TEST(StandardTemplateList, ReverseIterator) {
    int expected_element = this->l3.back();
    for (auto i = this->l3.rbegin(); i != this->l3.rend(); ++i) {
        ASSERT_EQ(*i, expected_element--);
    }
}

TYPED_TEST(StandardTemplateList, RandomAccessIterator) {
    auto begin = this->l3.begin();
    auto end = this->l3.end();
    ASSERT_EQ(*(begin + 2), this->l3[2]);
    ASSERT_EQ(*(end - 2), this->l3[this->l3.size() - 2]);
}
