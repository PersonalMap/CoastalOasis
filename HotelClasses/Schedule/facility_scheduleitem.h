#ifndef FACILITY_SCHEDULEITEM_H
#define FACILITY_SCHEDULEITEM_H
#include "scheduleitem.h"
#include "../GlobalUtils/HotelEnums.h"

class Facility_ScheduleItem: public ScheduleItem
{
private:
    MyEnums::HotelArea _location; //where is this

public:
    ///Constructors
    Facility_ScheduleItem(MyEnums::HotelArea location, bool booked, std::string activityName,
                          long long startTime, long long endTime);
    ~Facility_ScheduleItem();

    ///getters & setters
    const MyEnums::HotelArea& getLocation()const{return this->_location;}

    void setLocation(const MyEnums::HotelArea newLocation){this->_location = newLocation;}
};

#endif
