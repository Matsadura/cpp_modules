#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>
#include <string>

typedef struct Data
{
    std::string firstName;
    std::string lastName;
} Data;

class Serializer
{
  private:
    Serializer(void);
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

  public:
    static uintptr_t serialize(Data *ptr);
    static Data     *deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */