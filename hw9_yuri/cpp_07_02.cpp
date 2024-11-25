#include <iostream>
#include <variant>

struct Pt {
    double x, y;
    Pt(double x_, double y_) : x(x_), y(y_) {}
    friend std::ostream& operator<<(std::ostream& os, const Pt& p) {
        return os << "(" << p.x << ", " << p.y << ")";
    }
};

class Ln {
public:
    double a, b, c;
    Ln(double a_, double b_, double c_) : a(a_), b(b_), c(c_) {} //ax + by + c
};

struct InfSol {};

using Res = std::variant<std::monostate, Pt, InfSol>;

Res intersect(const Ln& l1, const Ln& l2) {
    double det = l1.a * l2.b - l2.a * l1.b;
    if (det != 0.0) {
        double x = (l2.c * l1.b - l1.c * l2.b) / det;
        double y = (l1.c * l2.a - l2.c * l1.a) / det;
        return Pt(x, y);
    } else if (l1.a * l2.c == l2.a * l1.c && l1.b * l2.c == l2.b * l1.c) {
        return InfSol{};
    } else {
        return std::monostate{};
    }
}

void print(const Res& res) {
    if (std::holds_alternative<std::monostate>(res)) {
        std::cout << "нет решений.\n";
    } else if (std::holds_alternative<Pt>(res)) {
        std::cout << std::get<Pt>(res) << '\n';
    } else if (std::holds_alternative<InfSol>(res)) {
        std::cout << "линии совпали \n";
    }
}

int main() {
    Ln l1(1, -1, -1);
    Ln l2(1, 1, -3);
    Ln l3(2, -2, -2);

    Res r1 = intersect(l1, l2);
    print(r1);

    Res r2 = intersect(l1, l3);
    print(r2);

    Ln l4(2, -2, -2);
    Res r3 = intersect(l3, l4);
    print(r3);

}