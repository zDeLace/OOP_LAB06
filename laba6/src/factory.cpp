#include "factory.h"
#include "bear.h"
#include "elf.h"
#include "rogue.h"
#include <stdexcept>

std::shared_ptr<NPC> NPCFactory::create(const std::string& type, const std::string& name, int x, int y)
{
    if (type == "Bear") return std::make_shared<Bear>(name, x, y);
    if (type == "Elf") return std::make_shared<Elf>(name, x, y);
    if (type == "Rogue") return std::make_shared<Rogue>(name, x, y);

    throw std::runtime_error("Unknown NPC type: " + type);
}
