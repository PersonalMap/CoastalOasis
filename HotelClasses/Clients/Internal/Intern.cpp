#include "Intern.h"


///Constructor
//default
Intern::Intern(MyEnums::Department workRole, const HTime& employeDate, float salary,
                unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                    :Employee(workRole, employeDate, salary, acessLevel, std::move(name), std::move(phone), std::move(age)){};

//create with references
Intern::Intern(std::vector<std::string> references,MyEnums::Department workRole,const HTime& employeDate, float salary,
                unsigned int acessLevel,std::string name, std::string phone, unsigned int age)
                    :Employee(workRole, employeDate, salary, acessLevel, std::move(name), std::move(phone), std::move(age))
                ,_references(std::move(references)){};

Intern::~Intern()=default;
///Operators

///Functions
void Intern::AddReference(const std::string r)
{
    this->_references.push_back(r);
}