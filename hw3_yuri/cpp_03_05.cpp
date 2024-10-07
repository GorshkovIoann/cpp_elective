#include <iostream>

class A
{
public:
    virtual ~A() = default;
};
class B : public A
{
};
class C
{
};
class D : public B
{
};
class F : public B, public C
{
};

int main()
{

    A *pA = new D(); // успешно расширили экземпляр D до A
    std::cout << (dynamic_cast<B *>(pA) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<C *>(pA) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<D *>(pA) ? "успех" : "неудача") << std::endl;

    delete pA;

    F *pf = new F();

    std::cout << (dynamic_cast<C *>(pf) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<B *>(pf) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<A *>(pf) ? "успех" : "неудача") << std::endl;

    std::cout << (dynamic_cast<D *>(pf) ? "успех" : "неудача") << std::endl;

    delete pf;
}
