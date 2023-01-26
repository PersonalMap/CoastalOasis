#ifndef COASTALOASIS_MANAGER_H
#define COASTALOASIS_MANAGER_H
#include "employee.h"
#include <algorithm>


class Manager: public Employee{

private:
    std::map<std::string, std::shared_ptr<Employee>> _employeeList;
    std::vector<std::string> _employeeKeys;
public:

    ///*Constructors*/
            //default constructor
            Manager();
    Manager(MyEnums::Department workRole, const HTime& employeeDate, float salary,
            unsigned int accessLevel,std::string name, std::string phone, unsigned int age);

            //employee list ,  constructor
    Manager(const std::map<std::string, std::shared_ptr<Employee>> employeeList, MyEnums::Department workRole,
            const HTime& employeeDate, float salary, unsigned int accessLevel,
            std::string name, std::string phone, unsigned int age);

            //employee list + finished schedule , constructor
    Manager(  const WeeklySchedule& _schedule,std::map<std::string, std::shared_ptr<Employee>> employeeList,
             MyEnums::Department workRole, const HTime& employeeDate, float salary,
             unsigned int accessLevel,std::string name, std::string phone, unsigned int age);

    ~Manager();

        ///* GETTERS & SETTERS*/

        const std::map<std::string, std::shared_ptr<Employee>>& getEmployeeMap() const{return this->_employeeList;}
        std::map<std::string, std::shared_ptr<Employee>>& getEmployeeListP(){return this->_employeeList;}
        int getNumberOfEmployees()const{return (int)this->_employeeList.size();}

        ///operator
        friend std::ostream& operator<<(std::ostream& os, const Manager& e);

        ///* FUNCTIONS */
        void addEmployee(const std::string& key, std::shared_ptr<Employee> employee);
        void removeEmployee(const std::string& key);
        void AddEmpFromKey(std::map<std::string, std::shared_ptr<Employee>>& employees)override;

        void parse(std::string data) override;
        std::string to_string() const override;
};


#endif //COASTALOASIS_MANAGER_H
