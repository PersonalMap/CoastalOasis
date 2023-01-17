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

    WeeklySchedule _schema;

protected:
    MyEnums::Department _workRole;
    std::string _employmentDate;
    float _salary;
    unsigned int _acessLevel;

    //function
    float convertAnnualSalary(){return 12*_salary;}

public:

    //constructor
    Employee(MyEnums::Department workRole, std::string employeDate, float salary, unsigned int acessLevel,
             std::string name, std::string phone, unsigned int age):Person(name, phone, age),
        _workRole(workRole),_employmentDate(employeDate), _salary(salary), _acessLevel(acessLevel)
        {
        _advancedDebugStr = "";
        }
    ~Employee();

    //getter & setters

    const MyEnums::Department& getWorkRole(){return this->_workRole;}
    const std::string& getEmploymentDate(){return this->_employmentDate;}
    const float& getSalary(){return this->_salary;}
    const unsigned int& getAcessLevel(){return this->_acessLevel;}
    inline WeeklySchedule& getScheduleP(){return this->_schema;}

    void setWorkRole(const MyEnums::Department& newWorkRole){this->_workRole = newWorkRole;}
    void setEmploymentDate(const std::string& newEmployeementDate){this->_employmentDate = newEmployeementDate;}
    void setSalary(const float& newSalary){this->_salary = newSalary;}
    void setAcessLevel(const unsigned int& newAcessLevel){this->_acessLevel = newAcessLevel;}
    //add scheduel setters if necissery

    //operations

    friend std::ostream& operator<<(std::ostream& os, Employee& e)
    {
       return os << e._name << ", " << e._age << "(" << MyEnums::departmentMap[e._workRole] << ")\n"
       << "AnnualSalary: " << e.convertAnnualSalary() << "$\n"
       << "Phone: " << e._phoneNumber << "\t" << std::endl;
    }
};
#endif // EMPLOYEE_H
