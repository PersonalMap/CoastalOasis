#include "employee.h"

///* CONSTRUCTORS */
Employee::Employee(std::string email, std::string password,MyEnums::WorkPosition position,MyEnums::Department workRole, const HTime& employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone,unsigned int age)
                        :Person(std::move(name), std::move(phone), std::move(age)),_workRole(workRole)
                        ,_employmentDate(employeDate), _salary(salary), _acessLevel(acessLevel), _position(position), _email(email), _password(password)
                    {
                        _advancedDebugStr = "";
                    }


///*OPERATORS*/

std::ostream& operator<<(std::ostream& os, const Employee& e) {
    return os << e._name << ", " << e._age << "(" << MyEnums::departmentMap[e._workRole] << ")\n"
              << "AnnualSalary: " << e.convertAnnualSalary() << "$\n"
              << "Phone: " << e._phoneNumber << "\t" << std::endl;
}


///*FUNCTIONS*/

float Employee::convertAnnualSalary()const{{return 12*_salary;}}


void Employee::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    try {
        _email = parts[0];
        _password = parts[1];
        _workRole = static_cast<MyEnums::Department>(std::stoi(parts[2]));
        _employmentDate = HTime(parts[3]);
        _salary = std::stof(parts[4]);
        _acessLevel = std::stoi(parts[5]);
        _name = parts[6];
        _phoneNumber = (parts[7]);
        _age = std::stoi(parts[8]);
    } catch (const std::exception& e) {
        std::cout << "Error: Invalid data format: " << e.what() << std::endl;
    }
}
std::string Employee::to_string() const {
    std::stringstream ss;
    ss << _email << ":" << _password << ":" << _workRole << ":" <<
    _employmentDate.getRawFullDateString() << ":" << _salary << ":" << _acessLevel <<
    ":" << _name << ":"<< _phoneNumber << ":"<< _age;
    return ss.str();
}

