#include "Contractor.h"
///Constructor

//default
Contractor::Contractor(){};
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

void Contractor::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':'); //a function in utilities that splits data string
    _endDate = HTime(parts[1]);
    Employee::parse(parts[2]);
}
std::string Contractor::to_string()
{
    std::stringstream ss;
    ss << "Contractor:" << _endDate.getRawFullDateString() << ":" << Employee::to_string();
    return ss.str();
};