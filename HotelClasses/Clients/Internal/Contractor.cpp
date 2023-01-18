#include "Contractor.h"

///Constructor

//default
Contractor::Contractor(MyEnums::Department workRole, std::string employeDate, float salary,
                        unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                            :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
                        _endDate(_employmentDate){};

//init with hour salary
Contractor::Contractor(std::string endDate, MyEnums::Department workRole, std::string employeDate, float salary,
                        unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                        :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
                             _endDate(endDate){};
                        Contractor::~Contractor(){};

///functions
