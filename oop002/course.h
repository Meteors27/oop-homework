#include <map>
#include <iostream>
#if !defined(COURSE_H)
#define COURSE_H
namespace course {
    const std::map<std::string, int> courseMap = {
    {"math", 0},
    {"english", 1},
    {"chinese", 2},
    {"physics", 3},
    {"chemistry", 4},
    {"biology", 5}
    };
    const int courseLenth = 6;
}
#endif // COURSE_H