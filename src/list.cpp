#include "../inc/list.h"

LinkedList::LinkedList() { head = nullptr; }

void *LinkedList::Node::operator new(std::size_t) {
    return malloc(sizeof(LinkedList::Node));
}

void LinkedList::Node::operator delete(void *ptr, std::size_t) {
    if (ptr)
        free(ptr);
    return;
}

void LinkedList::prepend(int value) {
    Node *tmp = new Node;
    tmp->next = head;
    tmp->value = value;
    head = tmp;
    size++;
}

void LinkedList::print() const {
    Node *tmp = head;
    if (tmp) {
        std::cout << tmp->value;
    }
    for (auto i = tmp->next; i; i = i->next) {
        std::cout << ", " << i->value;
    }
}

LinkedList::~LinkedList() {
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

std::ostream &operator<<(std::ostream &o, const LinkedList &l) {
    l.print();
    return o;
}
