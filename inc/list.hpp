#include <initializer_list>
#include <iostream>
#include <ostream>

class List {};

template <typename T> class LinkedList : public List {
private:
    class Node {
    public:
        Node *next;
        T value;
        void *operator new(std::size_t);
        void operator delete(void *, std::size_t);
    };
    Node *head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void prepend(T);
    void print() const;
};

template <typename T>
std::ostream &operator<<(std::ostream &o, const LinkedList<T> &l);

class ArrayList : public List {};

template<typename T>
LinkedList<T>::LinkedList() { head = nullptr; }

template<typename T>
void *LinkedList<T>::Node::operator new(std::size_t) {
    return malloc(sizeof(LinkedList::Node));
}

template<typename T>
void LinkedList<T>::Node::operator delete(void *ptr, std::size_t) {
    if (ptr)
        free(ptr);
    return;
}

template<typename T>
void LinkedList<T>::prepend(T value) {
    Node *tmp = new Node;
    tmp->next = head;
    tmp->value = value;
    head = tmp;
    size++;
}

template<typename T>
void LinkedList<T>::print() const {
    Node *tmp = head;
    if (tmp) {
        std::cout << tmp->value;
    }
    for (auto i = tmp->next; i; i = i->next) {
        std::cout << ", " << i->value;
    }
}

template<typename T>
LinkedList<T>::~LinkedList() {
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

template<typename T>
std::ostream &operator<<(std::ostream &o, const LinkedList<T> &l) {
    l.print();
    return o;
}
