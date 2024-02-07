#include "doubly_linked_list.hpp"

#ifndef DEQUE_H
#define DEQUE_H

template <typename T> class Deque : private DoublyLinkedList<T> {
public:

    // Types
    using value_type = T;
    using self_type = Deque<value_type>;
    using reference = value_type &;
    using const_reference = const value_type &;
    using pointer = value_type *;
    using const_pointer = const pointer;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    // Iterators
    // iterator
    // const_iterator
    // reverse_iterator
    // const_reverse_iterator

    // Constructors and Destructors
    Deque();
    Deque(size_type);
    Deque(std::initializer_list<T>);
    ~Deque();

    // Element Access
    reference at(size_type);
    reference operator[](size_type);
    const_reference operator[](size_type) const;
    reference front();
    reference back();

    // Operations
    void push_back(value_type);
    void push_front(value_type);
    void pop_back();
    void pop_front();
    void erase(size_type);
    void insert(size_type, value_type);

    // Size and Allocation
    void clear();
    size_type size() const;
};

#endif // DEQUE_H
