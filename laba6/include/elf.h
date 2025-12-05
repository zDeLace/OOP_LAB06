#pragma once
#include "npc.h"

class Elf : public NPC {
public:
    Elf(const std::string& n, int x, int y) : NPC(n, x, y) {}

    std::string getType() const override { return "Elf"; }
    void accept(NPCVisitor& visitor, NPC& other) override;
    int getAttackRange() const override { return 70; }

};
