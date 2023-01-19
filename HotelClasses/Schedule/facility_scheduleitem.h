#ifndef FACILITY_SCHEDULEITEM_H
#define FACILITY_SCHEDULEITEM_H
#include "scheduleitem.h"
#include "../GlobalUtils/HotelEnums.h"

class Facility_ScheduleItem: public ScheduleItem
{
private:
    MyEnums::HotelArea _location; //where is this
    bool _booked;

public:
    ///Constructors
    Facility_ScheduleItem(MyEnums::HotelArea location, bool booked, std::string activityName,
                          const HTime& startTime,const HTime& endTime);
    ~Facility_ScheduleItem();

    ///getters & setters
    const MyEnums::HotelArea& getLocation()const{return this->_location;}
    const bool& getBooked() const{return this->_booked;}

    void setLocation(const MyEnums::HotelArea newLocation){this->_location = newLocation;}
    void setBooked(const bool& isbooked){this->_booked = isbooked;}
};

#endif
