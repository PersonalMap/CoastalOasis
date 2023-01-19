#include "room_scheduleitem.h"

///Constructors

Room_scheduleitem::Room_scheduleitem(User booker, bool isbooked,
                                     const HTime& startTime, const HTime& endTime)
                                        :ScheduleItem("Reservation", startTime, endTime)
                                    ,_booker(booker), _booked(isbooked){}

Room_scheduleitem::~Room_scheduleitem()=default;
///Operators

///Functions