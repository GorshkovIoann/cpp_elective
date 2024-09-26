#include <iostream>
#include <cmath>
#include <vector>
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

    int sum = 1;

    for (int i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            if (i * i == num)
                sum += i;
            else
                sum += i + num / i;
        }
    }

    return sum > num;
}

bool isFriendly(int bigger_num, int smaller_num)
{
    if (bigger_num < 2)
        return false;

    int sum = 1;
    for (int i = 2; i * i <= bigger_num; i++)
    {
        if (bigger_num % i == 0)
        {
            if (bigger_num % i == 0)
            {
                if (i * i == bigger_num)
                    sum += i;
                else
                    sum += i + bigger_num / i;
            }
        }
    }

    return sum == smaller_num;
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
    for (int i = 2; i <= n; i++)
        if (isFriendly(n, i))
            std::cout << i << " ";

    return 0;
}
