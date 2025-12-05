#pragma once
#include "npc.h"

class Rogue : public NPC {
public:
    Rogue(const std::string& n, int x, int y) : NPC(n, x, y) {}

    std::string getType() const override { return "Rogue"; }
    void accept(NPCVisitor& visitor, NPC& other) override;
    int getAttackRange() const override { return 40; }

};
