#include "list.hpp"
#include <initializer_list>
#include <stdexcept>
#include <type_traits>

#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
// Singly Linked List Template

template <typename T> class SinglyLinkedList : public virtual List<T> {
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
    void swap(SinglyLinkedList<T> &, SinglyLinkedList<T> &);

public:
    SinglyLinkedList();
    SinglyLinkedList(std::initializer_list<T>);
    SinglyLinkedList(const SinglyLinkedList<T> &);
    SinglyLinkedList(SinglyLinkedList<T> &&);
    SinglyLinkedList<T> &operator=(SinglyLinkedList<T>);
    ~SinglyLinkedList();
    unsigned int length() const override;
    void append(T) override;
    void prepend(T) override;
    void insert(int, T) override;
    T drop(int, bool = 1) override;
    T &operator[](unsigned int) const override;

    template <typename ElementType> struct Iterator {
        using iterator_category = std::forward_iterator_tag;
        using difference_type = std::ptrdiff_t;
        using value_type = ElementType;
        using pointer = ElementType *;
        using reference = ElementType &;

        Iterator(Node *node) : node(node) {}

        reference operator*() const { return node->value; }
        pointer operator->() { return &node->value; }
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
};

// Default Constructor
template <typename T> SinglyLinkedList<T>::SinglyLinkedList() {}

// Initialiser List Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(std::initializer_list<T> l) {
    for (auto i : l) {
        append(i);
    }
}

// Copy Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T> &source) {
    for (int i{0}; i < source.size; i++) {
        this->append(source[i]);
    }
}

// Move Constructor
template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T> &&source) {
    std::swap(this->size, source.size);
    std::swap(this->head, source.head);
    std::swap(this->tail, source.tail);
}

// Copy Assignment
template <typename T>
SinglyLinkedList<T> &
SinglyLinkedList<T>::operator=(SinglyLinkedList<T> source) {
    this->swap(*this, source);
    return *this;
}

template <typename T>
void SinglyLinkedList<T>::swap(SinglyLinkedList<T> &a, SinglyLinkedList<T> &b) {
    std::swap(a.size, b.size);
    std::swap(a.head, b.head);
    std::swap(a.tail, b.tail);
}

template <typename T>
void *SinglyLinkedList<T>::Node::operator new(std::size_t) {
    return malloc(sizeof(SinglyLinkedList::Node));
}

template <typename T>
void SinglyLinkedList<T>::Node::operator delete(void *ptr, std::size_t) {
    if (ptr)
        free(ptr);
    return;
}
template <typename T> void SinglyLinkedList<T>::append(T value) {
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

template <typename T> void SinglyLinkedList<T>::prepend(T value) {
    Node *tmp = new Node;
    tmp->next = head;
    tmp->value = value;
    head = tmp;
    if (!tail)
        tail = tmp;
    size++;
}
template <typename T> void SinglyLinkedList<T>::insert(int index, T value) {
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
template <typename T>
T SinglyLinkedList<T>::drop(int index, bool bound_checking) {
    if (bound_checking) {
        if (index >= size) {
            throw std::out_of_range{"List Index Out of Range"};
        }
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
        Node *old = tmp->next;
        tmp->next = old->next;
        delete old;
    }
    if (index == size - 1) {
        tail = nullptr;
    }
    size--;
    return value;
}

template <typename T>
T &SinglyLinkedList<T>::operator[](unsigned int index) const {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    }
    Node *tmp = head;
    for (int i = 0; i < index; i++)
        tmp = tmp->next;
    return tmp->value;
}

template <typename T> unsigned int SinglyLinkedList<T>::length() const {
    return size;
}

template <typename T> SinglyLinkedList<T>::~SinglyLinkedList() {
    for (auto i = head; i;) {
        head = i->next;
        delete i;
        i = head;
    }
}

#endif // SINGLY_LINKED_LIST_H
