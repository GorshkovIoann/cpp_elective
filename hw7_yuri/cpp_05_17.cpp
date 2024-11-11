#include <iostream>

template<typename T>
struct Entity_v1
{
    virtual ~Entity_v1() = default; 

    void test() const
    {
        static_cast<const T*>(this)->test_impl();
    }
};

struct Client_v1 : public Entity_v1<Client_v1> 
{
    void test_impl() const { std::clog << "Client_v1::test\n"; }
};

struct Client_v2 : public Entity_v1<Client_v2> 
{
    void test_impl() const { std::clog << "Client_v2::test\n"; }
};

template<typename T1, typename T2>
class Entity_v2 
{
public:
    explicit Entity_v2(const Entity_v1<T1>& entity_v1) : m_bridge(entity_v1) {}

    virtual ~Entity_v2() = default; 
    
    void test() const
    {
        static_cast<const T2*>(this)->test_impl();
        m_bridge.test(); 
    }

protected:
    const Entity_v1<T1>& m_bridge;
};

struct Server_v1 : public Entity_v2<Client_v1, Server_v1> 
{
    explicit Server_v1(const Client_v1& client_v1) : Entity_v2(client_v1) {}
        void test_impl() const { std::clog << "server_v1::test\n"; }
};

struct Server_v2 : public Entity_v2<Client_v2, Server_v2> 
{
    explicit Server_v2(const Client_v2& client_v2) : Entity_v2(client_v2) {}
    void test_impl() const { std::clog << "Server_v2::test\n"; }
};

int main() 
{
    Client_v1 client_v1;
    
    Server_v1 server_v1(client_v1);
    server_v1.test();

    Client_v2 client_v2;
    
    Server_v2 server_v2(client_v2);
    server_v2.test();
}
