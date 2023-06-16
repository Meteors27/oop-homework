#include <iostream>
#include "personalDiary.h"


int main(int argc, char* argv []) {
    if (argc != 4) {
        std::cout << "Usage: pdadd <path to your diary> <date> <content>" << std::endl;
        return 1;
    }
    auto pd = personalDiary(argv[1]);
    pd.add(argv[2], argv[3]);
    return 0;
}
