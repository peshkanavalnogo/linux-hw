#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <string>

int main() {
    char** first = environ;
    while (*first) {
        std::string s(*first);
        if (s.find("L") < s.length()) { 
            std::cout << s << '\n';
        }
        ++first;
    }

    return 0;
}
