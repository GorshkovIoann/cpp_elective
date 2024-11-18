#include <iostream>

struct Global {
    Global() {
        std::cout << "Who is a good boy?" << std::endl;
    }
} global;

int main() {}