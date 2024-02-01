#include <initializer_list>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <type_traits>

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
    T &operator[](unsigned int) const;
};

template <typename T> unsigned int lengthOf(LinkedList<T> &);

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
    // std::swap(this->size, source.size);
    // std::swap(this->head, source.head);
    // std::swap(this->tail, source.tail);
    this->size = source.size;
    this->head = source.head;
    this->tail = source.tail;
    source.head = nullptr;
    source.tail = nullptr;
    source.size = 0;
}

// Copy Assignment
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> source) {
    this->swap(*this, source);
    return *this;
}

/* Move Assignment
 * Implementation not needed if using copy-swap
template <typename T>
LinkedList<T> &LinkedList<T>::operator=(LinkedList<T> &&source) {
    this->head = source.head;
    this->tail = source.tail;
    source.head = nullptr;
    source.tail = nullptr;
    source.size = 0;
    return *this;
} */

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
template <typename T> void LinkedList<T>::insert(int index, T value) {}

template <typename T> T &LinkedList<T>::operator[](unsigned int index) const {
    if (index >= size) {
        throw std::out_of_range{"List Index Out of Range"};
    } else {
        Node *tmp = head;
        for (int i = 0; i < index; i++)
            tmp = tmp->next;
        return tmp->value;
    }
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

template <typename T>
std::ostream &operator<<(std::ostream &o, const LinkedList<T> &l) {
    l.print();
    return o;
}

template <typename T> unsigned int lengthOf(LinkedList<T> &l) {
    return l.length();
}