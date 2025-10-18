#include "Serializer.hpp"

int main()
{
    Data data;

    data.a = 7;
    data.b = 's';

    std::cout << "Original pointer: " << &data << std::endl;
    std::cout << "Original values: a = " << data.a << ", b = " << data.b << std::endl;

    uintptr_t var = Serializer::serialize(&data);
    Data* data1 = Serializer::deserialize(var);

    std::cout << "Deserialized pointer: " << data1 << std::endl;
    std::cout << "Deserialized values: a = " << data1->a << ", b = " << data1->b << std::endl;

    std::cout << "Pointers equal? " << std::boolalpha << (&data == data1) << std::endl;
}
