#include <iostream>
#include <type_traits>


namespace detail {
template <class T>
std::integral_constant<bool, !std::is_union<T>::value> test(int T::*);
// в эту функцию может попасть только обьект типа класс и она вернет единицу 
// для любого класса не обьединения

template <class>
std::false_type test(...);
// 0 для всего остального
}

template <class T>
struct is_class : decltype(detail::test<T>(nullptr)) {};

#include <iostream>

int main() {
  std::cout << is_class<int>::value << std::endl;
  std::cout << is_class<int*>::value << std::endl;
  std::cout << is_class<int&>::value << std::endl;

  std::cout << is_class<std::string>::value << std::endl;
  std::cout << is_class<std::tuple<int, double>>::value << std::endl;

  return 0;
}
