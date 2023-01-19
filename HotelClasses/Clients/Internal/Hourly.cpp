#include "Hourly.h"

///Constructor
//default
Hourly::Hourly(MyEnums::Department workRole, const HTime& employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(workRole, employeDate, salary, acessLevel,std::move(name),std::move(phone),std::move(age)),
         _hourSalary(0), _hoursWorked(0){}
//init with hour salary
Hourly::Hourly(unsigned int hourSalary, MyEnums::Department workRole,const HTime& employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(workRole, employeDate, salary, acessLevel, std::move(name),std::move(phone), std::move(age)),
         _hourSalary(hourSalary), _hoursWorked(0){}
Hourly::~Hourly()=default;

///Operators

///Functions

unsigned int Hourly::calculateSalary() const
{
    return this->_hoursWorked * this->_hourSalary;
}