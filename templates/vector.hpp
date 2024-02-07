#ifndef VECTOR_HPP
#define VECTOR_HPP
#include "array_list.hpp"

template <typename T> class Vector : private ArrayList<T> {
public:

    // Types
    using value_type = T;
    using self_type = Vector<value_type>;
    using reference = value_type&;
    using const_reference = const value_type&;
    using pointer = value_type*;
    using const_pointer = const pointer;
    using size_type = size_t;
    using difference_type = ptrdiff_t;
    // Iterators
    // iterator
    // const_iterator
    // reverse_iterator
    // const_reverse_iterator

    // Constructors and Destructors
    Vector();
    Vector(size_type);
    Vector(std::initializer_list<T>);
    ~Vector();

    // Element access
    reference at(size_type);
    reference operator[](size_type);
    const_reference operator[](size_type) const;
    reference front();
    reference back();

    //Operations
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

#endif // VECTOR_HPP
