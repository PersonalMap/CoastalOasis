#include "room_scheduleitem.h"

///Constructors

Room_scheduleitem::Room_scheduleitem(User booker, bool isbooked, std::string activityName,
                                     const HTime& startTime, const HTime& endTime)
                                        :ScheduleItem(std::move(activityName), startTime, endTime)
                                    ,_booker(booker), _booked(isbooked){}

Room_scheduleitem::~Room_scheduleitem()=default;
///Operators

///Functions