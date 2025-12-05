#include "bear.h"
#include "visitor.h"

void Bear::accept(NPCVisitor& visitor, NPC& other) {
    visitor.visitBear(*this, other);
}
