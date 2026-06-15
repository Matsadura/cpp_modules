#include "Serializer.hpp"
#include <iostream>

int main(void)
{
    Data *data      = new Data();
    data->firstName = "Zidane";
    data->lastName  = "ZAOUI";

    std::cout << "Original Data: " << data->firstName << " " << data->lastName << std::endl;

    uintptr_t raw = Serializer::serialize(data);
    std::cout << "Serialized Data (uintptr_t): " << raw << std::endl;

    Data *deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << deserializedData->firstName << " " << deserializedData->lastName << std::endl;

    delete data;
    return 0;
}