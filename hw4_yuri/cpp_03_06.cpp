#include <algorithm>
#include <iostream>

class Container
{
private:
    int *m_data;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    Container() : m_size(0), m_capacity(2) { m_data = new int[m_capacity]{}; }

    Container(std::size_t size) : m_size(size), m_capacity(2 * size ? 2 * size : 2)
    {
        m_data = new int[m_capacity]{};
    }

    Container(const Container &other) : m_size(other.m_size), m_capacity(other.m_capacity)
    {
        m_data = new int[m_capacity];
        std::copy_n(other.m_data, m_size, m_data);
    }

    Container(Container &&other) noexcept : Container()
    {
        swap(other);
    }

    Container &operator=(Container other)
    {
        swap(other);
        return *this;
    }

    ~Container()
    {
        delete[] m_data;
    }

    void swap(Container &other) noexcept
    {
        using std::swap;
        swap(m_data, other.m_data);
        swap(m_size, other.m_size);
        swap(m_capacity, other.m_capacity);
    }

    int &front() { return m_data[0]; }
    int &front() const { return m_data[0]; }

    int &back() { return m_data[m_size - 1]; }
    int &back() const { return m_data[m_size - 1]; }

    int &operator[](std::size_t index) { return m_data[index]; }
    int &operator[](std::size_t index) const { return m_data[index]; }

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    bool empty() const { return m_size == 0; }

    void clear() { m_size = 0; }

    void push_back(int value)
    {
        if (m_size == m_capacity)
        {
            reserve(m_capacity * 2);
        }
        m_data[m_size++] = value;
    }

private:
    void reserve(std::size_t new_capacity)
    {
        if (new_capacity <= m_capacity)
            return;

        int *new_data = new int[new_capacity];
        std::copy_n(m_data, m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
};

