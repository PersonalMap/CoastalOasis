#include "Hourly.h"

///Constructor
//default
Hourly::Hourly(){};
Hourly::Hourly(MyEnums::Department workRole, const HTime& employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(MyEnums::WorkPosition::Hourly ,workRole, employeDate, salary, acessLevel,std::move(name),std::move(phone),std::move(age)),
         _hourSalary(0), _hoursWorked(0){}
//init with hour salary
Hourly::Hourly(unsigned int hourSalary, MyEnums::Department workRole,const HTime& employeDate, float salary,
               unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
        :Employee(MyEnums::WorkPosition::Hourly,workRole, employeDate, salary, acessLevel, std::move(name),std::move(phone), std::move(age)),
         _hourSalary(hourSalary), _hoursWorked(0){}
Hourly::~Hourly()=default;

///Operators

///Functions

unsigned int Hourly::calculateSalary() const
{
    return this->_hoursWorked * this->_hourSalary;
}


void Hourly::parse(const std::string& data) {
    std::vector<std::string> parts = Utilities::split(data, ':');
    if (parts.size() != 9) {
        std::cout << "wrong amount of words!" << parts.size() << " meanwhile 9 was expected";
        throw std::runtime_error("");
    }
    _hourSalary = std::stoi(parts[1]);
    _hoursWorked = std::stoi(parts[2]);
    std::stringstream ss;
    for (auto i = parts.begin() + 3; i != parts.end(); ++i) {
        ss << *i;
        if (i + 1 != parts.end()) {
            ss << ":";
        }
    }
    Employee::parse(ss.str());
}

std::string Hourly::to_string() const {
    std::stringstream ss;
    ss << "Hourly:" << _hourSalary << ":" << _hoursWorked << ":" << Employee::to_string();
    return ss.str();
}
