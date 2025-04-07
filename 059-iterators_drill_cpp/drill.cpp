#include <iostream>
#include <vector>
#include <list>
#include <array>
#include <iterator>
#include <cstdlib>

template <typename Container>
void print(const Container& container, const std::string& name) {
    std::cout << name << ": {";
    for (auto it = container.begin(); it != container.end(); ++it) {
        std::cout << *it;
        if (std::next(it) != container.end()) {
            std::cout << ", ";
        }
    }
    std::cout << "}\n";
}

// Generic increment function
template <typename Iter>
void increase(Iter begin, Iter end, int increment) {
    while (begin != end) {
        *begin += increment;
        ++begin;
    }
}

// Copy function
template <typename Iter1, typename Iter2>
Iter2 copy2(Iter1 f1, Iter1 e1, Iter2 f2) {
    while (f1 != e1) {
        *f2 = *f1;
        ++f1;
        ++f2;
    }
    return f2;
}

int main() {
    std::array<int, 10> arr = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    std::vector<int> vec(arr.begin(), arr.end());
    std::list<int> lst(arr.begin(), arr.end());

    increase(arr.begin(), arr.end(), 2);
    increase(vec.begin(), vec.end(), 3);
    increase(lst.begin(), lst.end(), 5);

    copy2(arr.begin(), arr.end(), vec.begin());
    copy2(lst.begin(), lst.end(), arr.begin());

    print(arr, "array");
    print(vec, "vector");
    print(lst, "list");

    return EXIT_SUCCESS;
}
