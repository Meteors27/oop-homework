#include <iostream>
#include "personalDiary.h"


int main(int argc, char* argv []) {
    if (argc != 3) {
        std::cout << "Usage: pdremove <path to your diary> <date>" << std::endl;
        return 1;
    }
    auto pd = personalDiary(argv[1]);
    pd.remove(argv[2]);
    return 0;
}
