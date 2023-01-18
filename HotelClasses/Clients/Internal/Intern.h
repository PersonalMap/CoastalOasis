#ifndef COASTALOASIS_INTERN_H
#define COASTALOASIS_INTERN_H
#include "employee.h"

class Intern: public Employee{

private:

    std::vector<std::string> _references;


public:

    ///Constructor
    //default
    Intern(MyEnums::Department workRole, std::string employeDate, float salary,
           unsigned int acessLevel,std::string name, std::string phone, unsigned int age);
    //create with references
    Intern(std::vector<std::string> references,MyEnums::Department workRole, std::string employeDate, float salary,
           unsigned int acessLevel,std::string name, std::string phone, unsigned int age);

    ~Intern();

    ///Getters & Setters
    const std::vector<std::string>& getReferences()const{ return this->_references;}

    void setReferences(std::vector<std::string> references){this->_references = references;}

    ///Operators

    ///Functions
    void AddReference(const std::string r);



};


#endif
