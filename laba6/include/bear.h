#pragma once
#include "npc.h"

class Bear : public NPC {
public:
    Bear(const std::string& n, int x, int y) : NPC(n, x, y) {}

    std::string getType() const override { return "Bear"; }
    void accept(NPCVisitor& visitor, NPC& other) override;
    int getAttackRange() const override { return 30; }

};
