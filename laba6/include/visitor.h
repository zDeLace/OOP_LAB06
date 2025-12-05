#pragma once

class Bear;
class Elf;
class Rogue;
class NPC;

class NPCVisitor {
public:
    virtual ~NPCVisitor() = default;

    virtual void visitBear(Bear&, NPC&) = 0;
    virtual void visitElf(Elf&, NPC&) = 0;
    virtual void visitRogue(Rogue&, NPC&) = 0;
};
