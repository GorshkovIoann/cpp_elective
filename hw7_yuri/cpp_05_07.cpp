#include <iostream>

//  ================================================================================================

struct Client {
  void test() const { std::clog << "Client::test\n"; }
};

//  ================================================================================================

struct Entity {
  virtual ~Entity() = default;

  virtual void test() const = 0;
};

//  ================================================================================================

class Adapter : public Entity, private Client {
 public:
  void test() const override { Client::test(); }
};

//  ================================================================================================

int main() {
  Client client;

  Entity* entity = new Adapter();

  entity->test();

  delete entity;
}