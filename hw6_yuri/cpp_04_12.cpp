#include <iostream>
#include <type_traits>

template <typename T>
struct Add_Const {
  using type = const T;
};

template <typename T>
using add_const = typename Add_Const<T>::type;

template <typename T>
struct Remove_Const {
  using type = T;
};

template <typename T>
struct Remove_Const<const T> {
  using type = T;
};

template <typename T>
using remove_const = typename Remove_Const<T>::type;

int main() {
  std::cout << std::is_same_v<int, add_const<int>> << std::endl;
  std::cout << std::is_same_v<const int, add_const<int>> << std::endl;

  std::cout
      << std::is_same_v<const int, remove_const<const int>> << std::endl;
  std::cout << std::is_same_v<int, remove_const<int>> << std::endl;
  std::cout << std::is_same_v<int, remove_const<const int>> << std::endl;

  return 0;
}
