#include "../templates/linked_list.hpp"
// #include <gtest/gtest.h>
#include <iostream>
#include <stdexcept>

int main() {
    LinkedList<int> l;
    l.append(1);
    l.prepend(2);
    l.append(3);
    std::cout << l << '\n';
    LinkedList<double> l2 {1.2, 3.4, 5.6};
    std::cout << l2 << '\n';
    // std::cout << l2.length() << '\n';
    std::cout << lengthOf(l2) << '\n';
    LinkedList<int> l3 {};
    std::cout << lengthOf(l3) << '\n';
    return 0;
}
