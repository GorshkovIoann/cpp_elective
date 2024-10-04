#include <iostream>

class A
{
    virtual void test1() {}
};
class B : public A
{
    virtual void test2() {}
};
class C : public A
{
    virtual void test3() {}
};
class D : public B
{
    virtual void test4() {}
};

int main()
{

    A *pA = new D(); // успешно расширили экземпляр D до A
    std::cout << (dynamic_cast<B *>(pA) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<C *>(pA) ? "неудача" : "успех") << std::endl;

    std::cout << (dynamic_cast<C *>(new B()) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<C *>(new A()) ? "успех" : "неудача") << std::endl;
}
