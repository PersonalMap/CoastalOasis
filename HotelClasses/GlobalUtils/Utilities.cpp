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

unsigned int Utilities::getNumberOfDays(HTime start, HTime end)
{
    unsigned int startDay = start.getDay();
    unsigned int endDay = end.getDay();
    auto dayOfMonth = MyEnums::daysOfMonth[start.getMonth()];

    int itterations = 0;
    //get numbers of days that the event is
    if(endDay > startDay)
    {
        itterations = endDay - startDay;
    }
    else
    {
        itterations = (dayOfMonth - startDay) + endDay;
    }
    return itterations;

}

static unsigned int generateUniqeNmbr()
{
    time_t current_time = time(nullptr);
    srand(current_time);
    return (unsigned int)current_time + rand();

}
