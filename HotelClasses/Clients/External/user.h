#ifndef USER_H
#define USER_H
#include "../person.h"
#include "Utilities.h"

class User: public Person
{

private:
    std::string _advanceDebugStr;
    std::string _mail;
    std::string _password;
    /* ADD VECTOR WITH BOOKINGS*/

public:

    ///constructor
    User();
    User(std::string password,std::string mail, std::string name, std::string phone, unsigned int age);
    ~User();

    /// getter & setter
    const std::string& getMail()const{return this->_mail;}
    const std::string& getPassword()const{return this->_password;}

    void setMail(const std::string& newMail){ this->_mail = newMail;}
    void setPassword(const std::string& newPassword){this->_password = newPassword;}

    ///operator
    bool operator==(const User& rhs) const {
        return this->_mail == rhs.getMail() && this->_password == rhs.getPassword();
    }


    /// functions
    std::string advancedDebug();

    void parse(std::string data);
    std::string to_string()const;
};

#endif
