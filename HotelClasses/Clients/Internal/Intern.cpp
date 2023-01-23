#include "Intern.h"


///Constructor
//default
Intern::Intern(){};
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


void Intern::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    _references.clear();
    for(unsigned int i=1;i<parts.size()-7;i++)
    {
        _references.push_back(parts[i]);
    }
    Employee::parse(parts[parts.size()-7]);
}
std::string Intern::to_string()
{
    std::string ref = "";
    for(unsigned int i=0;i<_references.size();i++)
    {
        ref += _references[i] + ":";
    }
    return "Intern:" + ref + Employee::to_string();
}