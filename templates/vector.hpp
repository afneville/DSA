#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "array_list.hpp"
#include <cstddef>
#include <stdexcept>

template <typename T> class Vector : private ArrayList<T> {
public:
    // Types
    using value_type = T;
    using reference = value_type &;
    using const_reference = const value_type &;
    using difference_type = ptrdiff_t;
    using size_type = size_t;
    using iterator = typename ArrayList<value_type>::template Iterator<value_type>;
    using const_iterator = typename ArrayList<value_type>::template Iterator<const value_type>;

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

    using ArrayList<T>::begin;
    using ArrayList<T>::end;
    using ArrayList<T>::cbegin;
    using ArrayList<T>::cend;
    using ArrayList<T>::rbegin;
    using ArrayList<T>::rend;
    using ArrayList<T>::crbegin;
    using ArrayList<T>::crend;
};

// Element access
template <typename T> T &Vector<T>::at(size_t index) {
    try {
        T &value = ArrayList<T>::operator[](index);
        return value;
    } catch (std::out_of_range &e) {
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
template <typename T> void Vector<T>::push_back(T value) {
    this->append(value);
};

template <typename T> void Vector<T>::push_front(T value) {
    this->prepend(value);
};

template <typename T> void Vector<T>::pop_back() {
    this->drop(this->size_ - 1, 0);
};

template <typename T> void Vector<T>::pop_front() { this->drop(0, 0); };

template <typename T> void Vector<T>::erase(size_t index) {
    this->drop(index, 0);
};

template <typename T> void Vector<T>::insert(size_t index, T value) {
    ArrayList<T>::insert(index, value);
};

// Size and allocation
template <typename T> void Vector<T>::clear() { this->size_ = 0; };

template <typename T> size_t Vector<T>::size() const { return this->size_; };
template <typename T> void Vector<T>::reserve(size_type capacity) {
    if (capacity > this->allocated) {
        this->allocated = capacity;
        this->array = static_cast<T *>(
            std::realloc(this->array, sizeof(T) * this->allocated));
    }
};

template <typename T> size_t Vector<T>::capacity() const {
    return this->allocated;
};

template <typename T> void Vector<T>::shrink_to_fit() {
    this->allocated = this->size_;
    this->array = static_cast<T *>(
        std::realloc(this->array, sizeof(T) * this->allocated));
};

#endif // VECTOR_HPP
