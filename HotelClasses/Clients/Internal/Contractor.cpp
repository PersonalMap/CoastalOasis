#include "Contractor.h"
///Constructor

//default
Contractor::Contractor(){};
Contractor::Contractor(std::string email, std::string password,MyEnums::Department workRole,const HTime& employeDate, float salary,
                        unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                            :Employee(std::move(email), std::move(password),MyEnums::WorkPosition::Contractor,workRole, employeDate, salary, acessLevel,std::move(name),
                      std::move(phone), age),
                      _endDate(HTime(2000, 10, 10, 10, 10)){};

//init with hour salary
Contractor::Contractor(const HTime& endDate,std::string email, std::string password, MyEnums::Department workRole,const HTime& employeeDate, float salary,
                       unsigned int accessLevel, std::string name, std::string phone, unsigned int age)
                        :Employee(std::move(email), std::move(password),MyEnums::WorkPosition::Contractor,workRole, employeeDate, salary, accessLevel,
                      std::move(name), std::move(phone), age),_endDate(endDate){};

Contractor::~Contractor()=default;
///functions

void Contractor::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    if (parts.size() != 11) {
        std::cout << "wrong amount of words!" << parts.size() << " meanwhile 9 was expected";
        throw std::runtime_error("");
    }
    _endDate = HTime(parts[1]);

    //grabbing the rest of the parts to parse them with employee, using string stream
    std::stringstream ss;
    for (auto i = parts.begin() + 2; i != parts.end(); ++i) {
        ss << *i;
        if (i + 1 != parts.end()) {
            ss << ":";
        }
    }
    Employee::parse(ss.str());
}


std::string Contractor::to_string() const
{
    std::stringstream ss;
    ss << _endDate.getRawFullDateString() << ":" << Employee::to_string();
    return ss.str();
}


