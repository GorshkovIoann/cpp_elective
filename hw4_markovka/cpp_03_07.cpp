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
};

int main()
{
    IPv4 addr1(12, 18, 1, 1);
    std::cout << "Адрес 1: " << addr1 << "\nВведите адрес" << std::endl;

    IPv4 addr2(2, 3, 4, 5);
    std::cin >> addr2;
    std::cout << "Введенный адрес: " << addr2 << std::endl;

    return 0;
}
