#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>

// Linked List Template

template <typename T> class LinkedList {
private:
    class Node {
    public:
        Node *next;
        T value;
        void *operator new(std::size_t);
        void operator delete(void *, std::size_t);
    };
    Node *head;
    Node *tail;
    int size{0};

public:
    LinkedList();
    LinkedList(std::initializer_list<T>);
    ~LinkedList();
    void print() const;
    void append(T);
    void prepend(T);
    void insert(int, T);
    T &operator[](unsigned int);
};

template <typename T> LinkedList<T>::LinkedList() {
    head = nullptr;
    tail = nullptr;
}

template <typename T> LinkedList<T>::LinkedList(std::initializer_list<T> l) {
    head = nullptr;
    tail = nullptr;
    for (auto i : l) {
        append(i);
    }
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
template <typename T> void LinkedList<T>::insert(int index, T value) {}

template <typename T> T &LinkedList<T>::operator[](unsigned int index) {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    } else {
        Node *tmp = head;
        for (int i = 0; i < index; i++)
            tmp = tmp->next;
        return tmp->value;
    }
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
    Node *tmp;
    if (head) {
        tmp = head->next;
        delete head;
    }
    for (auto i = tmp; i; i = i->next) {
        tmp = i->next;
        delete i;
        i = tmp;
    }
}

template <typename T>
std::ostream &operator<<(std::ostream &o, const LinkedList<T> &l) {
    l.print();
    return o;
}
