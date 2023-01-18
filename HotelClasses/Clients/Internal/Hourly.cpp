#include "Hourly.h"





///Constructor
//default
Hourly::Hourly(MyEnums::Department workRole, std::string employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
         _hourSalary(0), _hoursWorked(0){}
//init with hour salary
Hourly::Hourly(unsigned int hourSalary, MyEnums::Department workRole, std::string employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
         _hourSalary(hourSalary), _hoursWorked(0){}
Hourly::~Hourly(){};

///Operators

///Functions

unsigned int Hourly::calculateSalary() const
{
    return this->_hoursWorked * this->_hourSalary;
}