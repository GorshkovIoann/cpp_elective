#include <vector>
#include <iostream>

size_t unique(std::vector<int> &vec)
{
    size_t end = 1;
    for (size_t i = 1; i < std::size(vec); ++i)
        if (vec[i] != vec[i - 1])
        {
            vec[end] = vec[i];
            ++end;
        }
    return end;
}

void printVector(const std::vector<int> &vec, int end)
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
    printVector(numbers, numbers.size());

    int newEnd = unique(numbers);

    std::cout << "Стало: ";
    printVector(numbers, newEnd);

    return 0;
}