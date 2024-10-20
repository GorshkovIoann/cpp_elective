#include <algorithm>
#include <iostream>

template <typename T>
class Container
{
private:
    T *m_data;
    std::size_t m_size;
    std::size_t m_capacity;

public:
    Container() : m_size(0), m_capacity(0) {}

    Container(std::size_t size) : m_size(size), m_capacity(size)
    {
        m_data = new T[m_capacity]{};
    }

    Container(const Container &other) : m_size(other.m_size), m_capacity(other.m_capacity)
    {
        m_data = new T[m_capacity];
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

    T &front()
    {
        if (!m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[0];
    }
    T &front() const
    {
        if (!m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[0];
    }

    T &back()
    {
        if (!m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[m_size - 1];
    }
    T &back() const
    {
        if (!m_size)
        {
            throw std::out_of_range("Index out of range");
        }
        return m_data[m_size - 1];
    }

    T &operator[](std::size_t index) { return m_data[index]; }
    T &operator[](std::size_t index) const { return m_data[index]; }

    std::size_t size() const { return m_size; }
    std::size_t capacity() const { return m_capacity; }

    bool empty() const { return m_size == 0; }

    void clear() { m_size = 0; }

    void push_back(T value)
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

        T *new_data = new T[new_capacity];
        std::copy_n(m_data, m_size, new_data);
        delete[] m_data;
        m_data = new_data;
        m_capacity = new_capacity;
    }
};