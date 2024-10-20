#include <iostream>

template <typename T>
auto sum(T t)
{
    return 0;
}
template <>
auto sum<int>(int t)
{
    return t;
}

template <typename T, typename... Ts>
auto sum(T t, Ts... ts)
{
    return sum(t) + sum(ts...);
}

int main()
{
    std::cout << sum(1, 2, 3, 4.5, true, 'A') << std::endl;
    return 0;
}
