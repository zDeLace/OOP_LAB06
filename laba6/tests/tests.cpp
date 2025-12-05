#include <gtest/gtest.h>
#include "npc.h"
#include "factory.h"
#include "battle_visitor.h"
#include "observer.h"

class DummyObserver : public Observer {
public:
    std::string lastKill;
    void onKill(const std::string& killer,
                const std::string& victim) override {
        lastKill = killer + ">" + victim;
    }
};

TEST(BattleTests, ElfKillsRogue) {
    auto elf = NPCFactory::create("Elf", "EL", 0, 0);
    auto rogue = NPCFactory::create("Rogue", "RG", 0, 0);

    DummyObserver obs;
    std::vector<Observer*> list = { &obs };
    BattleVisitor battle(list);

    try {
        elf->accept(battle, *rogue);
    } catch (...) {}

    EXPECT_EQ(obs.lastKill, "EL>RG");
}

TEST(BattleTests, BearKillsElf) {
    auto bear = NPCFactory::create("Bear", "BR", 0, 0);
    auto elf = NPCFactory::create("Elf", "EL", 0, 0);

    DummyObserver obs;
    std::vector<Observer*> list = { &obs };
    BattleVisitor battle(list);

    try {
        bear->accept(battle, *elf);
    } catch (...) {}

    EXPECT_EQ(obs.lastKill, "BR>EL");
}

TEST(BattleTests, RogueKillsRogue) {
    auto r1 = NPCFactory::create("Rogue", "R1", 0, 0);
    auto r2 = NPCFactory::create("Rogue", "R2", 0, 0);

    DummyObserver obs;
    std::vector<Observer*> list = { &obs };
    BattleVisitor battle(list);

    try {
        r1->accept(battle, *r2);
    } catch (...) {}

    EXPECT_EQ(obs.lastKill, "R1>R2");
}
