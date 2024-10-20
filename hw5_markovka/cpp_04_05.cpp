#include <iostream>

template <typename T>
auto min(T arg) { return arg; }

template <typename T, typename... Ts>
auto min(T arg, Ts... args)
{
    return arg < min(args...) ? arg : min(args...);
}

int main()
{
    std::cout << min(0, -5, 100, 13, 13, 56, -2) << std::endl;
}
