#include "facility_scheduleitem.h"

///Constructors

Facility_ScheduleItem::Facility_ScheduleItem(MyEnums::HotelArea location, bool booked,
                                             std::string activityName, long long startTime,long long endTime)
                                                :ScheduleItem(activityName, startTime, endTime, booked)
                                            , _location(location){}
Facility_ScheduleItem::~Facility_ScheduleItem(){};

///Operators

///Functions