#include "list.hpp"
#include <cstddef>
#include <cstring>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <typename T> class ArrayList : public virtual List<T> {
protected:
    T *array{nullptr};
    int size_{0};
    int allocated{1};
    void swap(ArrayList<T> &, ArrayList<T> &);
    void reallocate() {
        allocated *= 2;
        array = static_cast<T *>(std::realloc(array, sizeof(T) * allocated));
    };

public:
    ArrayList();
    ArrayList(int allocated);
    ArrayList(std::initializer_list<T>);
    ArrayList(const ArrayList<T> &);
    ArrayList(ArrayList<T> &&);
    ArrayList<T> &operator=(ArrayList<T>);
    ~ArrayList();
    unsigned int length() const override;
    void append(T) override;
    void prepend(T) override;
    void insert(int, T) override;
    T drop(int, bool = 1) override;
    T &operator[](size_t) override;
    const T &operator[](size_t) const override;
};

template <typename T> ArrayList<T>::ArrayList() {
    this->array = static_cast<T *>(std::malloc(sizeof(T) * this->allocated));
}
template <typename T> ArrayList<T>::ArrayList(int allocated) {
    this->allocated = allocated;
    this->array = static_cast<T *>(std::malloc(sizeof(T) * this->allocated));
};

template <typename T> ArrayList<T>::ArrayList(std::initializer_list<T> l) {
    this->allocated = l.size();
    this->array = static_cast<T *>(std::malloc(sizeof(T) * this->allocated));
    for (auto i : l) {
        append(i);
    }
};

// Copy Constructor
template <typename T> ArrayList<T>::ArrayList(const ArrayList<T> &source) {
    this->allocated = source.size_;
    this->array = static_cast<T *>(std::malloc(sizeof(T) * this->allocated));
    for (int i{0}; i < source.size_; i++) {
        this->append(source[i]);
    }
};

// Move Constructor
template <typename T> ArrayList<T>::ArrayList(ArrayList<T> &&source) {
    std::swap(this->size_, source.size_);
    std::swap(this->allocated, source.allocated);
    std::swap(this->array, source.array);
};

// Move Copy Swap Assignment
template <typename T>
ArrayList<T> &ArrayList<T>::operator=(ArrayList<T> source) {
    this->swap(*this, source);
    return *this;
};

template <typename T> ArrayList<T>::~ArrayList() {
    if (array)
        std::free(array);
};

template <typename T> unsigned int ArrayList<T>::length() const {
    return size_;
};

template <typename T> void ArrayList<T>::append(T value) {
    size_ += 1;
    while (size_ > allocated)
        reallocate();
    array[size_ - 1] = value;
};

template <typename T> void ArrayList<T>::prepend(T value) { insert(0, value); };

template <typename T> void ArrayList<T>::insert(int index, T value) {
    if (index > size_)
        throw std::out_of_range{"List Index Out of Range"};
    while (size_ + 1 > allocated)
        reallocate();
    std::memmove(array + index + 1, array + index, sizeof(T) * (size_ - index));
    array[index] = value;
    size_ += 1;
};

template <typename T> T ArrayList<T>::drop(int index, bool bound_checking) {
    if (bound_checking) {
        if (index >= size_)
            throw std::out_of_range{"List Index Out of Range"};
    }
    T value = array[index];
    if (size_ - (1 + index) > 0)
        std::memmove(array + index, array + index + 1,
                     sizeof(T) * (size_ - index - 1));
    size_ -= 1;
    return value;
};

template <typename T>
void ArrayList<T>::swap(ArrayList<T> &a, ArrayList<T> &b) {
    std::swap(a.size_, b.size_);
    std::swap(a.allocated, b.allocated);
    std::swap(a.array, b.array);
};

template <typename T> T &ArrayList<T>::operator[](size_t index) {
    if (index >= size_)
        throw std::out_of_range{"List Index Out of Range"};
    return array[index];
};

template <typename T> const T &ArrayList<T>::operator[](size_t index) const {
    if (index >= size_)
        throw std::out_of_range{"List Index Out of Range"};
    return array[index];
};

#endif // ARRAY_LIST_H
