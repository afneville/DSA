#include "../templates/singly_linked_list.hpp"
#include <iostream>

int main() {
    SinglyLinkedList<int> l {1,2,3,4,5,6,7,8};
    for (auto it = l.begin(), end = l.end(); it != end; ++it) { 
        const auto i = *it;
        std::cout << i << "\n";
    }
    return 0;
}
