#include "dolphin.h"
#include <iostream>



Dolphin::Dolphin(std::string name): name(name) {

}

void Dolphin::Sound() const{
    std::cout << name << " Dolphin sound" << std::endl;
}