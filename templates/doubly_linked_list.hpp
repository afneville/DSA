#include "list.hpp"
#include <cstddef>
#include <initializer_list>
#include <iostream>
#include <iterator>
#include <ostream>
#include <stdexcept>
#include <type_traits>

#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

template <typename T> class DoublyLinkedList : public virtual List<T> {
protected:
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
    int size_{0};
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
    T &operator[](size_t) override;
    const T &operator[](size_t) const override;

    template <typename ElementType> struct Iterator {
        using iterator_category = std::random_access_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = ElementType;
        using pointer = ElementType *;
        using reference = ElementType &;

        Iterator(Node *node, Node *tail) : node(node), tail(tail) {}

        reference operator*() const { return node->value; }
        pointer operator->() { return &node->value; }
        Iterator &operator--() {
            if (!node) {
                node = tail;
            } else {
                node = node->prev;
            }
            return *this;
        }

        Iterator<ElementType> operator--(int) {
            Iterator tmp = *this;
            --(*this);
            return tmp;
        }

        Iterator<ElementType> &operator++() {
            node = node->next;
            return *this;
        }

        Iterator<ElementType> operator++(int) {
            Iterator tmp = *this;
            ++(*this);
            return tmp;
        }

        Iterator<ElementType> &operator+=(difference_type n) {
            int i = 0;
            if(!node) {
                node = tail;
                i = 1;
            }
            for (i; i < n; i++)
                node = node->next;
            return *this;
        }

        Iterator<ElementType> &operator-=(difference_type n) {
            int i = 0;
            if(!node) {
                node = tail;
                i = 1;
            }
            for (i; i < n; i++)
                node = node->prev;
            return *this;
        }

        Iterator<ElementType> operator+(difference_type n) {
            Iterator<ElementType> tmp{node, tail};
            tmp += n;
            return tmp;
        }

        Iterator<ElementType> operator-(difference_type n) {
            Iterator<ElementType> tmp{node, tail};
            tmp -= n;
            return tmp;
        }

        ElementType &operator[](size_t n) {
            Node * tmp = node;
            for (auto i = 0; i < n; i++)
                tmp = tmp->next;
            return tmp->value;
        }

        friend bool operator==(const Iterator &a, const Iterator &b) {
            return a.node == b.node;
        };

        friend bool operator!=(const Iterator &a, const Iterator &b) {
            return a.node != b.node;
        };

    private:
        Node *node;
        Node *tail;
    };

    Iterator<T> begin() { return Iterator<T>{head, tail}; }

    Iterator<T> end() { return Iterator<T>{nullptr, tail}; }

    Iterator<const T> cbegin() { return Iterator<const T>{head, tail}; }

    Iterator<const T> cend() { return Iterator<const T>{nullptr, tail}; }

    std::reverse_iterator<Iterator<T>> rbegin() {
        revbegin.prev = tail;
        return std::make_reverse_iterator(Iterator<T>{&revbegin, tail});
    }

    std::reverse_iterator<Iterator<T>> rend() {
        return std::make_reverse_iterator(Iterator<T>{head, tail});
    }

    std::reverse_iterator<Iterator<const T>> crbegin() {
        revbegin.prev = tail;
        return std::make_reverse_iterator(Iterator<T>{&revbegin, tail});
    }

    std::reverse_iterator<Iterator<const T>> crend() {
        return std::make_reverse_iterator(Iterator<const T>{head, tail});
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
    for (int i{0}; i < source.size_; i++) {
        this->append(source[i]);
    }
}

// Move Constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList<T> &&source) {
    std::swap(this->size_, source.size_);
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
    std::swap(a.size_, b.size_);
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
    size_++;
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
    size_++;
}

template <typename T> void DoublyLinkedList<T>::insert(int index, T value) {
    if (index > size_) {
        throw std::out_of_range{"List Index Out of Range"};
        return;
    }
    if (index == 0) {
        prepend(value);
        return;
    }
    if (index == size_) {
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
    size_++;
}

template <typename T> T DoublyLinkedList<T>::drop(int index, bool bound_check) {
    if (bound_check) {
        if (index >= size_) {
            throw std::out_of_range{"List Index Out of Range"};
        }
    }
    Node *tmp = head;
    T value;
    if (index == 0) {
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        value = tmp->value;
        delete tmp;
    } else {
        for (int i = 0; i < index - 1; i++)
            tmp = tmp->next;
        Node *old = tmp->next;
        value = old->value;
        tmp->next = old->next;
        if (old->next) {
            old->next->prev = tmp;
        } else {
            tail = tmp;
        }
        delete old;
    }
    size_--;
    return value;
}

template <typename T> T &DoublyLinkedList<T>::operator[](size_t index) {
    if (index >= size_) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <typename T>
const T &DoublyLinkedList<T>::operator[](size_t index) const {
    if (index >= size_) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <typename T> unsigned int DoublyLinkedList<T>::length() const {
    return size_;
}

template <typename T> DoublyLinkedList<T>::~DoublyLinkedList() {
    for (auto i = head; i;) {
        head = i->next;
        delete i;
        i = head;
    }
}

#endif // DOUBLY_LINKED_LIST_H
