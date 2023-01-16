#ifndef FACILITY_SCHEDULEITEM_H
#define FACILITY_SCHEDULEITEM_H
#include "scheduleitem.h"
#include "../GlobalsAndNecessities/HotelEnums.h"

class Facility_ScheduleItem: public ScheduleItem
{

private:
    MyEnums::HotelArea _location; //where is this

public:
    Facility_ScheduleItem(MyEnums::HotelArea location, bool booked, std::string activityName, long long startTime, long long endTime)
        :ScheduleItem(activityName, startTime, endTime, booked), _location(location){}
    ~Facility_ScheduleItem();

    //getters & setters
    const MyEnums::HotelArea& getLocation(){return this->_location;}

    void setLocation(const MyEnums::HotelArea newLocation){this->_location = newLocation;}

};

#endif // FACILITY_SCHEDULEITEM_H
