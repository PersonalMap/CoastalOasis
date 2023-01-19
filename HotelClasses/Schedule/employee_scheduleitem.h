#ifndef COASTALOASIS_EMPLOYEE_SCHEDULEITEM_H
#define COASTALOASIS_EMPLOYEE_SCHEDULEITEM_H
#include "scheduleitem.h"
#include "HotelEnums.h"
#include "../Clients/Internal/employee.h"
#include <string>

class Employee_scheduleitem : public ScheduleItem{

private:
    MyEnums::HotelArea _location;
    Employee _employee;

public:

    ///constructors
    Employee_scheduleitem(const Employee& employee, MyEnums::HotelArea location,
                          std::string activityName, const HTime& startTime,const HTime& endTime);

    ~Employee_scheduleitem();

    ///getters & setters
    const MyEnums::HotelArea& getLocation()const{return this->_location;}
    const Employee& getEmployee()const{return this->_employee;}

    void setLocation(const MyEnums::HotelArea& hotelArea){this->_location = hotelArea;}
    void setEmployee(const Employee& employee){this->_employee = employee;}
};


#endif
