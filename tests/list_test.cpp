#include "../inc/list.hpp"

int main() {
    LinkedList<int> l {};
    for (auto i : {1,2,3,4,5})
        l.prepend(i);
    std::cout << l << '\n';
    return 0;
}
