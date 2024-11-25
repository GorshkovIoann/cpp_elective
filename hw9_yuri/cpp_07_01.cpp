#include <cmath>
#include <iostream>
#include <variant>
#include <utility>

using Sol = std::variant<std::monostate, double, std::pair<double, double>>;

Sol solve(double a, double b, double c) {
    double D = b * b - 4 * a * c;
    
    if (D > 0.0) {
        double sqrt_D = std::sqrt(D);
        double x1 = (-b + sqrt_D) / (2 * a);
        double x2 = (-b - sqrt_D) / (2 * a);
        return std::make_pair(x1, x2);
    } else if (D == 0.0) {
        return -b / (2 * a);
    } else {
        return std::monostate{};
    }
}

void print(const Sol& sol) {
    if (std::holds_alternative<std::monostate>(sol)) {
        std::cout << "Нет решений.\n";
    } else if (std::holds_alternative<double>(sol)) {
        std::cout << "x = " << std::get<double>(sol) << '\n';
    } else {
        auto [x1, x2] = std::get<std::pair<double, double>>(sol);
        std::cout << "x1 = " << x1 << ", x2 = " << x2 << '\n';
    }
}

int main() {
    double a = 1.0, b = -3.0, c = 2.0;
    Sol sol1 = solve(a, b, c);
    print(sol1);
}