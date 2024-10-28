#include <iostream>
#include <numbers>
#include <vector>

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
    std::vector<double> sides;

public:
    Polygon(std::vector<double> s) : sides{s} {}
};

class Rectangle : public Polygon
{

public:
    Rectangle(double w, double h) : Polygon({w, h}) {}

    double area() const override
    {
        return sides[0] * sides[1];
    }

    double perimeter() const override
    {
        return 2 * (sides[0] + sides[1]);
    }
};

class Square : public Rectangle
{
public:
    Square(double side) : Rectangle(side, side) {}
};

class Triangle : public Polygon
{
public:
    Triangle(double a, double b, double c) : Polygon({a, b, c}) {}

    double perimeter() const override
    {
        return sides[0] + sides[1] + sides[2];
    }

    double area() const override
    {
        double p = perimeter() / 2;
 //       return sqrt(p * (p - sides[0]) * (p - sides[1]) * (p - sides[2]));
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
