#ifndef COASTALOASIS_CONTRACTOR_H
#define COASTALOASIS_CONTRACTOR_H
#include "employee.h"
#include "GlobalFunctions.h"

class Contractor: public Employee{

private:
    std::string _endDate; // yyyymmdd hhmm

public:
    ///Constructor
    //default
    Contractor(MyEnums::Department workRole, std::string employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    //init with hour salary
    Contractor(std::string endDate, MyEnums::Department workRole, std::string employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone, unsigned int age);
    ~Contractor();

    ///Getters & Setters
    const std::string& getEndDate()const{return this->_endDate;}
    const std::string getTimeLeft()const
    {return myGlobalFunctions::subtractTime(myGlobalFunctions::getCurrentDateTime(), _endDate);}

    void setEndDate(const std::string& endDate){this->_endDate = endDate;}



};
#endif
