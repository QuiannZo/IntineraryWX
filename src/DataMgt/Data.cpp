#include "Data.hpp"

Data::Data(){}

Data::~Data(){
    // default.
}

Month::Month(std::string name, int days)
: name{name}, lengthInDays{days}
{}

Month::~Month(){}