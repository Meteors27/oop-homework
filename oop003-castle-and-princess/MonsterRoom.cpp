#include "MonsterRoom.h"
#include <iostream>
void MonsterRoom::enter() const {
    std::cout << "You are in the " << name << std::endl;
    std::cout << "***CONVERSATION*** " << std::endl;
    std::cout << "Monster: I am going to eat you. " << std::endl;
    std::cout << "You: No, please don't. " << std::endl;
    std::cout << "Monster smiles, bloody mouth wide open." << std::endl;
    std::cout << "You are dead. " << std::endl;
    std::cout << "Game over. " << std::endl;
    exit(0);
}