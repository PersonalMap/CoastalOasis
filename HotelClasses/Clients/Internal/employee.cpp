#include "employee.h"

///* CONSTRUCTORS */

Employee::Employee(MyEnums::Department workRole, std::string employeDate, float salary,
                   unsigned int acessLevel,std::string name, std::string phone,unsigned int age)
                        :Person(name, phone, age),_workRole(workRole),_employmentDate(employeDate),
                    _salary(salary), _acessLevel(acessLevel)
                    {
                        _advancedDebugStr = "";
                    }

Employee::~Employee(){};

///*OPERATORS*/

bool Employee::operator==(const Employee& other) // == operator
{
    return(this->_phoneNumber == other._phoneNumber);
}

std::ostream& operator<<(std::ostream& os, Employee& e) // cout
{
return os << e._name << ", " << e._age << "(" << MyEnums::departmentMap[e._workRole] << ")\n"
<< "AnnualSalary: " << e.convertAnnualSalary() << "$\n"
<< "Phone: " << e._phoneNumber << "\t" << std::endl;
}

///*FUNCTIONS*/

float Employee::convertAnnualSalary(){{return 12*_salary;}}


