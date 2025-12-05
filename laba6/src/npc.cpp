#include "npc.h"
#include <iostream>

void NPC::print() const {
    std::cout << getType() << " \"" << name 
              << "\" (" << x << ", " << y << ")\n";
}
