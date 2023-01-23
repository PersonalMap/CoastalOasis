#include "Manager.h"

///*Constructors*/

//default
Manager::Manager(){};
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


void Manager::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    _employeeList.clear();
    for(unsigned int i = 1; i < parts.size()-7; i++) {
        Employee employee;
        employee.parse(parts[i]);
        _employeeList.push_back(employee);
    }
    Employee::parse(parts[parts.size()-7]);
}
std::string Manager::to_string()const
{
    std::string employees = "";
    for(unsigned int i = 0; i < _employeeList.size(); i++) {
        employees += _employeeList[i].to_string() + ":";
    }
    return "Manager:" + employees + Employee::to_string();
}