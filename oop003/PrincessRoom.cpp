#include "PrincessRoom.h"
#include <iostream>

void PrincessRoom::enter() const {
    std::cout << "You are in the secret room where the princess is being held captive." << std::endl;
    std::cout << "***CONVERSATION***" << std::endl;
    std::cout << "Princess: Thank you for rescuing me!" << std::endl;
    std::cout << "You: I love you!" << std::endl;
    std::cout << "Princess: I love you too!" << std::endl;
    std::cout << "You: Let's get married!" << std::endl;
    std::cout << "Princess: Yes! But we must find our way out!" << std::endl;
    std::cout << "Next mission: get to the Lobby. " << std::endl;
    Room::enter();
}

bool PrincessRoom::hasPrincess() const {
    return true;
}