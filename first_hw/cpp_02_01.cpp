#include <iostream>
#include <cctype>
#include <string>

void classOfSymbol(char symbol)
{
    switch (symbol)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        std::cout << "молодец, ввел число\n"
                  << std::endl;
        break;

    case '+':
    case '-':
    case '*':
    case '/':
        std::cout << "отлично, ты ввел арифметический оператор\n"
                  << std::endl;
        break;

    case '(':
    case ')':
        std::cout << "хм, скобочка...неплохо\n"
                  << std::endl;
        break;

    default:
        std::cout << "дурашка, ты ввел что то странное, попробуйеще разок\n"
                  << std::endl;
    }
}

int main()
{
    char input;

    std::cout << "пожалуйста, введи цифру, арифметический оператор или скобочку, \
        если хочешь остановитьcя, введи 'e'\n"
              << std::endl;

    while (std::cin >> input)
    {
        if (input == 'e')
        {

            break;
        }

        classOfSymbol(input);

        std::cout << "пожалуйста, введи цифру, арифметический оператор или скобочку, \
        если хочешь остановитьcя, введи 'e'"
                  << std::endl;
    }
    return 0;
}
