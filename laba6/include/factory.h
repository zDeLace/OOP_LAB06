#pragma once
#include <memory>
#include <string>

class NPC;

class NPCFactory {
public:
    static std::shared_ptr<NPC> create(const std::string& type, const std::string& name, int x, int y);
};
