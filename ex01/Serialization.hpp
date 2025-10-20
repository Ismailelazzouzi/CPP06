#include <iostream>
#include <cstdint>

struct Data
{
    std::string placeholder;
};


class Serializer
{
private:
    Serializer(/* args */);
public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
    ~Serializer(){};
};
