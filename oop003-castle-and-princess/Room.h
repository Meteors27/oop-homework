#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <utility>

class Room {
public:
    explicit Room(std::string str) : name(std::move(str)) {}
    virtual void enter() const;
    virtual bool hasPrincess() const;
    std::string getName();
    void addExit(const std::string& str, Room* room);
    Room* getExit(const std::string& str) const;
protected:
    std::string name;
    std::map<std::string, Room*> exits;
};


#endif //ROOM_H
