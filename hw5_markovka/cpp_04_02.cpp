#include <vector>
#include <iostream>

template <typename T>
size_t unique(std::vector<T> &vec)
{
    size_t end = 1;
    for (size_t i = 1; i < std::size(vec); ++i)
        if (vec[i] != vec[i - 1])
            vec[end++] = vec[i];
    return end;
}

template <typename T>
void printVector(const std::vector<T> &vec, const int end)
{
    for (int i = 0; i < end; ++i)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = {1, 2, 2, 3, 4, 4, 4, 4, 4, 4, 5, 6, 6, 7};

    std::cout << "Было: ";
    printVector(numbers, std::size(numbers));

    int newEnd = unique(numbers);

    std::cout << "Стало: ";
    printVector(numbers, newEnd);

    return 0;
}