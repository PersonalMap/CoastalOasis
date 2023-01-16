#ifndef COASTALOASIS_EMPLOYEE_SCHEDULEITEM_H
#define COASTALOASIS_EMPLOYEE_SCHEDULEITEM_H
#include "scheduleitem.h"
#include "HotelEnums.h"
#include "../Clients/Internal/employee.h"
#include <string>

class Employee_scheduleitem : public ScheduleItem
        {

private:
    MyEnums::HotelArea _location;
    Employee _employee;

public:

    Employee_scheduleitem(Employee employee, MyEnums::HotelArea location, std::string activityName, long long startTime,long long endTime,bool booked):
    ScheduleItem(activityName, startTime, endTime, booked), _employee(employee), _location(location){};

    ~Employee_scheduleitem(){};

    //getters & setters

    const MyEnums::HotelArea& getLocation(){return this->_location;}
    const Employee& getEmployee(){return this->_employee;}

    void setLocation(const MyEnums::HotelArea& hotelArea){this->_location = hotelArea;}
    void setEmployee(const Employee& employee){this->_employee = employee;}
};


#endif //COASTALOASIS_EMPLOYEE_SCHEDULEITEM_H
