#include <iostream>
#include <type_traits>

// украдено с cpp resference
template <typename T>
struct decay {
 private:
  using U = typename std::remove_reference<T>::type;
  // удалили ссылку

 public:
  using type = std::conditional_t<
      std::is_array_v<U>, std::add_pointer_t<std::remove_extent_t<U>>,
      std::conditional_t<std::is_function_v<U>, std::add_pointer_t<U>,
                         std::remove_cv_t<U>>>;
};

template <typename T>
using decay_t = typename decay<T>::type;

int main() {
  std::cout << std::is_same_v<int, decay_t<const int&>> << std::endl;
  std::cout << std::is_same_v<int*, decay_t<int[]>> << std::endl;
  std::cout << std::is_same_v<void (*)(), decay_t<void()>> << std::endl;

  int arr[5];
  std::cout << std::is_same_v<decay_t<decltype(arr)>, int*> << std::endl;
}
