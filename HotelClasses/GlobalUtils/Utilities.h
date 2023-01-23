#ifndef COASTALOASIS_UTILITIES_H
#define COASTALOASIS_UTILITIES_H
#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <sstream>

#include "HTime.h"
#include "HotelEnums.h"
class Utilities {

public:

    ///functions
    static std::string getCounterEnder(const unsigned int i);
    static unsigned int getNumberOfDays(HTime start, HTime end);
    static unsigned int generateUniqeNmbr();

    static std::vector<std::string>
    split(const std::string& data, char delimiter);

};
#endif //COASTALOASIS_UTILITIES_H
