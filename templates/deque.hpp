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
    // Deque();
    // Deque(size_type);
    // Deque(std::initializer_list<T>);
    // ~Deque();
    using DoublyLinkedList<value_type>::DoublyLinkedList;

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

template <typename T> T &Deque<T>::at(size_t){};

template <typename T> T &Deque<T>::operator[](size_t){};

template <typename T> const T &Deque<T>::operator[](size_t) const {};

template <typename T> T &Deque<T>::front(){};

template <typename T> T &Deque<T>::back(){};

// Operations
template <typename T> void Deque<T>::push_back(T){};

template <typename T> void Deque<T>::push_front(T){};

template <typename T> void Deque<T>::pop_back(){};

template <typename T> void Deque<T>::pop_front(){};

template <typename T> void Deque<T>::erase(size_t){};

template <typename T> void Deque<T>::insert(size_t, T){};

// Size and allocation
template <typename T> void Deque<T>::clear(){};
template <typename T> size_t Deque<T>::size() const {};

#endif // DEQUE_H
