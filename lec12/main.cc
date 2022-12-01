#include <iostream>

int main() {
    int a[] = {4, 3, 3, 5};
    int size = sizeof(a) / sizeof(a[0]);
    int i = 0;
    while (i < size) {
        std::cout << *(a+i) << "\n";
        ++i;
    }
    return 0;
}
