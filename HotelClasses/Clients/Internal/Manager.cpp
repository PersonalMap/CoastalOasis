#include "Manager.h"

///*Constructors*/

//default
Manager::Manager()= default;
Manager::Manager(std::string email, std::string password,MyEnums::Department workRole,const HTime& employeeDate, float salary,
                 unsigned int accessLevel,std::string name, std::string phone, unsigned int age)
                       :Employee(std::move(email), std::move(password), MyEnums::WorkPosition::Manager, workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age){}

//employee list
Manager::Manager(std::map<std::string,std::shared_ptr<Employee>> employeeList,std::string email, std::string password,  MyEnums::Department workRole,
                 const HTime& employeeDate, float salary, unsigned int accessLevel,
                 std::string name, std::string phone, unsigned int age)
                     :Employee(std::move(email), std::move(password),MyEnums::WorkPosition::Manager,workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age),
                     _employeeList(std::move(employeeList)){}

//employee list + finished schedule
Manager::Manager( const WeeklySchedule& _schedule,std::map<std::string, std::shared_ptr<Employee>> employeeList,
                  std::string email, std::string password,MyEnums::Department workRole, const HTime& employeeDate, float salary,
                  unsigned int accessLevel,std::string name, std::string phone, unsigned int age)
                  :Employee(std::move(email), std::move(password),MyEnums::WorkPosition::Manager, workRole, employeeDate, salary, accessLevel, std::move(name),std::move(phone), age),
                  _employeeList(std::move(employeeList))
                        {
                                this->_schedule = _schedule;
                        }

    Manager::~Manager()=default;


///functions

void Manager::addEmployee(const std::string& key, std::shared_ptr<Employee> employee) {
    _employeeList.insert(std::make_pair(key,std::shared_ptr<Employee>(employee.get())));
}

void Manager::removeEmployee(const std::string& key) {
    _employeeList.erase(key);
}


void Manager::AddEmpFromKey(std::map<std::string, std::shared_ptr<Employee>>& employees) {
    _employeeList.clear();
    for(const auto& string : _employeeKeys) {
        try {
            _employeeList.insert(std::make_pair(string, std::weak_ptr<Employee>(employees.at(string))));
        } catch (std::out_of_range& e) {
            std::cerr << "Error: employee with key " << string << " not found in employees map" << std::endl;
        }
    }
}

void Manager::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    _employeeKeys.clear();
    for(unsigned int i = 1; i < parts.size()-9; i++) {
       _employeeKeys.push_back(parts[i]);
    }

    //grabbing the rest of the parts to parse them with employee, using string stream
    std::stringstream ss;
    for (auto i = parts.begin() + parts.size()-9; i != parts.end(); ++i) {
        ss << *i;
        if (i + 1 != parts.end()) {
            ss << ":";
        }
    }
    Employee::parse(ss.str());
}
std::string Manager::to_string() const {
    std::string employees;
    for (const auto& [key, value] : _employeeList) {
        employees += key + ":";
    }
    return employees + Employee::to_string();
}


///operator

std::ostream& operator<<(std::ostream& os, const Manager& e) {

    std::string employeeNames;
    for (const auto& [key, employee] : e._employeeList) {
        employeeNames += employee->getName() + ", ";
    }

    return os << e._name << ", " << e._age << "(" << MyEnums::departmentMap[e._workRole] << ")\n"
              << "AnnualSalary: " << e.convertAnnualSalary() << "$\n"
              << "Phone: " << e._phoneNumber << "\t" << "$\n"
              << "Boss for :" << employeeNames <<std::endl;
}