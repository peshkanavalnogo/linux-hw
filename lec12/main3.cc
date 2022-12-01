#include <iostream>
#include <bitset>


int main() {
    int x = 12345;
    char* y = reinterpret_cast<char*>(&x);
    for (int i = 0; i < 4; ++i) {
        std::cout << std::bitset<sizeof(*y)*8> (*y) << "\n";
        ++y;
    }
    return 0;
}
