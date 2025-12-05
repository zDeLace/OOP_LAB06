#pragma once
#include <string>

class NPCVisitor;

class NPC {
protected:
    std::string name;
    int x, y;

public:
    NPC(std::string n, int x, int y) : name(std::move(n)), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string getType() const = 0;
    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }

    virtual void accept(NPCVisitor& visitor, NPC& other) = 0;

    virtual void print() const;

    virtual int getAttackRange() const = 0;
};
