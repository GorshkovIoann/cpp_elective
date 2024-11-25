#include <iostream>
#include <optional>
#include <string>

class Person {
public:
    std::string first_name;
    std::string last_name;

    std::optional<std::string> middle_name;
    std::optional<std::string> address;

    Person(const std::string& first_name_, const std::string& last_name_)
    : first_name(first_name_), last_name(last_name_) {}

    void print_info() const {
        std::cout << "First Name: " << first_name << '\n';
        std::cout << "Last Name: " << last_name << '\n';

        if (middle_name) {
            std::cout << "Middle Name: " << *middle_name << '\n';
        } else {
            std::cout << "Middle Name: not provided\n";
        }

        if (address) {
            std::cout << "Address: " << *address << '\n';
        } else {
            std::cout << "Address: not provided\n\n";
        }
    }
};

int main() {
    Person p1("Yuri", "?????");
    p1.print_info();

    Person p2("Markovka", "?????");
    p2.middle_name = "Mako";
    p2.address = "MIPT";
    p2.print_info();

    return 0;
}