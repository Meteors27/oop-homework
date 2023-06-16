#include "course.h"
#include "record.hpp"
#include <iostream>
#include <iomanip>

#define WIDTH 10 // output diagram seperation width

std::ostream& operator<<(std::ostream& out, const Record& r)
{
    out << "(" << r.getName();
    for (auto& course : course::courseMap) {
        out << ",  " << course.first << ": " << ((r.getScore(course.first) > 0) ? std::to_string(r.getScore(course.first)) : "NaN");
    }
    out << ")" << std::endl;
    return out;
}

template <typename T>
void formatPrint(const T s) {
    std::cout << std::setiosflags(std::ios::left) << std::setw(WIDTH) << s;
}

void formatPrint(const Record& r) {
    formatPrint(r.getName());
    for (auto& course : course::courseMap) {
        formatPrint(((r.getScore(course.first) > 0) ? std::to_string(r.getScore(course.first)) : ""));
    }
}

double average(const Record& r) {
    int sum = 0;
    int count = 0;
    for (auto& course : course::courseMap) {
        if (r.getScore(course.first) > 0) {
            sum += r.getScore(course.first);
            count++;
        }
    }
    return (count > 0) ? sum*1.0/count : 0;
}

void printDiagram(Record records[], int num) {
    // print diagram title
    formatPrint("no");
    formatPrint("name");
    for (auto& course : course::courseMap) {
        formatPrint(course.first);
    }
    formatPrint("average");
    std::cout << std::endl;
    // print data
    for (int i = 0; i < num; i++){
        formatPrint(i+1);
        formatPrint(records[i]);
        formatPrint(average(records[i]));
        std::cout << std::endl;
    }
    // print average
    formatPrint("average");
    formatPrint("");
    for (auto& course : course::courseMap) {
        int sum = 0;
        int count = 0;
        for (int i = 0; i < num; i++) {
            if (records[i].getScore(course.first) > 0) {
                sum += records[i].getScore(course.first);
                count++;
            }
        }
        formatPrint((count > 0) ? sum*1.0/count : 0.0);
    }
    std::cout << std::endl;
    // print max
    formatPrint("max");
    formatPrint("");
    for (auto& course : course::courseMap) {
        int max = 0;
        for (int i = 0; i < num; i++) {
            if (records[i].getScore(course.first) > max) {
                max = records[i].getScore(course.first);
            }
        }
        formatPrint((max > 0) ? max : 0.0);
    }
    std::cout << std::endl;
    // print min
    formatPrint("min");
    formatPrint("");
    for (auto& course : course::courseMap) {
        int min = 100;
        for (int i = 0; i < num; i++) {
            if (records[i].getScore(course.first) > 0 && records[i].getScore(course.first) < min) {
                min = records[i].getScore(course.first);
            }
        }
        formatPrint((min < 100) ? min : 0.0);
    }
    std::cout << std::endl;
}

int main() {
    std::cout << "Available courses:";
    for (auto& course : course::courseMap) {
        std::cout << " " << course.first;
    }
    std::cout << std::endl << "Please input the number of students: ";
    int num;
    std::cin >> num;
    Record records[num];
    std::cout << "Input format: \"name course1 score1 course2 score2 ... \\n\"\nPlease input the records:" << std::endl;
    for (int i = 0; i < num; i++) {
        records[i].readRecord();
    }
    printDiagram(records, num);
    return 0;
}