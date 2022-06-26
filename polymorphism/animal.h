#ifndef ANIMAL_H__
#define ANIMAL_H__


class Animal
{
public:
    Animal() = default;
    ~Animal() = default;
    virtual void Sound() const;
};

// void Animal::Sound() const {

// }
#endif