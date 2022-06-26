#ifndef DOLPHIN__
#define DOLPHIN__


#include "animal.h"
#include <string>


class Dolphin: public Animal
{
private:
    std::string name;
public:
    Dolphin(std::string name);
    ~Dolphin();
    void Sound() const override;
};

#endif