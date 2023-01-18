#include "Intern.h"


///Constructor
//default
Intern::Intern(MyEnums::Department workRole, std::string employeDate, float salary,
                unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                    :Employee(workRole, employeDate, salary, acessLevel, name, phone, age){};

//create with references
Intern::Intern(std::vector<std::string> references,MyEnums::Department workRole, std::string employeDate, float salary,
                unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                    :Employee(workRole, employeDate, salary, acessLevel, name, phone, age)
                ,_references(references){};

Intern::~Intern(){}
///Operators

///Functions
void Intern::AddReference(const std::string r)
{
    this->_references.push_back(r);
}