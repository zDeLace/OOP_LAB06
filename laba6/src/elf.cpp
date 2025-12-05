#include "elf.h"
#include "visitor.h"

void Elf::accept(NPCVisitor& visitor, NPC& other) {
    visitor.visitElf(*this, other);
}
