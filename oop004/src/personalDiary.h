//
// Created by XMacBook on 2023/4/26.
//

#ifndef OOP004_PERSONAL_DIARY_H
#define OOP004_PERSONAL_DIARY_H
#include <iostream>
#include <map>

class personalDiary {
private:
    std::map<std::string, std::string> diary;
    std::string filePath;
public:
    personalDiary(const std::string filePath);
    ~personalDiary();
    void add(std::string date, std::string content);
    int remove(std::string date);
    void list();
    void list(std::string startDate, std::string endDate);
    void show(std::string date);
};


#endif //OOP004_PERSONAL_DIARY_H
