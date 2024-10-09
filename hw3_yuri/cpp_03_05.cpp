#include <iostream>

class A
{
public:
    virtual ~A() = default;
};
class B : public A
{
public:
    virtual ~B() = default;
};
class C
{
public:
    virtual ~C() = default;
};
class D : public B
{
public:
    virtual ~D() = default;
};
class F : public B, public C
{
public:
    virtual ~F() = default;
};

int main()
{

    A *pA = new D();                                                         // успешно расширили экземпляр D до A
    std::cout << (dynamic_cast<B *>(pA) ? "успех" : "неудача") << std::endl; // сужающее успешно

    std::cout << (dynamic_cast<C *>(pA) ? "успех" : "неудача") << std::endl; // к другому классу очевидно сузить не получится

    std::cout << (dynamic_cast<D *>(pA) ? "успех" : "неудача") << std::endl; // еще сильнее сузающщее успешно

    delete pA;

    B *pf = new F();

    std::cout << (dynamic_cast<C *>(pf) ? "успех" : "неудача") << std::endl; // теперь железобетонно удачный side cast

    std::cout << (dynamic_cast<F *>(pf) ? "успех" : "неудача") << std::endl; // просто еще сузающее показал

    std::cout << (dynamic_cast<A *>(pf) ? "успех" : "неудача") << std::endl; // к самому базовому классу мы тоже спокойно кастуем

    std::cout << (dynamic_cast<D *>(pf) ? "успех" : "неудача") << std::endl; // а вот к классу, от которого не наследуемся, нет

    delete pf;
}
