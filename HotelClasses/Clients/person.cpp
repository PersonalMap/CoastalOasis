#include "person.h"

///Constructor
Person::Person(){};
Person::Person(std::string name, std::string phone, unsigned int age): _name(name), _phoneNumber(phone), _age(age){}
Person::~Person(){}

///Operators

///Functions

const std::string& Person::debug(){
    _debugStr = "";
    _debugStr = "name: " + _name + "," + std::to_string(_age) +  " phone: " + _phoneNumber;
    return _debugStr;
}

