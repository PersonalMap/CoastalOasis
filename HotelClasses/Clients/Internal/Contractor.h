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
    Contractor(MyEnums::Department workRole, std::string employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    //init with hour salary
    Contractor(HTime, MyEnums::Department workRole, std::string employeDate, float salary,
               unsigned int acessLevel, std::string name, std::string phone, unsigned int age);
    ~Contractor(){};

    ///Getters & Setters
    const HTime& getEndDate()const{return this->_endDate;};
    void setEndDate(const HTime& endDate){ this->_endDate = endDate;};



};
#endif