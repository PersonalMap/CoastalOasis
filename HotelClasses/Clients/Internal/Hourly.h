#ifndef COASTALOASIS_HOURLY_H
#define COASTALOASIS_HOURLY_H
#include "employee.h"

class Hourly: public Employee{

private:
    unsigned int _hourSalary;
    unsigned int _hoursWorked;

    unsigned int calculateSalary() const;

public:
    ///Constructor

    //default
    Hourly(MyEnums::Department workRole, std::string employeDate, float salary,
    unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    //init with hour salary
    Hourly(unsigned int hourSalary, MyEnums::Department workRole, std::string employeDate, float salary,
    unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    ~Hourly();

    ///getters & setters

    const unsigned int& getHoursWorked(){return _hoursWorked;}
    const unsigned int& getHourSalary(){return _hourSalary;}
    const unsigned int getCalculatedSalary(){return calculateSalary();}

    void setHoursWorked(const unsigned int& hoursWorked){this->_hoursWorked = hoursWorked;}
    void setHourSalary(const unsigned int& hourSalary){this->_hourSalary = hourSalary;}

    ///functions
    void addHour(){_hoursWorked++;}
    void addHours(const unsigned int& h){this->_hoursWorked += h;}
    void subtractHour(){_hoursWorked--;}
    void subtractHours(const unsigned int& h){this->_hoursWorked -= h;}
};


#endif
