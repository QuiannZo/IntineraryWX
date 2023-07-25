#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>


#include "Controller.hpp"
#include "RBTree/RBTree.hxx"

using ecci::RedBlackTree;

// Constructor.
Controller::Controller() {
    std::time_t currentTime = std::time(nullptr);
    std::tm* localTime = std::localtime(&currentTime);
    currentDay = localTime->tm_mday;
    currentMonth = localTime->tm_mon + 1;
}

//Default destructor.
Controller::~Controller() {}

//returns the corresponding key of a value contained in the values vector.
int Controller::searchKeyByMember(RedBlackTree<int, std::vector<std::string>> tree, std::string memberValue){
    for(RedBlackTree<int, std::vector<std::string>>::Iterator itr = tree.begin(); itr != tree.end(); ++itr){
        for(int i = 0; i < itr.getValue().size(); ++i){
            if(itr.getValue().at(i) == memberValue){
                return itr.getKey();
            }
        }
    }
    // In case the memberValue is not a member of tree return 1.
    return 1;
}

// Trim function to get the blank lines.
// Used for checking blank lines in readDara().
void Controller::trim(std::string& str) {
    str.erase(str.begin(), std::find_if(str.begin(), str.end(), [](int ch) {
        return !(std::isspace(ch)); }));

    str.erase(std::find_if(str.rbegin(), str.rend(), [](int ch) {
        return !(std::isspace(ch)); }).base(), str.end());
}

// Data reader. Reads from the saver file of the desired semester folder.
void Controller::readData(){
    // open file.
    std::ifstream fSaver("data/semesterTwo2023/saver.csv");

    if(!fSaver){
        std::cout << "Failed to open the file." << std::endl;
    }

    //// Now read the file ////
    
    std::string line;
    // counter to go through the months in the array and save the data.
    int currentMonth = 0;
    while(std::getline(fSaver, line)){
        trim(line);
        if(line.empty()){
            break;
        }
        std::istringstream ss(line);
        std::string name;
        std::string strLength;
        std::string firstDay;
        std::string lastDay;

        std::getline(ss, name, ',');
        std::getline(ss, strLength, ',');
        std::getline(ss, firstDay, ',');
        std::getline(ss, lastDay, ',');

        trim(strLength);
        int intLength = std::stoi(strLength);

        Month month(name, intLength);
        month.initialDay = firstDay;
        month.lastDay = lastDay;
        controllerData.monthsVector.push_back(month);

        // Now read the data for the current month.
        while(std::getline(fSaver, line)){
            trim(line);
            if(line.empty()){
                break;
            }
            std::istringstream ss2(line);
            std::string data;
            std::string key;
            std::getline(ss2, data, ',');
            std::getline(ss2, key, ',');

            trim(key);
            int intKey = std::stoi(key);

            // Store found data in the tree inside the current month at monthsVector.
            controllerData.monthsVector.at(currentMonth).activities[intKey].push_back(data);
        }
        currentMonth++;
    }
    // Testing.
    /*for(RedBlackTree<int, std::vector<std::string>>::Iterator itr = controllerData.monthsVector.at(1).activities.begin();
    itr != controllerData.monthsVector.at(1).activities.end(); ++itr){
        for(int i = 0; i < itr.getValue().size(); ++i){
            std::cout << "Test: " << itr.getKey() << ": " << itr.getValue().at(i) << std::endl;
        }
    }*/
}

void Controller::saveData(int month, std::string& data, int day){
    //
    for(int i = 7; i <= 12; ++i){
        if(month == i){
            int x = i - 7;
            controllerData.monthsVector.at(x).activities[day].push_back(data);
        }
    }
}

void Controller::saveDataToFile(){
    // Store the data in the file using the trees.
    std::fstream file("data/semesterTwo2023/saver.csv", std::ios::in | std::ios::out);

    // Check if the file was opened
    if (!file.is_open()) {
        std::cout << "Failed to open the file." << std::endl;
    }

    std::string currentContent;

    for(int i = 0; i < controllerData.monthsVector.size(); ++i){
        // First, the header.
        currentContent += (controllerData.monthsVector.at(i).name + ',' + std::to_string(controllerData.monthsVector.at(i).lengthInDays)
         + ',' + controllerData.monthsVector.at(i).initialDay + ',' + controllerData.monthsVector.at(i).lastDay);
        currentContent += '\n';
        // The tasks of the month.
        for(RedBlackTree<int, std::vector<std::string>>::Iterator itr = controllerData.monthsVector.at(i).activities.begin();
        itr != controllerData.monthsVector.at(i).activities.end(); ++itr){
            // store each activity.
            for(int i = 0; i < itr.getValue().size(); ++i){
                currentContent += itr.getValue().at(i) + ',' + std::to_string(itr.getKey());
                currentContent += '\n';
            }
        }
        currentContent += '\n';
    }
    file.seekp(0); // moves file pointer to the beggining of the file.
    file << currentContent;
}

void Controller::showData(int month){
    // month - 7 to evaluate pos in the vector.
    int x = month - 7;
    // find corresponding days.
    int initDay = 0;
    for(int i = 0; i < 7; ++i){
        if(controllerData.weekDays.at(i) == controllerData.monthsVector.at(x).initialDay){
            initDay = i;
        }
    }
    // iterate through.
    std::cout << controllerData.monthsVector.at(x).name << ": " << std::endl;
    for(int i = 0; i < controllerData.monthsVector.at(x).lengthInDays; ++i){
        std::cout << std::to_string(i + 1) << ": ";
        // print weekday.
        int y = initDay % 7;
        std::cout << controllerData.weekDays.at(y) << ". ";
        // print if current.
        if(currentMonth == month)
            if(currentDay == i)
                std::cout << "current.";
        std::cout << std::endl;
        for(RedBlackTree<int, std::vector<std::string>>::Iterator itr = controllerData.monthsVector.at(x).activities.begin();
        itr != controllerData.monthsVector.at(x).activities.end(); ++itr){
            // store each activity.
            for(int j = 0; j < itr.getValue().size(); ++j){
                if(itr.getKey() == i){
                    std::cout << "  " << itr.getValue().at(j) << std::endl;
                }
            }
        }
        initDay++;
    }
}