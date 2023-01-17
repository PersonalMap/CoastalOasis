#ifndef PERSON_H
#define PERSON_H
#include <string>

class Person
{
 private:
    std::string _debugStr;

 protected:
    std::string _name;
    std::string _phoneNumber;
    unsigned int _age;

 public:
    ///constructors
    Person(std::string, std::string, unsigned int);
    ~Person();

    ///getters & setters
    const std::string& getName()const{return this->_name;}
    const std::string& getPhone()const{return this->_phoneNumber;}
    const unsigned int& getAge()const{return this->_age;}

    void setName(const std::string& name){this->_name = name;}
    void setPhone(const std::string& phoneNumber){this->_phoneNumber = phoneNumber;}
    void setAge(const unsigned int& age){this->_age = age;}

    ///operator functions
    const std::string& debug();



};

#endif // PERSON_H
