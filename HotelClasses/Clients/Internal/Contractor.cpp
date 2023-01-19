#include "Contractor.h"
///Constructor

//default
Contractor::Contractor(MyEnums::Department workRole,const HTime& employeDate, float salary,
                        unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                            :Employee(workRole, employeDate, salary, acessLevel,std::move(name),
                      std::move(phone), age),
                      _endDate(HTime(2000, 10, 10, 10, 10)){};

//init with hour salary
Contractor::Contractor(const HTime& endDate, MyEnums::Department workRole,const HTime& employeeDate, float salary,
                       unsigned int accessLevel, std::string name, std::string phone, unsigned int age)
                        :Employee(workRole, employeeDate, salary, accessLevel,
                      std::move(name), std::move(phone), age),_endDate(endDate){};

Contractor::~Contractor()=default;
///functions
