#include <iostream>
#include <sstream>
#include <stdexcept>
#include <array>
#include <cstdint>

class IPv4
{
private:
    std::array<int, 4> parts;

public:
    IPv4(int part1, int part2, int part3, int part4)
    {
        parts[0] = part1;
        parts[1] = part2;
        parts[2] = part3;
        parts[3] = part4;
    }

    friend std::ostream &operator<<(std::ostream &os, const IPv4 &ipv4)
    {
        os << ipv4.parts[0] << "." << ipv4.parts[1] << "."
           << ipv4.parts[2] << "." << ipv4.parts[3];
        return os;
    }

    friend std::istream &operator>>(std::istream &is, IPv4 &ipv4)
    {
        char d1, d2, d3;
        int b1, b2, b3, b4;
        is >> b1 >> d1 >> b2 >> d2 >> b3 >> d3 >> b4;
        if (d1 == '.' && d2 == '.' && d3 == '.')
            ipv4 = IPv4(b1, b2, b3, b4);
        else
            is.setstate(std::ios_base::failbit);
        return is;
    }

    IPv4 &operator++()
    {
        for (int i = 3; i >= 0; --i)
        {
            if (++parts[i] < 256)
            {
                return *this;
            }
            parts[i] = 0;
        }
        throw std::overflow_error("IPv4 address overflow");
    }

    IPv4 operator++(int)
    {
        IPv4 temp(*this);
        ++(*this);
        return temp;
    }

    IPv4 &operator--()
    {
        for (int i = 3; i >= 0; --i)
        {
            if (--parts[i] >= 0)
            {
                return *this;
            }
            parts[i] = 255;
        }
        throw std::underflow_error("IPv4 address underflow");
    }

    IPv4 operator--(int)
    {
        IPv4 temp(*this);
        --(*this);
        return temp;
    }

    friend bool operator<(const IPv4 &lhs, const IPv4 &rhs)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (lhs.parts[i] != rhs.parts[i])
            {
                return lhs.parts[i] < rhs.parts[i];
            }
        }
        return false;
    }
};

int main()
{
    IPv4 start(0, 0, 0, 0), end(255, 255, 255, 255);

    std::cout << "Перебор всех возможных IPv4 адресов:" << std::endl;

    for (IPv4 addr = start; addr < end; ++addr)
        std::cout << addr << std::endl;
}
