#include <iostream>
#include <vector>

void shellSort(std::vector<int> &vec)
{
    for (int gap = vec.size() / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < std::size(vec); i++)
        {
            int temp = vec[i];
            int j = i;

            while (j >= gap && vec[j - gap] > temp)
            {
                vec[j] = vec[j - gap];
                j -= gap;
            }

            vec[j] = temp;
        }
    }
}

void printVector(const std::vector<int> &vec)
{
    for (const auto &num : vec)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> numbers = {-12, 1000, 43, 3, 21, 12, 2, 2, 2, -56};

    std::cout << "Было: ";
    printVector(numbers);

    shellSort(numbers);

    std::cout << "Стало: ";
    printVector(numbers);

    std::cout << "Профит" << std::endl;
    return 0;
}
