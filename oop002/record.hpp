#include <iostream>
#include <sstream>
#include "course.h"
#if !defined(RECORD_HPP)
#define RECORD_HPP
class Record {
private:
    std::string name;
    int scoreList[course::courseLenth] = {0};
public:
    void readRecord() {
        std::string line;
        // skip empty lines
        while (line.empty()) {
            getline(std::cin, line);
        }
        std::stringstream ss(line);
        ss >> name;
        int score;
        std::string courseName;
        while (ss >> courseName >> score) {
            scoreList[course::courseMap.at(courseName)] = score;
        }
    }
    std::string getName() const {
        return name;
    }
    int getScore(std::string courseName) const {
        return scoreList[course::courseMap.at(courseName)];
    }
};
#endif // RECORD_HPP