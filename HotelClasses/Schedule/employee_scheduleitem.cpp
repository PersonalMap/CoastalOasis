#include "employee_scheduleitem.h"

///Constructors

Employee_scheduleitem::Employee_scheduleitem(const Employee& employee, MyEnums::HotelArea location,
                                             std::string activityName, const HTime& startTime,const HTime& endTime)
                                             :ScheduleItem(std::move(activityName), startTime, endTime),
                                                _employee(employee), _location(location){};

Employee_scheduleitem::~Employee_scheduleitem()=default;

///Operators

///Functions