#include <iostream>

__attribute__((constructor))
void before_main() {
    std::cout << "You are a good one" << std::endl;
}

int main() {}