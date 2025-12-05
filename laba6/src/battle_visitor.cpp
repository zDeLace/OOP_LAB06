#include "battle_visitor.h"
#include "bear.h"
#include "elf.h"
#include "rogue.h"

BattleVisitor::BattleVisitor(std::vector<Observer*>& obs)
    : observers(obs) {}

void BattleVisitor::notify(const std::string& killer, const std::string& victim)
{
    for (auto o : observers)
        o->onKill(killer, victim);
}

void BattleVisitor::visitBear(Bear& bear, NPC& other) {
    if (other.getType() == "Elf") {
        notify(bear.getName(), other.getName());
        throw std::runtime_error("Elf killed");
    }
}

void BattleVisitor::visitElf(Elf& elf, NPC& other) {
    if (other.getType() == "Rogue") {
        notify(elf.getName(), other.getName());
        throw std::runtime_error("Rogue killed");
    }
}

void BattleVisitor::visitRogue(Rogue& rogue, NPC& other) {
    if (other.getType() == "Rogue") {
        notify(rogue.getName(), other.getName());
        throw std::runtime_error("Rogue killed");
    }
}
