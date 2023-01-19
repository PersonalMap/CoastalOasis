#include "Manager.h"

///*Constructors*/

//default
Manager::Manager(MyEnums::Department workRole,const HTime& employeeDate, float salary,
                 unsigned int accessLevel,std::string name, std::string phone, unsigned int age)
                       :Employee(workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age){}

//employee list
Manager::Manager(std::vector<Employee> employeeList, MyEnums::Department workRole,
                 const HTime& employeeDate, float salary, unsigned int accessLevel,
                 std::string name, std::string phone, unsigned int age)
                     :Employee(workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age),
                     _employeeList(std::move(employeeList)){}

//employee list + finished schedule
Manager::Manager( const WeeklySchedule& _schedule,std::vector<Employee> employeeList,
                  MyEnums::Department workRole, const HTime& employeeDate, float salary,
                  unsigned int accessLevel,std::string name, std::string phone, unsigned int age)
                  :Employee(workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age),
                  _employeeList(std::move(employeeList))
                        {
                                this->_schedule = _schedule;
                        }

    Manager::~Manager()=default;


///functions

void Manager::addEmployee(const Employee& employee){_employeeList.push_back(employee);}
void Manager::removeEmployee(const Employee& employee)
{
    auto it = std::find(_employeeList.begin(), _employeeList.end(), employee);

}