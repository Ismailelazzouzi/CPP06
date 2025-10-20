#include "Serialization.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
    uintptr_t p = reinterpret_cast<uintptr_t>(ptr);
    return (p);
}

Data *Serializer::deserialize(uintptr_t raw)
{
    Data *ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
}