#include "user.h"

///* Constructor*/

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