#include <iostream>
#include <vector>

void heapify(std::vector<int> &vec, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && vec[l] > vec[largest])
        largest = l;

    if (r < n && vec[r] > vec[largest])
        largest = r;

    if (largest != i)
    {
        std::swap(vec[i], vec[largest]);

        heapify(vec, n, largest);
    }
}

void heapSort(std::vector<int> &vec)
{
    for (int i = vec.size() / 2 - 1; i >= 0; i--)
        heapify(vec, vec.size(), i);

    for (int i = vec.size() - 1; i > 0; i--)
    {
        std::swap(vec[0], vec[i]);

        heapify(vec, i, 0);
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
    std::vector<int> numbers = {-12, 1000, 43, 3, 21, 12, 2, 2, 2, -56};

    std::cout << "Было: ";
    printVector(numbers);

    heapSort(numbers);

    std::cout << "Стало: ";
    printVector(numbers);

    std::cout << "Профит" << std::endl;
    return 0;
}