#include <iostream>
#include <vector>

void selectionSort(std::vector<int> &vec)
{

    for (int i = 0; i < vec.size() - 1; ++i)
    {
        int minIndex = i;

        for (int j = i + 1; j < vec.size(); ++j)
        {
            if (vec[j] < vec[minIndex])
            {
                minIndex = j;
            }
        }

        std::swap(vec[i], vec[minIndex]);
    }
}

void printVector(const std::vector<int> &vec)
{
    for (auto num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = {64, 34, 25, 12, 22, 11, 90};

    std::cout << "Было: ";
    printVector(numbers);

    selectionSort(numbers);

    std::cout << "Стало: ";
    printVector(numbers);

    std::cout << "Профит" << std::endl;
    return 0;
}
