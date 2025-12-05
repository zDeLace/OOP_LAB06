#include <iostream>
#include <vector>
#include <memory>
#include <random>
#include <algorithm>
#include <cmath>

#include "npc.h"
#include "factory.h"
#include "battle_visitor.h"
#include "observer.h"

int rnd(int min, int max) {
    static std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

double distanceBetween(const NPC& a, const NPC& b) {
    int dx = a.getX() - b.getX();
    int dy = a.getY() - b.getY();
    return std::sqrt(dx * dx + dy * dy);
}

int main() {
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<Observer*> observers;

    LogObserver log("log.txt");
    observers.push_back(&log);

    const std::vector<std::string> types = { "Bear", "Elf", "Rogue" };

    std::cout << "Generating NPCs...\n";
    for (int i = 0; i < 10; i++) {
        std::string type = types[rnd(0, types.size() - 1)];
        std::string name = type + "_" + std::to_string(i + 1);

        npcs.push_back(
            NPCFactory::create(type, name, rnd(0, 200), rnd(0, 200))
        );
    }

    std::cout << "\n=== NPC LIST ===\n";
    for (auto& npc : npcs)
        npc->print();

    std::cout << "\n=== COMBAT PHASE ===\n";

    BattleVisitor battle(observers);
    std::vector<std::shared_ptr<NPC>> dead;

    for (size_t i = 0; i < npcs.size(); i++) {
        for (size_t j = 0; j < npcs.size(); j++) {
            if (i == j) continue;

            auto& attacker = *npcs[i];
            auto& target   = *npcs[j];

            double dist = distanceBetween(attacker, target);

            std::cout << attacker.getName()
                      << " -> " << target.getName()
                      << " | distance = " << dist << "\n";

            if (dist > attacker.getAttackRange()) {
                std::cout << "   Too far, cannot attack.\n";
                continue;
            }

            std::cout << "   Attack allowed!\n";

            try {
                attacker.accept(battle, target);
            }
            catch (...) {
                std::cout << "   " << target.getName() << " has been killed.\n";
                dead.push_back(npcs[j]);
            }
        }
    }

    npcs.erase(
        std::remove_if(
            npcs.begin(),
            npcs.end(),
            [&](const std::shared_ptr<NPC>& npc) {
                return std::find(dead.begin(), dead.end(), npc) != dead.end();
            }),
        npcs.end()
    );

    std::cout << "\n=== SURVIVORS ===\n";
    for (auto& npc : npcs)
        npc->print();

    std::cout << "\nSimulation complete. Logs saved to log.txt.\n";

    return 0;
}
