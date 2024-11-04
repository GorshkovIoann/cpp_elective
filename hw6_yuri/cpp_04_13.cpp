#include <type_traits>
#include <iostream>


//украдено с cpp resference
template<typename T>
struct decay {
    private:
        using U = typename std::remove_reference<T>::type;
        //удалили ссылку
    
    public:
        using type = typename std::conditional<       //условия
            std::is_array<U>::value,             //если массив
            typename std::add_pointer<typename std::remove_extent<U>::type>::type,
                                                 // добавили указательна член и удалили размер
            typename std::conditional<
                std::is_function<U>::value,      // если функция
                typename std::add_pointer<U>::type, // добавили указатель если да
                typename std::remove_cv<U>::type    // удалили всякие константы если нет
            >::type
        >::type; //вытащили тип того что получилось
};

template<typename T>
using decay_t = typename decay<T>::type;


int main() {
    std::cout << std::is_same_v<int, decay_t<const int&>> << std::endl; 
    std::cout << std::is_same_v<int*, decay_t<int[]>> << std::endl;
    std::cout << std::is_same_v<void(*)(), decay_t<void()>> << std::endl;

    int arr[5];
    std::cout << std::is_same_v<decay_t<decltype(arr)>, int*> << std::endl;
    
}
