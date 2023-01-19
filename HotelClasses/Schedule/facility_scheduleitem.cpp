#include "facility_scheduleitem.h"

///Constructors

Facility_ScheduleItem::Facility_ScheduleItem(MyEnums::HotelArea location, bool booked,
                                             std::string activityName, const HTime& startTime,const HTime& endTime)
                                                :ScheduleItem(std::move(activityName), startTime, endTime)
                                            , _location(location), _booked(booked){}
Facility_ScheduleItem::~Facility_ScheduleItem() = default;

///Operators

///Functions