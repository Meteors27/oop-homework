#ifndef CASTLE_H
#define CASTLE_H
#include "Room.h"
#include <vector>

class Castle {
public:
    Castle();
    ~Castle();
    void play();
private:
    std::vector<Room*> rooms;
    bool findPrincess;
};

#endif //CASTLE_H
