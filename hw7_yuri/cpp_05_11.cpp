#include <iostream>
#include <string>

//  ================================================================================================

struct Entity {
  virtual ~Entity() = default;

  virtual void test() const = 0;
};

void Entity::test() const { std::clog << "Entity::test\n"; }

//  ================================================================================================

struct Client : public Entity {
  void test() const override { std::clog << "Client::test\n"; }
};
struct Server : public Entity {
  void test() const override { std::clog << "Server::test\n"; }
};

//  ================================================================================================

class Decorator : public Entity {
 public:
  explicit Decorator(Entity& entity) : m_entity(entity) {}

  virtual void test() const = 0;
    

 protected:
  Entity& m_entity;
};

void Decorator::test() const{
  std::clog << "DecoratedBaseMethod::";
    Entity::test();
}

//  ================================================================================================

struct Decorated_Entity : public Decorator {
  explicit Decorated_Entity(Entity& entity) : Decorator(entity) {}

  //  ------------------------------------------------------------------------------------------------

  void test() const override {
    std::clog << "Decorated::Entity::";
    m_entity.test();
  }
};

//  ================================================================================================

int main() {
  Entity* entity_1 = new Client();

  Entity* entity_2 = new Decorated_Entity(*entity_1);

  entity_1->test();
  entity_2->test();

  delete entity_1;
  delete entity_2;
}