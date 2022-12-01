#include <iostream>
#define rp reinterpret_cast<int*>

int main() {
    int x = 11;
    long y = 12;
    double z = 0.0;
    std::cout << &x << "\n" << &y << "\n" << &z << "\n";
    std::cout << &x-&x << "\n" << rp(&y)-&x << "\n" << rp(&z)-&x << "\n";
} 
