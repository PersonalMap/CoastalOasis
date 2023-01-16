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
    Person(std::string, std::string, unsigned int);
    ~Person();

    //getters & setters
    const std::string& getName(){return this->_name;}
    const std::string& getPhone(){return this->_phoneNumber;}
    const unsigned int& getAge(){return this->_age;}

    void setName(const std::string& name){this->_name = name;}
    void setPhone(const std::string& phoneNumber){this->_phoneNumber = phoneNumber;}
    void setAge(const unsigned int& age){this->_age = age;}

    //operator functions
       const std::string& debug(){
        _debugStr = "";
        _debugStr = "name: " + _name + "," + std::to_string(_age) +  " phone: " + _phoneNumber;
     return _debugStr;
    }



};

#endif // PERSON_H
