#pragma once
#include "visitor.h"
#include "observer.h"
#include <vector>

class BattleVisitor : public NPCVisitor {
    std::vector<Observer*>& observers;

    void notify(const std::string& killer, const std::string& victim);

public:
    BattleVisitor(std::vector<Observer*>& obs);

    void visitBear(Bear&, NPC&) override;
    void visitElf(Elf&, NPC&) override;
    void visitRogue(Rogue&, NPC&) override;
};
