#include "Room.h"
#include <iostream>

void Room::enter() const {
    using namespace std;
    cout << "You are in the " << name << ". ";
    if (exits.empty()) {
        cout << "There are no exits." << endl;
    }
    else if (exits.size() == 1) {
        cout << "There is 1 exit: " << exits.begin()->first << "." << endl;
    }
    else {
        cout << "There are " << exits.size() << " exits: ";
        for (auto& pair : exits) {
            cout << pair.first << " ";
        }
        cout << endl;
    }
}

void Room::addExit(const std::string& str, Room* room) {
    exits[str] = room;
}

Room* Room::getExit(const std::string &str) const {
    return exits.at(str);
}

std::string Room::getName() {
    return name;
}

bool Room::hasPrincess() const {
    return false;
}