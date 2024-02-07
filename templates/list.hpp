#ifndef LIST_HPP
#define LIST_HPP

template <typename T> class List {
public:
    virtual unsigned int length() const = 0;
    virtual void append(T) = 0;
    virtual void prepend(T) = 0;
    virtual void insert(int, T) = 0;
    virtual T drop(int) = 0;
    virtual T &operator[](unsigned int) const = 0;
    virtual ~List() = default;
};

template <typename T> unsigned int lengthOf(List<T> &l) { return l.length(); }

#endif // LIST_HPP
