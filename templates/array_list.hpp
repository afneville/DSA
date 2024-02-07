#include "list.hpp"
#include <cstring>
#include <initializer_list>
#include <stdexcept>
#include <type_traits>

#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

template <typename T> class ArrayList : public virtual List<T> {
private:
    T *array{nullptr};
    int size{0};
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
    void print() const;
    unsigned int length() const;
    void append(T);
    void prepend(T);
    void insert(int, T);
    T drop(int);
    T &operator[](unsigned int) const;
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
    this->allocated = source.size;
    this->array = static_cast<T *>(std::malloc(sizeof(T) * this->allocated));
    for (int i{0}; i < source.size; i++) {
        this->append(source[i]);
    }
};

// Move Constructor
template <typename T> ArrayList<T>::ArrayList(ArrayList<T> &&source) {
    std::swap(this->size, source.size);
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
    return size;
};

template <typename T> void ArrayList<T>::append(T value) {
    size += 1;
    while (size > allocated)
        reallocate();
    array[size - 1] = value;
};

template <typename T> void ArrayList<T>::prepend(T value) { insert(0, value); };

template <typename T> void ArrayList<T>::insert(int index, T value) {
    if (index > size)
        throw std::out_of_range{"List Index Out of Range"};
    while (size + 1 > allocated)
        reallocate();
    std::memmove(array + index + 1, array + index, sizeof(T) * (size - index));
    array[index] = value;
    size += 1;
};

template <typename T> T ArrayList<T>::drop(int index) {
    if (index >= size)
        throw std::out_of_range{"List Index Out of Range"};
    T value = array[index];
    if (size - (1 + index) > 0)
        std::memmove(array + index, array + index + 1,
                     sizeof(T) * (size - index - 1));
    size -= 1;
    return value;
};

template <typename T>
void ArrayList<T>::swap(ArrayList<T> &a, ArrayList<T> &b) {
    std::swap(a.size, b.size);
    std::swap(a.allocated, b.allocated);
    std::swap(a.array, b.array);
};

template <typename T> T &ArrayList<T>::operator[](unsigned int index) const {
    if (index >= size)
        throw std::out_of_range{"List Index Out of Range"};
    return array[index];
};

#endif // ARRAY_LIST_H
