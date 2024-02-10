#include "doubly_linked_list.hpp"

#ifndef DEQUE_H
#define DEQUE_H

template <typename T> class Deque : private DoublyLinkedList<T> {
public:

    using DoublyLinkedList<T>::Node;
    // Types
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using difference_type = ptrdiff_t;
    using size_type = size_t;
    using iterator = typename Deque<value_type>::template Iterator<value_type>;
    using const_iterator = typename Deque<value_type>::template Iterator<const value_type>;

    // Constructors and Destructors
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

    // Iterators
    using DoublyLinkedList<T>::begin;
    using DoublyLinkedList<T>::end;
    using DoublyLinkedList<T>::cbegin;
    using DoublyLinkedList<T>::cend;
    using DoublyLinkedList<T>::rbegin;
    using DoublyLinkedList<T>::rend;
    using DoublyLinkedList<T>::crbegin;
    using DoublyLinkedList<T>::crend;
};


template <typename T> T &Deque<T>::at(size_t index){
    try {
        T &value = DoublyLinkedList<T>::operator[](index);
        return value;
    } catch (std::out_of_range &e) {
        throw std::out_of_range{"List Index Out of Range"};
    }
};

template <typename T> T &Deque<T>::operator[](size_t index){
    auto tmp = this->head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
};

template <typename T> const T &Deque<T>::operator[](size_t index) const {
    auto tmp = this->head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
};

template <typename T> T &Deque<T>::front(){
    return this->head->value;
};

template <typename T> T &Deque<T>::back(){
    return this->tail->value;
};

// Operations
template <typename T> void Deque<T>::push_back(T value){
    this->append(value);
};

template <typename T> void Deque<T>::push_front(T value){
    this->prepend(value);
};

template <typename T> void Deque<T>::pop_back(){
    auto tmp = this->tail;
    this->tail = tmp->prev;
    if (this->tail)
        this->tail->next = nullptr;
    delete tmp;
    this->size_--;
};

template <typename T> void Deque<T>::pop_front(){
    this->drop(0, 0);
};

template <typename T> void Deque<T>::erase(size_t index){
    this->drop(index, 0);
};

template <typename T> void Deque<T>::insert(size_t index, T value){
    this->insert(index, value);
};

// Size and allocation
template <typename T> void Deque<T>::clear(){
    int size__ = this->size_;
    for (auto i = 0; i < size__; i++)
        this->drop(0, 0);
};

template <typename T> size_t Deque<T>::size() const {
    return this->size_;
};

#endif // DEQUE_H
