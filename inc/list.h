#include <initializer_list>
#include <iostream>
#include <ostream>

class List {};

class LinkedList : public List {
private:
    class Node {
    public:
        Node *next;
        int value;
        void *operator new(std::size_t);
        void operator delete(void *, std::size_t);
    };
    Node *head;
    int size;

public:
    LinkedList();
    ~LinkedList();
    void prepend(int);
    void print() const;
};
std::ostream& operator<<(std::ostream &o, const LinkedList &l);
class ArrayList : public List {};
