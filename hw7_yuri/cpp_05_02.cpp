#include <cassert>
#include <iostream>
#include <string>

//  ================================================================================================

struct Person {
  int age = 0;
  int height = 0;
  std::string name;
};

//  ================================================================================================

class Builder {
 public:
  virtual ~Builder() = default;

  auto get() const { return m_person; }

  virtual const Builder* age(int age) const = 0;
  virtual const Builder* height(int height) const = 0;
  virtual const Builder* name(std::string name) const = 0;

 protected:
  mutable Person* m_person = nullptr;
};

//  ================================================================================================

struct Builder_Great_Person : public Builder {
  Builder_Great_Person() { m_person = new Person(); }
  const Builder* age(int age) const {
    m_person->age = age;
    return this;
  }
  const Builder* height(int height) const {
    m_person->height = height;
    return this;
  }
  const Builder* name(std::string name) const {
    m_person->name = name;
    return this;
  }
};

//  ================================================================================================

int main() {
  Builder* builder = new Builder_Great_Person();

  Person* p = builder->name("Ivan")->age(26)->height(180)->get();

  std::cout << "Name: " << p->name << ", Age: " << p->age
            << ", Height: " << p->height << std::endl;

  delete p;
  delete builder;
}