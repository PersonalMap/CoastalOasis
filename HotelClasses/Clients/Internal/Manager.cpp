#include <algorithm>
#include "Manager.h"

///*Constructors*/

//default
Manager::Manager(MyEnums::Department workRole, std::string employeDate, float salary,
                 unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                       :Employee(workRole, employeDate, salary, acessLevel, name, phone, age){}

//employee list
Manager::Manager(std::vector<Employee> employeeList, MyEnums::Department workRole,
                 std::string employeDate, float salary, unsigned int acessLevel,
                 std::string name, std::string phone, unsigned int age)
                     :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
                     _employeeList(employeeList){}

//employee list + finished schedule
Manager::Manager( WeeklySchedule _schedule,std::vector<Employee> employeeList,
                  MyEnums::Department workRole, std::string employeDate, float salary,
                  unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                  :Employee(workRole, employeDate, salary, acessLevel, name, phone, age),
                  _employeeList(employeeList)
                        {
                                this->_schedule = _schedule;
                        }

    Manager::~Manager(){}

///operators

bool Manager::operator==(const Employee& other)
{
    return (this->_phoneNumber == other.getPhone());
}

///functions

void Manager::addEmployee(Employee employee){_employeeList.push_back(employee);}
void Manager::removeEmployee(const Employee& employee)
{
    auto it = std::find(_employeeList.begin(), _employeeList.end(), employee);

}