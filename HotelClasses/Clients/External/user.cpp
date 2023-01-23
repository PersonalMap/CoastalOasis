#include "user.h"

///* Constructor*/
User::User(){}
User::User(std::string password,std::string mail, std::string name, std::string phone, unsigned int age):
Person(name, phone,age),_password(password) ,_mail(mail){}

User::~User(){}

///* Operators */

///* Functions */

std::string User::advancedDebug()
{
    _advanceDebugStr = "";
    _advanceDebugStr = _name + ", " + std::to_string(_age)
                       + "\n Mail: " + _mail
                       + "\n Phone " + _phoneNumber
                       + "\n Password" + _password;
    return  _advanceDebugStr;

}


void User::parse(std::string data)
{
    std::vector<std::string> parts = Utilities::split(data, ':');
    _password = parts[0];
    _mail = parts[1];
    _name = parts[2];
    _phoneNumber = parts[3];
    _age = std::stoi(parts[4]);
}

std::string User::to_string()const
{
    return _password + ":" + _mail + ":" + _name + ":" + _phoneNumber + ":" + std::to_string(_age);
}