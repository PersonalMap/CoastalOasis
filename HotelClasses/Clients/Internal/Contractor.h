#ifndef COASTALOASIS_CONTRACTOR_H
#define COASTALOASIS_CONTRACTOR_H
#include "employee.h"
#include "HTime.h"

class Contractor: public Employee{

private:
    HTime _endDate; // yyyymmdd hhmm

public:
    ///Constructor
    //default
    Contractor();
    Contractor(MyEnums::Department workRole,const HTime& employeDate, float salary,
                   unsigned int accessLevel,std::string name, std::string phone, unsigned int age);

    //init with hour salary
    Contractor(const HTime&, MyEnums::Department workRole,const HTime& employeeDate, float salary,
               unsigned int accessLevel, std::string name, std::string phone, unsigned int age);
    ~Contractor();

    ///Getters & Setters
    const HTime& getEndDate()const{return this->_endDate;};
    void setEndDate(const HTime& endDate){ this->_endDate = endDate;};

    //functions

    void parse(std::string data);
    std::string to_string();


};
#endif
