#include "Utilities.h"

#include "Utilities.h"

///functions
std::string Utilities::getCounterEnder(const unsigned int i)
{
    std::string s = "";
    switch (i)
    {
        case 1: s = "st";
            break;
        case 2: s = "nd";
            break;
        case 3: s = "rd";
            break;
        default: s = "th";
            break;
    }
    return s;
}
