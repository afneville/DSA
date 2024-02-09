#include "list.hpp"
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <type_traits>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T> class DoublyLinkedList : public virtual List<T> {
private:
    class Node {
    public:
        Node *next{nullptr};
        Node *prev{nullptr};
        T value;
        void *operator new(std::size_t);
        void operator delete(void *, std::size_t);
        Node(Node *next = nullptr, Node *prev = nullptr, T value = {})
            : next(next), prev(prev), value(value){};
    };
    Node *head{nullptr};
    Node *tail{nullptr};
    Node revbegin{nullptr, nullptr, T{}}; // required for reverser iterator
    int size{0};
    void swap(DoublyLinkedList<T> &, DoublyLinkedList<T> &);

public:
    DoublyLinkedList();
    DoublyLinkedList(std::initializer_list<T>);
    DoublyLinkedList(const DoublyLinkedList<T> &);
    DoublyLinkedList(DoublyLinkedList<T> &&);
    DoublyLinkedList<T> &operator=(DoublyLinkedList<T>);
    ~DoublyLinkedList();
    unsigned int length() const override;
    void append(T) override;
    void prepend(T) override;
    void insert(int, T) override;
    T drop(int, bool = 1) override;
    T &operator[](unsigned int) const override;

    template <typename ElementType> struct Iterator {
        using iterator_category = std::bidirectional_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = ElementType;
        using pointer = ElementType *;
        using reference = ElementType &;

        Iterator(Node *node) : node(node) {}

        reference operator*() const { return node->value; }
        pointer operator->() { return &node->value; }
        Iterator &operator--() {
            node = node->prev;
            return *this;
        }
        Iterator operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }
        Iterator &operator++() {
            node = node->next;
            return *this;
        }
        Iterator operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }
        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.node == b.node;
        };
        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return a.node != b.node;
        };

    private:
        Node *node;
    };

    Iterator<T> begin() { return Iterator<T>{head}; }
    Iterator<T> end() { return Iterator<T>{nullptr}; }
    Iterator<const T> cbegin() { return Iterator<const T>{head}; }
    Iterator<const T> cend() { return Iterator<const T>{nullptr}; }
    std::reverse_iterator<Iterator<T>> rbegin() {
        revbegin.prev = tail;
        return std::make_reverse_iterator(Iterator<T>{&revbegin});
    }
    std::reverse_iterator<Iterator<T>> rend() {
        return std::make_reverse_iterator(Iterator<T>{head});
    }
    std::reverse_iterator<Iterator<const T>> crbegin() {
        revbegin.prev = tail;
        return std::make_reverse_iterator(Iterator<T>{&revbegin});
    }
    std::reverse_iterator<Iterator<const T>> crend() {
        return std::make_reverse_iterator(Iterator<const T>{head});
    }
};

// Default Constructor
template <typename T> DoublyLinkedList<T>::DoublyLinkedList() {}

// Initialiser List Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(std::initializer_list<T> l) {
    for (auto i : l) {
        append(i);
    }
}

// Copy Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T> &source) {
    for (int i{0}; i < source.size; i++) {
        this->append(source[i]);
    }
}

// Move Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T> &&source) {
    std::swap(this->size, source.size);
    std::swap(this->head, source.head);
    std::swap(this->tail, source.tail);
}

// Copy Assignment
template <typename T>
DoublyLinkedList<T> &
DoublyLinkedList<T>::operator=(DoublyLinkedList<T> source) {
    this->swap(*this, source);
    return *this;
}

template <typename T>
void DoublyLinkedList<T>::swap(DoublyLinkedList<T> &a, DoublyLinkedList<T> &b) {
    std::swap(a.size, b.size);
    std::swap(a.head, b.head);
    std::swap(a.tail, b.tail);
}

template <typename T>
void *DoublyLinkedList<T>::Node::operator new(std::size_t) {
    return malloc(sizeof(DoublyLinkedList::Node));
}

template <typename T>
void DoublyLinkedList<T>::Node::operator delete(void *ptr, std::size_t) {
    if (ptr)
        free(ptr);
    return;
}

template <typename T> void DoublyLinkedList<T>::append(T value) {
    if (!tail) {
        prepend(value);
        return;
    }
    Node *tmp = new Node;
    tmp->next = nullptr;
    tmp->value = value;
    tmp->prev = tail;
    tail->next = tmp;
    tail = tmp;
    size++;
}

template <typename T> void DoublyLinkedList<T>::prepend(T value) {
    Node *tmp = new Node;
    tmp->next = head;
    if (head)
        head->prev = tmp;
    tmp->prev = nullptr;
    tmp->value = value;
    head = tmp;
    if (!tail)
        tail = tmp;
    size++;
}

template <typename T> void DoublyLinkedList<T>::insert(int index, T value) {
    if (index > size) {
        throw std::out_of_range{"List Index Out of Range"};
        return;
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    if (index == size) {
        append(value);
        return;
    }
    Node *tmp = head;
    for (int i = 0; i < index - 1; i++)
        tmp = tmp->next;
    Node *newnode = new Node;
    newnode->next = newnode;
    newnode->prev = newnode;
    std::swap(newnode->next, tmp->next);
    std::swap(newnode->prev, tmp->prev);
    newnode->value = value;
    size++;
}

template <typename T> T DoublyLinkedList<T>::drop(int index, bool bound_check) {
    if (bound_check) {
        if (index >= size) {
            throw std::out_of_range{"List Index Out of Range"};
        }
    }
    Node *tmp = head;
    T value;
    if (index == 0) {
        head = head->next;
        if (head)
            head->prev = nullptr;
        value = tmp->value;
        delete tmp;
    } else {
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        Node *old = tmp->next;
        value = old->value;
        tmp->next = old->next;
        if (old->next)
            old->next->prev = tmp;
        delete old;
    }
    if (index == size - 1) {
        tail = nullptr;
    }
    size--;
    return value;
}

template <typename T>
T &DoublyLinkedList<T>::operator[](unsigned int index) const {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <typename T> unsigned int DoublyLinkedList<T>::length() const {
    return size;
}

template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
    for (auto i = head; i;) {
        head = i->next;
        delete i;
        i = head;
    }
}

#endif // DOUBLY_LINKED_LIST_H
