#include "rogue.h"
#include "visitor.h"

void Rogue::accept(NPCVisitor& visitor, NPC& other) {
    visitor.visitRogue(*this, other);
}
