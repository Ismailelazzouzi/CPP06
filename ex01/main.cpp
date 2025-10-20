#include "Serialization.hpp"

int main()
{
    Data *data = new Data;
    Data *newData = NULL;
    data->placeholder = std::string("wach");

    std::cout << data->placeholder << std::endl;
    uintptr_t raw = Serializer::serialize(data);
    std::cout << raw << std::endl;
    newData = Serializer::deserialize(raw);
    std::cout << (data == newData) << std::endl;
    std::cout << newData->placeholder << std::endl;
    delete data;
}