#ifndef LIST_HPP
#define LIST_HPP

#include <cstddef>
template <typename T> class List {
public:
    virtual unsigned int length() const = 0;
    virtual void append(T) = 0;
    virtual void prepend(T) = 0;
    virtual void insert(int, T) = 0;
    virtual T drop(int, bool) = 0;
    virtual T &operator[](size_t) = 0;
    virtual const T &operator[](size_t) const = 0;
    virtual ~List() = default;
};

template <typename T> unsigned int lengthOf(List<T> &l) { return l.length(); }

#endif // LIST_HPP
