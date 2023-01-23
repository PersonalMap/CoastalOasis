#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "WeeklySchedule.h"
#include "../../GlobalUtils/HotelEnums.h"
#include "Utilities.h"
#include "../person.h"


class Employee : public Person
{
private:
    std::string _advancedDebugStr;
protected:
    WeeklySchedule _schedule;
    MyEnums::Department _workRole;
    HTime _employmentDate;
    float _salary;
    unsigned int _acessLevel;

    //function
    float convertAnnualSalary();

public:

    ///constructor
    Employee();
    Employee(MyEnums::Department workRole, const HTime& employeDate, float salary,
            unsigned int acessLevel,std::string name, std::string phone,unsigned int age);

    ~Employee();

    ///getter & setters
    const MyEnums::Department& getWorkRole()const{return this->_workRole;}
    const HTime& getEmploymentDate()const{return this->_employmentDate;}
    const float& getSalary()const{return this->_salary;}
    const unsigned int& getAcessLevel()const{return this->_acessLevel;}

    void setWorkRole(const MyEnums::Department& newWorkRole){this->_workRole = newWorkRole;}
    void setEmploymentDate(const HTime& newEmployeementDate){this->_employmentDate = newEmployeementDate;}
    void setSalary(const float& newSalary){this->_salary = newSalary;}
    void setAcessLevel(const unsigned int& newAcessLevel){this->_acessLevel = newAcessLevel;}

    WeeklySchedule& getScheduleP(){return this->_schedule;}

    ///operations
    bool operator==(const Employee& rhs) const {
        return this->_phoneNumber == rhs.getPhone() && this->_name == rhs.getName();
    }

    friend std::ostream& operator<<(std::ostream& os, Employee& e); //cout

    //functions
     void parse(std::string data);
     std::string to_string()const;
};
#endif
