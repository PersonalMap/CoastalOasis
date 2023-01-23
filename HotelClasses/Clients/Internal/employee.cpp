#include "employee.h"

///* CONSTRUCTORS */
Employee::Employee(){};
Employee::Employee(MyEnums::Department workRole, const HTime& employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone,unsigned int age)
                        :Person(std::move(name), std::move(phone), std::move(age)),_workRole(workRole)
                        ,_employmentDate(employeDate), _salary(salary), _acessLevel(acessLevel)
                    {
                        _advancedDebugStr = "";
                    }

Employee::~Employee()=default;

///*OPERATORS*/

std::ostream& operator<<(std::ostream& os, Employee& e) // cout
{
return os << e._name << ", " << e._age << "(" << MyEnums::departmentMap[e._workRole] << ")\n"
<< "AnnualSalary: " << e.convertAnnualSalary() << "$\n"
<< "Phone: " << e._phoneNumber << "\t" << std::endl;
}

///*FUNCTIONS*/

float Employee::convertAnnualSalary(){{return 12*_salary;}}


void Employee::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    _workRole = static_cast<MyEnums::Department>(std::stoi(parts[0]));
    _employmentDate = HTime(parts[1]);
    _salary = std::stof(parts[2]);
    _acessLevel = std::stoi(parts[3]);
    _name = parts[4];
    _phoneNumber = std::stoi(parts[5]);
    _age = std::stoi(parts[6]);
};
std::string Employee::to_string()const
{
    std::stringstream ss;
    ss << static_cast<int>(_workRole) << ":" << _employmentDate.getRawFullDateString() <<
    ":" << _salary << ":" << _acessLevel << ":" << _name << ":" << _phoneNumber << ":" << _age;
    return ss.str();

};
