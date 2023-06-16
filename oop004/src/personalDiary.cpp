//
// Created by XMacBook on 2023/4/26.
//

#include "personalDiary.h"
#include <iostream>
#include <fstream>

personalDiary::personalDiary(const std::string path):filePath(path) {
    std::ifstream fin(filePath);
    if(!fin.is_open())
        throw std::runtime_error("Cannot open file. Please check the file path.");
    std::string line, date;
    while (!fin.eof()) {
        std::getline(fin, date);
        if (date.empty()) continue;
        while(!fin.eof()) {
            std::getline(fin, line);
            if (line.empty()) break;
            diary[date] += line + "\n";
        }
        diary[date].erase(diary[date].end() - 1); // delete the last '\n'
    }
}

personalDiary::~personalDiary() {
    std::ofstream fout;
    fout.open(filePath);
    for (auto& it : diary) {
        fout << it.first << std::endl << it.second << std::endl << std::endl;
    }
}

void personalDiary::show(std::string date) {
    if (diary.contains(date)) {
        std::cout << diary[date] << std::endl;
    }
}

void personalDiary::add(std::string date, std::string content) {
    diary[date] = content;
}

int personalDiary::remove(std::string date) {
    if (diary.contains(date)) {
        diary.erase(date);
        return 0;
    }
    return -1;
}

void personalDiary::list() {
    for (auto& it : diary) {
        std::cout << it.first << std::endl << it.second << std::endl << std::endl;
    }
}

void personalDiary::list(std::string startDate, std::string endDate) {
    for (auto& it : diary) {
        if (it.first >= startDate && it.first <= endDate) {
            std::cout << it.first << std::endl << it.second << std::endl << std::endl;;
        }
    }
}