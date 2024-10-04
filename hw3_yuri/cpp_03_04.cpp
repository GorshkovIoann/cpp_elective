#include <iostream>

class Grandma
{
public:
    virtual void foo() = 0;
};

class Grandpa
{
public:
    virtual void foo() = 0;
};

class Mom : public Grandpa
{
public:
    virtual void fooGrandpa() = 0;

    void foo() override final
    {
        fooGrandpa();
    }
};

class Dad : public Grandma
{
public:
    virtual void fooGrandma() = 0;

    void foo() override final
    {
        fooGrandma();
    }
};

class Me : public Mom, public Dad
{
public:
    void fooGrandma() override final
    {
        std::cout << "Похож на бабушку" << std::endl;
    }

    void fooGrandpa() override final
    {
        std::cout << "Похож на дедушку" << std::endl;
    }
};

int main()
{
    Me i;

    Grandma *m = &i;
    m->foo(); 

    Grandpa *p = &i;
    p->foo();

    return 0;
}
