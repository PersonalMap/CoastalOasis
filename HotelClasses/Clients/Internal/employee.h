#pragma once
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
    std::string _email;
    std::string _password;
    WeeklySchedule _schedule;
    MyEnums::Department _workRole;
    HTime _employmentDate;
    float _salary;
    unsigned int _acessLevel;
    MyEnums::WorkPosition _position;

    //function
    float convertAnnualSalary();

public:

    ///constructor
    Employee() = default;
    Employee(std::string email, std::string password,MyEnums::WorkPosition pos,MyEnums::Department workRole, const HTime& employeDate, float salary,
            unsigned int acessLevel,std::string name, std::string phone,unsigned int age);

    virtual ~Employee() {}

    ///getter & setters
    const std::string& getEmail()const{return this->_email;}
    const std::string& getPassword()const{return this->_password;}
    const MyEnums::Department& getWorkRole()const{return this->_workRole;}
    const HTime& getEmploymentDate()const{return this->_employmentDate;}
    const float& getSalary()const{return this->_salary;}
    const unsigned int& getAcessLevel()const{return this->_acessLevel;}
    const MyEnums::WorkPosition& getWorkPosition()const{return this->_position;}

    void setEmail(const std::string& email){this->_email = email;}
    void setPassword(const std::string& password){this->_password = password;}
    void setWorkRole(const MyEnums::Department& newWorkRole){this->_workRole = newWorkRole;}
    void setEmploymentDate(const HTime& newEmployeementDate){this->_employmentDate = newEmployeementDate;}
    void setSalary(const float& newSalary){this->_salary = newSalary;}
    void setAcessLevel(const unsigned int& newAcessLevel){this->_acessLevel = newAcessLevel;}
    void setWorkPosition(const MyEnums::WorkPosition& pos){this->_position = pos;}

    WeeklySchedule& getScheduleP(){return this->_schedule;}

    ///operations
    bool operator==(const Employee& rhs) const {
        return this->_phoneNumber == rhs.getPhone() && this->_name == rhs.getName();
    }

   friend std::ostream& operator<<(std::ostream& os, const Employee& e); //cout

    //functions

     virtual void AddEmpFromKey(std::map<std::string, std::shared_ptr<Employee>>& employees) {}
     virtual void parse(std::string data);
     virtual std::string to_string()const;
     float convertAnnualSalary()const;
};
#endif
