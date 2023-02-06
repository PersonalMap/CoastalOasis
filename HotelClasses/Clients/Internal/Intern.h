#ifndef COASTALOASIS_INTERN_H
#define COASTALOASIS_INTERN_H
#include "employee.h"

class Intern: public Employee{

private:

    std::vector<std::string> _references;


public:

    ///Constructor
    //default
    Intern();
    Intern(std::string email, std::string password,MyEnums::Department workRole, const HTime& employeeDate, float salary,
           unsigned int accessLevel,std::string name, std::string phone, unsigned int age);
    //create with references
    Intern(std::vector<std::string> references,std::string email, std::string password,MyEnums::Department workRole, const HTime& employeeDate, float salary,
           unsigned int accessLevel,std::string name, std::string phone, unsigned int age);

    ~Intern();

    ///Getters & Setters
    const std::vector<std::string>& getReferences()const{ return this->_references;}

    void setReferences(std::vector<std::string> references){this->_references = references;}

    ///Operators

    ///Functions
    void AddReference(const std::string r);

    void parse(std::string data) override;
    virtual std::string to_string() const override;

};


#endif
