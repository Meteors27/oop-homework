#include "Castle.h"
#include "MonsterRoom.h"
#include "PrincessRoom.h"
#include <iostream>
#include <algorithm>
#include <random>
Castle::Castle() :
findPrincess(false)
{
    rooms = {
        new Room("Lobby"),
        new MonsterRoom("Monster Room"),
        new PrincessRoom("Secret Room"),
        new Room("Kitchen"),
        new Room("Balcony")
    };
    // random shuffle
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(rooms.begin()+1, rooms.end(), std::default_random_engine(seed));

    // init room exits
    rooms[0]->addExit("east", rooms[1]);
    rooms[0]->addExit("west", rooms[3]);
    rooms[0]->addExit("up", rooms[2]);
    rooms[1]->addExit("west", rooms[0]);
    rooms[1]->addExit("up", rooms[4]);
    rooms[2]->addExit("down", rooms[0]);
    rooms[2]->addExit("east", rooms[4]);
    rooms[3]->addExit("east", rooms[0]);
    rooms[4]->addExit("down", rooms[1]);
    rooms[4]->addExit("west", rooms[2]);

    std::cout << "Welcome to the castle! " << std::endl;
    std::cout << "Your misson is to find the princess and bring her back to the lobby. " << std::endl;
}

void Castle::play() {
    auto current_room = rooms[0];
    while (true) {
        current_room->enter();
        std::string command, input;
        std::cout << "Enter your command: ";
        std::cin >> command;
        if (command != "go"){
            std::cout << "Invalid command. Please use command 'go' and try again. " << std::endl;
            continue;
        }

        std::cin >> input;
        try {
            current_room = current_room->getExit(input);
            if (current_room->hasPrincess())
                findPrincess = true;
            if (findPrincess && current_room->getName() == "Lobby") {
                std::cout << "You have found the princess and brought her back to the lobby. " << std::endl;
                std::cout << "You won! " << std::endl;
                break;
            }
        }
        catch (const std::out_of_range& e) {
            std::cout << "You cannot go that way. " << std::endl;
        }
    }
}

Castle::~Castle() {
    // Delete the rooms
    for (auto& room : rooms) {
        delete room;
    }
}