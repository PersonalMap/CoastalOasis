#ifndef USER_H
#define USER_H
#include <string>
#include "../person.h"

class User: public Person
{

private:
    std::string _advanceDebugStr;
    std::string _mejl;
    std::string _password;
    /* ADD VECTOR WITH BOOKINGS*/

public:

    //constructor
    User(std::string password,std::string mejl, std::string name, std::string phone, unsigned int age):
        Person(name, phone,age),_password(password) ,_mejl(mejl){}
    ~User();

    // getter & setter

    const std::string& getMejl(){return this->_mejl;}
    const std::string& getPassword(){return this->_password;}

    void setMejl(const std::string& newMejl){this->_mejl = newMejl;}
    void setPassword(const std::string& newPassword){this->_password = newPassword;}

    // functions

    std::string advancedDebug()
    {
        _advanceDebugStr = "";
        _advanceDebugStr = _name + ", " + std::to_string(_age)
              +  "\n Mejl: " + _mejl
              + "\n Telefon " + _phoneNumber
              + "\n Password" + _password;
        return  _advanceDebugStr;

    }
};

#endif // USER_H
