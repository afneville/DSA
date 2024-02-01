#include "list.hpp"
#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <type_traits>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
// Linked List Template

template <typename T> class LinkedList : public virtual List<T> {
private:
    class Node {
    public:
        Node *next{nullptr};
        T value;
        void *operator new(std::size_t);
        void operator delete(void *, std::size_t);
    };
    Node *head{nullptr};
    Node *tail{nullptr};
    int size{0};
    void swap(LinkedList<T> &, LinkedList<T> &);

public:
    LinkedList();
    LinkedList(std::initializer_list<T>);
    LinkedList(const LinkedList<T> &);
    LinkedList(LinkedList<T> &&);
    LinkedList<T> &operator=(LinkedList<T>);
    ~LinkedList();
    void print() const;
    unsigned int length() const;
    void append(T);
    void prepend(T);
    void insert(int, T);
    T drop(int);
    T &operator[](unsigned int) const;
};

// Default Constructor
template <typename T> LinkedList<T>::LinkedList() {}

// Initialiser List Constructor
template <typename T> LinkedList<T>::LinkedList(std::initializer_list<T> l) {
    for (auto i : l) {
        append(i);
    }
}

// Copy Constructor
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T> &source) {
    for (int i{0}; i < source.size; i++) {
        this->append(source[i]);
    }
}

// Move Constructor
template <typename T> LinkedList<T>::LinkedList(LinkedList<T> &&source) {
    std::swap(this->size, source.size);
    std::swap(this->head, source.head);
    std::swap(this->tail, source.tail);
}

// Copy Assignment
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> source) {
    this->swap(*this, source);
    return *this;
}

template <typename T>
void LinkedList<T>::swap(LinkedList<T> &a, LinkedList<T> &b) {
    std::swap(a.size, b.size);
    std::swap(a.head, b.head);
    std::swap(a.tail, b.tail);
}

template <typename T> void *LinkedList<T>::Node::operator new(std::size_t) {
    return malloc(sizeof(LinkedList::Node));
}

template <typename T>
void LinkedList<T>::Node::operator delete(void *ptr, std::size_t) {
    if (ptr)
        free(ptr);
    return;
}
template <typename T> void LinkedList<T>::append(T value) {
    if (!tail) {
        prepend(value);
        return;
    }
    Node *tmp = new Node;
    tmp->next = nullptr;
    tmp->value = value;
    tail->next = tmp;
    tail = tmp;
    size++;
}

template <typename T> void LinkedList<T>::prepend(T value) {
    Node *tmp = new Node;
    tmp->next = head;
    tmp->value = value;
    head = tmp;
    if (!tail)
        tail = tmp;
    size++;
}
template <typename T> void LinkedList<T>::insert(int index, T value) {
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
    std::swap(newnode->next, tmp->next);
    newnode->value = value;
    size++;
}
template <typename T> T LinkedList<T>::drop(int index) {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    T value;
    if (index == 0) {
        head = head->next;
        value = tmp->value;
        delete tmp;
        if (index == size - 1) {
            tail = nullptr;
        }
    } else {
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        value = tmp->next->value;
        Node* old = tmp->next;
        tmp->next = old->next;
        delete old;
    }
    if (index == size - 1) {
        tail = nullptr;
    }
    size--;
    return value;
}

template <typename T> T &LinkedList<T>::operator[](unsigned int index) const {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <typename T> unsigned int LinkedList<T>::length() const {
    return size;
}

template <typename T> void LinkedList<T>::print() const {
    Node *tmp = head;
    if (tmp) {
        std::cout << tmp->value;
    }
    for (auto i = tmp->next; i; i = i->next) {
        std::cout << ", " << i->value;
    }
}

template <typename T> LinkedList<T>::~LinkedList() {
    for (auto i = head; i;) {
        head = i->next;
        delete i;
        i = head;
    }
}

#endif // LINKED_LIST_H
