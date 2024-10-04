#include <iostream>
#include <numbers>

class Shape
{
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual ~Shape() = default;
};

// хотя это скорее не многоугольник, а параллелограмм...
class Polygon : public Shape
{
protected:
    double sideA, sideB;

public:
    Polygon(double a, double b) : sideA{a}, sideB{b} {}
};

class Rectangle : public Polygon
{

public:
    Rectangle(double w, double h) : Polygon(w, h) {}

    double area() const override
    {
        return sideA * sideB;
    }

    double perimeter() const override
    {
        return 2 * (sideA + sideB);
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}
};

class Triangle : public Polygon
{
private:
    double sideC;

public:
    Triangle(double a, double b, double c) : Polygon(a, b), sideC{c} {}

    double perimeter() const override
    {
        return sideA + sideB + sideC;
    }

    double area() const override
    {
        double p = perimeter() / 2;
        return sqrt(p * (p - sideA) * (p - sideB) * (p - sideC));
    }
};

class Ellipse : public Shape
{
private:
    double MajorAxis, MinorAxis;

public:
    Ellipse(double a, double b) : MajorAxis(a), MinorAxis(b) {}

    double area() const override
    {
        return std::numbers::pi * MajorAxis * MinorAxis;
    }

    double perimeter() const override
    {
        return 4 * (std::numbers::pi * (MajorAxis * MinorAxis) + (MajorAxis - MinorAxis)) / (MajorAxis + MinorAxis);
    }
};

class Circle : public Ellipse
{
public:
    Circle(double radius) : Ellipse(radius, radius) {}
};

int main()
{
    Rectangle rect(4, 5);
    Square sqr(3);
    Triangle tri(3, 4, 5);
    Circle cir(2);
    Ellipse ell(3, 4);

    Shape *shapes[] = {&rect, &sqr, &tri, &cir, &ell};

    for (auto shape : shapes)
    {
        std::cout << "Площадь: " << shape->area()
                  << ", Периметр: " << shape->perimeter()
                  << std::endl;
    }

    return 0;
}
