#include <iostream>
#include "personalDiary.h"


int main(int argc, char* argv []) {
    if (!(argc == 2 || argc == 4)) {
        std::cout << "Usage: pdlist <path to your diary> or pdlist <path to your diary> <start date> <end date>" << std::endl;
        return 1;
    }
    auto pd = personalDiary(argv[1]);
    if (argc == 4) {
        pd.list(argv[2], argv[3]);
        return 0;
    }
    else
        pd.list();
    return 0;
}