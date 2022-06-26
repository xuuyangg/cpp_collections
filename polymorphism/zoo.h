#ifndef ZOO__
#define ZOO__

#include "animal.h"
#include <vector>



class Zoo:public Animal
{
private:
    std::vector<Animal *> animals;
public:
    Zoo() = default;
    ~Zoo() = default;
    void Push(Animal * ani) {
        animals.push_back(ani);
    }
    void GoToTheZoo() const {
        for (auto anis: animals) {
            anis->Sound();
        }
    }
};

#endif