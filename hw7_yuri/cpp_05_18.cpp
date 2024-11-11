#include <iostream>

template <typename T>
struct Strategy {
  virtual ~Strategy() = default;

  void test() const { static_cast<const T*>(this)->test_impl(); }
};

struct Fast : public Strategy<Fast> {
  void test_impl() const { std::clog << "Fast::test\n"; }
};

struct Slow : public Strategy<Slow> {
  void test_impl() const { std::clog << "Slow::test\n"; }
};

template <typename T>
class Entity {
 public:
  explicit Entity(const T& strategy) : m_strategy(strategy) {}

  void test() const { m_strategy.test(); }

 private:
  const T& m_strategy;
};

int main() {
  Strategy<Fast>* strategy = new Fast();

  Entity entity(*strategy);

  entity.test();

  delete strategy;
}
