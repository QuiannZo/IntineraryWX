#pragma once

#include <string>
#include <vector>

#include "RBTree/RBTree.hxx"

class Month {
  public:
    std::string name;
    int lengthInDays;
    std::string initialDay;
    std::string lastDay;
    ecci::RedBlackTree<int, std::vector<std::string>> activities;
    Month(std::string name, int days);
    ~Month();
};

class Data {
  public:
    // the trees store the days (int) of the month and the activities set for the day (string).
    std::vector<Month> monthsVector;
    std::vector<std::string> weekDays = {"monday", "tuesday", "wenedsday", "thursday", "friday", "saturday", "sunday"};
  public:
    Data();
    ~Data();
};