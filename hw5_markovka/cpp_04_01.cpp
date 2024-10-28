#include <algorithm>
#include <cassert>
#include <iterator>
#include <numeric>

template<typename T>
[[nodiscard]] const T* binary_search(const T* array, std::size_t size, const T& key)
{
    if (size > 0)
    {
        std::size_t l = 0, r = size - 1, m{};
        
        while (l < r)
        {       
            array[m = std::midpoint(l, r)] < key ? l = m + 1 : r = m;
        }
        
        return (array[l] == key ? array + l : nullptr);
    }
    else
    {
        return nullptr;
    }
}

//  ================================================================================================

int main()
{
    const std::size_t size = 5;

    const int array[size] { 1, 2, 3, 4, 5 };

    assert(binary_search(array, size, 1) == array + 0);
    assert(binary_search(array, size, 2) == array + 1);
    assert(binary_search(array, size, 3) == array + 2);
    assert(binary_search(array, size, 4) == array + 3);
    assert(binary_search(array, size, 5) == array + 4);

    return 0;
}
