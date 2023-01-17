#include "employee_scheduleitem.h"

///Constructors

Employee_scheduleitem::Employee_scheduleitem(Employee employee, MyEnums::HotelArea location,
                                             std::string activityName, long long startTime,long long endTime,bool booked)
                                             :ScheduleItem(activityName, startTime, endTime, booked),
                                                _employee(employee), _location(location){};

Employee_scheduleitem::~Employee_scheduleitem(){};

///Operators

///Functions