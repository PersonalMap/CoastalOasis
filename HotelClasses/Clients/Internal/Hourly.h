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
    Hourly();
    //default
    Hourly(std::string email, std::string password,MyEnums::Department workRole, const HTime& employeDate, float salary,
    unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    //init with hour salary
    Hourly(unsigned int hourSalary, std::string email, std::string password,MyEnums::Department workRole,const HTime& employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    ~Hourly();

    ///getters & setters

    const unsigned int& getHoursWorked()const{return _hoursWorked;}
    const unsigned int& getHourSalary()const{return _hourSalary;}
    unsigned int getCalculatedSalary()const{return calculateSalary();}

    void setHoursWorked(const unsigned int& hoursWorked){this->_hoursWorked = hoursWorked;}
    void setHourSalary(const unsigned int& hourSalary){this->_hourSalary = hourSalary;}

    ///functions
    void addHour(){_hoursWorked++;}
    void addHours(const unsigned int& h){this->_hoursWorked += h;}
    void subtractHour(){_hoursWorked--;}
    void subtractHours(const unsigned int& h){this->_hoursWorked -= h;}

    void parse(const std::string& data);
    std::string to_string() const;
};


#endif
