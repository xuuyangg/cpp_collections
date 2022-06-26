#include "monkey.h"
#include <iostream>



Monkey::Monkey(std::string name): name(name){

}

void Monkey::Sound() const {
    std::cout << name << " Monkey sound" << std::endl;
}
