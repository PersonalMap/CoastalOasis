#ifndef COASTALOASIS_MANAGER_H
#define COASTALOASIS_MANAGER_H
#include "employee.h"
#include <algorithm>


class Manager: public Employee{

private:
    std::vector<Employee> _employeeList;
public:

    ///*Constructors*/
            //default constructor
    Manager(MyEnums::Department workRole, std::string employeDate, float salary,
            unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

            //employee list ,  constructor
    Manager(std::vector<Employee> employeeList, MyEnums::Department workRole,
            std::string employeDate, float salary, unsigned int acessLevel,
            std::string name, std::string phone, unsigned int age);

            //employee list + finished schedule , constructor
    Manager( WeeklySchedule _schedule,std::vector<Employee> employeeList,
             MyEnums::Department workRole, std::string employeDate, float salary,
             unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    ~Manager();

        ///* GETTERS & SETTERS*/
        const std::vector<Employee>& getEmployeeList()const {return this->_employeeList;}
        std::vector<Employee>& getEmployeeListP(){return this->_employeeList;}
        const int getNumberOfemployees(){return this->_employeeList.size();}

        ///* OPERATORS */
        bool operator==(const Employee& employee);

        ///* FUNCTIONS */
        void addEmployee(Employee employee);
        void removeEmployee(const Employee& employee);

};


#endif //COASTALOASIS_MANAGER_H
