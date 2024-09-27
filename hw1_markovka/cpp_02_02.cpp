#include <iostream>
#include <cmath>
#include <vector>

int _findDivisors(int n)
{
    int sum = 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                sum += i;
            else
                sum += i + n / i;
        }
    }
    return sum;
}

bool isArmstrong(int num)
{
    int originalNum = num;
    int digitCount = 0;
    int temp = num;

    while (temp != 0)
    {
        digitCount++;
        temp /= 10;
    }

    temp = num;
    int sum = 0;

    while (temp != 0)
    {
        int digit = temp % 10;
        sum += pow(digit, digitCount);
        temp /= 10;
    }

    return sum == originalNum;
}

void fibonacci(int n)
{
    if (n <= 1)
    {
        return;
    }

    long prev = 0, curr = 1;
    while (curr < n)
    {
        std::cout << curr << " ";

        long next = prev + curr;
        prev = curr;
        curr = next;
    }

    return;
}

bool isExcess(int num)
{
    if (num < 2)
        return false;

    int sum = _findDivisors(num);

    return sum > num;
}

bool isFriendly(int bigger_num, int smaller_num)
{
    if (bigger_num < 2)
        return false;

    int bigger_num_divisors_sum = _findDivisors(bigger_num);
    int smaller_num_divisors_sum = _findDivisors(smaller_num);

    return bigger_num_divisors_sum == smaller_num && smaller_num_divisors_sum == bigger_num;
}

int main()
{
    int n;
    std::cout << "Введите N: ";
    std::cin >> n;

    std::cout << "\n\nЧисла Армстронга до " << n << ":" << std::endl;
    for (int i = 1; i <= n; i++)
        if (isArmstrong(i))
            std::cout << i << " ";

    std::cout << "\n\nЧисла Фибоначчи до " << n << ":" << std::endl;
    fibonacci(n);

    std::cout << "\n\nИзбыточные числа до " << n << ":" << std::endl;
    for (int i = 2; i <= n; i++)
        if (isExcess(i))
            std::cout << i << " ";

    std::cout << "\n\nДружественные числа до " << n << ":" << std::endl;
    for (int i = 3; i <= n; i++)
    {
        for (int j = 2; j < i; ++j)
            if (isFriendly(i, j))
                std::cout << i << "," << j << "; ";
    }

    return 0;
}
