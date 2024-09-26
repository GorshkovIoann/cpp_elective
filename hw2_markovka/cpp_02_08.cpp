/*Даны три стержня, на один из которых нанизаны восемь колец,
причём кольца отличаются размером и лежат меньшее на большем.
Задача состоит в том, чтобы перенести пирамиду из восьми колец
за наименьшее число ходов на другой стержень. За один раз разрешается
переносить только одно кольцо, причём нельзя класть большее кольцо на меньшее.*/

#include <iostream>
#include <vector>
#include <string>

struct Tower
{
    int towerNumber;
    size_t disksNumber;
    Tower(int t_number, size_t d_number) : towerNumber{t_number}, disksNumber{d_number} {};
};

void HanoiTowers(int disksNumber, Tower &fromTower, Tower &toTower, Tower &intermediateTower)
{

    if (disksNumber != 0)
    {
        HanoiTowers(disksNumber - 1, fromTower, intermediateTower, toTower);

        std::cout << "Передвиньте диск с башни " << fromTower.towerNumber
                  << " на башню " << toTower.towerNumber << std::endl;
        --fromTower.disksNumber;
        ++toTower.disksNumber;

        HanoiTowers(disksNumber - 1, intermediateTower, toTower, fromTower);
    }
}

int main()
{
    Tower tower1 = Tower(1, 3);
    Tower tower2 = Tower(2, 0);
    Tower tower3 = Tower(3, 0);
    HanoiTowers(tower1.disksNumber, tower1, tower3, tower2);
}
