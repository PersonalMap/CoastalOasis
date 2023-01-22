#ifndef COASTALOASIS_HOTELL_H
#define COASTALOASIS_HOTELL_H

#include <map>
#include <string>
#include <algorithm>

#include "../DataBase/Read.h"
#include "../DataBase/Write.h"

#include "user.h"
#include "employee.h"
#include "Room.h"
class Hotel {

private:

     bool _isEmployee;

     std::string _userKey;
     std::string _employeeKey;
     unsigned int _roomKey;

     std::map<std::string, User> _users; //phone
     std::map<std::string, Employee> _employees; //phone
     std::map<unsigned int, Room> _rooms; //room number

public:
    ///Constructors

    Hotel();
    ~Hotel();

    ///getters & setters

    //maps
    const User& getUser()const{return _users.at(this->_userKey);}
    const User& getUser(const std::string& userKey)const{return _users.at(userKey);}
    const Employee& getEmployee()const{return _employees.at(this->_employeeKey);}
    const Employee& getEmployee(const std::string& employeeKey)const{return _employees.at(employeeKey);}
    const Room& getRoom()const{return _rooms.at(this->_roomKey);}
    const Room& getRoom(unsigned int key)const{return this->_rooms.at(key);}
    //keys & loginType
    const bool& getIsEmployee()const{return this->_isEmployee;}
    const std::string& getCurrentUserKey()const{return this->_userKey;}
    const std::string& getCurrentEmployeeKey()const{return this->_employeeKey;}
    const unsigned int& getCurrentRoomKey()const{return this->_roomKey;}


    //keys
    void setActiveUserByObject(const User& user){this->_userKey = getUserKey(user);}
    void setActiveUserByPhone(const std::string& phoneNumber){this-> _userKey = getUserKeyByPhone(phoneNumber);}
    void setActiveEmployeeByObject(const Employee& employee){this->_employeeKey = getEmployeeKey(employee);}
    void setActiveEmployeeByPhone(const std::string& phoneNumber){this->_employeeKey = getEmployeeKeyByPhone(phoneNumber);}
    void setActiveRoomByObject(const Room& room){this->_roomKey = getRoomKey(room);}


    ///functions
    std::string getUserKey(const User& user); //get matching key
    std::string getUserKeyByPhone(const std::string& phoneNumber);//get matching key by phone
    std::string getEmployeeKey(const Employee& employee); //get matching key
    std::string getEmployeeKeyByPhone(const std::string& phoneNumber);//get matching key by phone
    unsigned int getRoomKey(const Room& room);

    //Add
    void addUser(User& user);
    void addEmployee(Employee& employee);
    void addRoom(Room& room);
    //delete
    void removeUser(User& user);
    void removeEmployee(Employee& employee);
    void removeRoom(Room& room);


};
#endif //COASTALOASIS_HOTELL_H
