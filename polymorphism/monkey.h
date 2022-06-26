#ifndef MONKEY__
#define MONKEY__


#include "animal.h"
#include <string>


class Monkey: public Animal
{
private:
    std::string name;
public:
    Monkey(std::string name);
    ~Monkey();
    void Sound() const override;
};

#endif