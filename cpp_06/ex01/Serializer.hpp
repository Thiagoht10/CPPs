#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

struct Data
{
    std::string name;
    int         value;
};


class Serializer
{
private:
    Serializer();
    Serializer(const Serializer& other);
    Serializer& operator=(const Serializer& other);
    ~Serializer();
    
public:
    static uintptr_t   serialize(Data* prt);
    static Data*       deserialize(uintptr_t raw);

};



#endif