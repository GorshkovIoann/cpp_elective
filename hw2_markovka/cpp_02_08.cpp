/*Даны три стержня, на один из которых нанизаны восемь колец,
причём кольца отличаются размером и лежат меньшее на большем.
Задача состоит в том, чтобы перенести пирамиду из восьми колец
за наименьшее число ходов на другой стержень. За один раз разрешается
переносить только одно кольцо, причём нельзя класть большее кольцо на меньшее.*/

#include <iostream>
#include <vector>
#include <string>

void HanoiTowers(int disksNumber, int fromTower, int toTower)
{

    if (disksNumber != 0)
    {
        int intermediateTower = 6 - fromTower - toTower;
        HanoiTowers(disksNumber - 1, fromTower, intermediateTower);

        std::cout << "Передвиньте диск с башни " << fromTower
                  << " на башню " << toTower << std::endl;

        HanoiTowers(disksNumber - 1, intermediateTower, toTower);
    }
}

int main()
{
    HanoiTowers(3, 1, 3);
}
