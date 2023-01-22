#ifndef COASTALOASIS_UTILITIES_H
#define COASTALOASIS_UTILITIES_H
#include <string>
#include "HTime.h"
#include "HotelEnums.h"
class Utilities {

public:

    ///functions
    static std::string getCounterEnder(const unsigned int i);
    static unsigned int getNumberOfDays(HTime start, HTime end);
};
#endif //COASTALOASIS_UTILITIES_H
