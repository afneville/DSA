#include "../inc/list.h"

int main() {
    LinkedList l{};
    for (auto i : {1, 2, 3, 4, 5}) {
        l.prepend(i);
    }
    std::cout << l << '\n';
    return 0;
}
