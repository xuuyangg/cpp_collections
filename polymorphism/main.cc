#include "zoo.h"
#include "dolphin.h"
#include "monkey.h"

int main() {
    Zoo zoo;
    Animal* a = new Monkey("AAA");
    Animal* b = new Monkey("BBB");
    Animal* c = new Monkey("CCC");
    Animal* d = new Monkey("DDD");

    Animal* e = new Dolphin("EEE");
    Animal* f = new Dolphin("FFF");
    Animal* g = new Dolphin("GGG");

    zoo.Push(d);
    zoo.Push(e);
    zoo.Push(a);
    zoo.Push(b);
    zoo.Push(c);
    zoo.Push(f);
    zoo.Push(g);
    
    zoo.GoToTheZoo();
    return 0;
}