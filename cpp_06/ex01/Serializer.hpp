#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include <inttypes.h>
# include "Data.hpp"

class Serializer
{
    private:
        Serializer(void);
        ~Serializer(void);
        Serializer(Serializer const &other);
        Serializer &operator=(Serializer const &other);
    public:
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);
};

#endif