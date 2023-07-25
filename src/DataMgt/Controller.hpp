#pragma once

#include "Data.hpp"

using ecci::RedBlackTree;

class Controller {
  public:
    Data controllerData;
    int currentMonth;
    int currentDay;
  public:
    Controller();
    ~Controller();
    void trim(std::string& str);
    int searchKeyByMember(RedBlackTree<int, std::vector<std::string>> tree, std::string memberValue);
    void readData();
    void saveData(int month, std::string& data, int day);
    void saveDataToFile();
    void showData(int month);
    // Must have and option for passing through the months as desired.
    // Must have a menu below the month for choosing going to the next month, the last, adding data or deleting.
    void run();
};