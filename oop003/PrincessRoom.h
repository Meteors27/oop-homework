#ifndef PRINCESSROOM_H
#define PRINCESSROOM_H
#include "Room.h"

class PrincessRoom : public Room {
public:
    PrincessRoom(const std::string& str) : Room(str) {}
    virtual void enter() const;
    virtual bool hasPrincess() const;
};

#endif
