#include "room_scheduleitem.h"

///Constructors

Room_scheduleitem::Room_scheduleitem(User booker, bool booked, std::string activityName,
                                     long long startTime, long long endTime)
                                        :ScheduleItem(activityName, startTime, endTime, booked)
                                    ,_booker(booker){}

Room_scheduleitem::~Room_scheduleitem(){};
///Operators

///Functions