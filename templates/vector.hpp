#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "array_list.hpp"
#include <cstddef>
#include <stdexcept>

template <typename T> class Vector : private ArrayList<T> {
public:
    // Types
    using value_type = T;
    using self_type = Vector<value_type>;
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
    using ArrayList<value_type>::ArrayList;

    // Element access
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

    // Size and allocation
    void clear();
    size_type size() const;
    void reserve(size_type);
    size_type capacity() const;
    void shrink_to_fit();

    // iterators
};

// Element access
template <typename T> T &Vector<T>::at(size_t index) {
    // if (index >= this->size_)
    //     throw std::out_of_range{"List Index Out of Range"};
    // return this->array[index];
    try {
        T& value = ArrayList<T>::operator[](index);
        return value;
    } catch (std::out_of_range& e) {
        throw std::out_of_range{"List Index Out of Range"};
    }
};

template <typename T> T &Vector<T>::operator[](size_t index) {
    return this->array[index];
};

template <typename T> const T &Vector<T>::operator[](size_t index) const {
    return this->array[index];
};

template <typename T> T &Vector<T>::front() { return this->array[0]; };

template <typename T> T &Vector<T>::back() {
    return this->array[this->size_ - 1];
};

// Operations
template <typename T> void Vector<T>::push_back(T value){
    this->append(value);
};

template <typename T> void Vector<T>::push_front(T value){
    this->prepend(value);
};

template <typename T> void Vector<T>::pop_back(){
    this->drop(this->size_ - 1, 0);
};

template <typename T> void Vector<T>::pop_front(){
    this->drop(0, 0);
};

template <typename T> void Vector<T>::erase(size_t index){
    this->drop(index, 0);
};

template <typename T> void Vector<T>::insert(size_t index, T value){
    ArrayList<T>::insert(index, value);
};

// Size and allocation
template <typename T> void Vector<T>::clear(){
    this->size_ = 0;
};

template <typename T> size_t Vector<T>::size() const { return this->size_; };
template <typename T> void Vector<T>::reserve(size_type){};
template <typename T> size_t Vector<T>::capacity() const {};
template <typename T> void Vector<T>::shrink_to_fit(){};

#endif // VECTOR_HPP
