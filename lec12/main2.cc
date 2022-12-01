#include <iostream>
#include <limits>

int main() {
    unsigned int x = std::numeric_limits<unsigned int>::max();
    int z = static_cast<int>(x);
    std::cout << z << "\n";
    int y = std::numeric_limits<int>::max();
    unsigned int u = static_cast<unsigned int>(y);
    std::cout << u << "\n";
}
