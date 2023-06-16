#ifndef MONSTERROOM_H
#define MONSTERROOM_H
#include "Room.h"
class MonsterRoom : public Room {
public:
    MonsterRoom(const std::string& str) : Room(str) {}
    virtual void enter() const;
};

#endif //OOP_MONSTERROOM_H
