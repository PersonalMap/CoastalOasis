#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <iostream>
#include <WeeklySchedule.h>
#include "../person.h"
#include "../../GlobalsAndNecessities/HotelEnums.h"

class Employee : public Person
{
private:
    std::string _advancedDebugStr;
protected:
    WeeklySchedule _schedule;
    MyEnums::Department _workRole;
    std::string _employmentDate;
    float _salary;
    unsigned int _acessLevel;

    //function
    float convertAnnualSalary();

public:

    ///constructor
    Employee(MyEnums::Department workRole, std::string employeDate, float salary,
             unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    ~Employee();

    ///getter & setters
    const MyEnums::Department& getWorkRole()const{return this->_workRole;}
    const std::string& getEmploymentDate()const{return this->_employmentDate;}
    const float& getSalary()const{return this->_salary;}
    const unsigned int& getAcessLevel()const{return this->_acessLevel;}

    void setWorkRole(const MyEnums::Department& newWorkRole){this->_workRole = newWorkRole;}
    void setEmploymentDate(const std::string& newEmployeementDate){this->_employmentDate = newEmployeementDate;}
    void setSalary(const float& newSalary){this->_salary = newSalary;}
    void setAcessLevel(const unsigned int& newAcessLevel){this->_acessLevel = newAcessLevel;}

    WeeklySchedule& getScheduleP(){return this->_schedule;}

    ///operations
    bool operator==(const Employee& other); // == operatoror

    friend std::ostream& operator<<(std::ostream& os, Employee& e); //cout
};
#endif
