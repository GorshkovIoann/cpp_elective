#include <iostream>
#include <set>

std::set<int> findPrimeNums(int n)
{
    std::set<int> primeNums;

    for (int i = 2; i * i <= n; ++i)
    {

        while (n % i == 0)
        {
            primeNums.insert(i);
            n /= i;
        }
    }

    if (n > 1)
        primeNums.insert(n);

    return primeNums;
}

int main()
{
    int num;
    std::cout << "дайте чиселко: ";
    std::cin >> num;

    std::set<int> primeNums = findPrimeNums(num);

    std::cout << "простые делители " << num << ": ";
    for (auto &num : primeNums)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
