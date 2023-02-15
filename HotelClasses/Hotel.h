#ifndef COASTALOASIS_HOTELL_H
#define COASTALOASIS_HOTELL_H

#include <map>
#include <string>
#include <algorithm>

#include "../DataBase/Read.h"
#include "../DataBase/Write.h"
#include "FrameSwitcher.h"

#include "user.h"
#include "employee.h"
#include "Room.h"
#include "Write.h"

class Hotel {

private:

     bool _isEmployee;
     bool _isUser;

     FrameSwitcher* frameSwitcher;
     std::string _userKey;
     std::string _employeeKey;
     unsigned int _roomKey;
     Write _write;
     Read _read;

     std::map<std::string, std::shared_ptr<User>> _users; //phone
     std::map<std::string, std::shared_ptr<Employee>> _employees;

    std::map<unsigned int, std::shared_ptr<Room>> _rooms; //room number


public:
    ///Constructors
    Hotel();
    ~Hotel();

    ///getters & setters

    //maps
    const std::shared_ptr<User>& getUser()const{return _users.at(this->_userKey);}
    const std::shared_ptr<User>& getUser(const std::string& userKey)const{return _users.at(userKey);}
    bool getIsUser()const{return this->_isUser;}
    const std::shared_ptr<Employee>& getEmployee()const{return _employees.at(this->_employeeKey);}
    const std::shared_ptr<Employee>& getEmployee(const std::string& employeeKey)const{return _employees.at(employeeKey);}
    bool getIsEmployee()const{return this->_isEmployee;}
    const std::shared_ptr<Room>& getRoom()const{return _rooms.at(this->_roomKey);}
    const std::shared_ptr<Room>& getRoom(unsigned int key)const{return this->_rooms.at(key);}
    //keys & loginType
    const std::string& getCurrentUserKey()const{return this->_userKey;}
    const std::string& getCurrentEmployeeKey()const{return this->_employeeKey;}
    const unsigned int& getCurrentRoomKey()const{return this->_roomKey;}

    FrameSwitcher* getFrameSwitcher(){return this->frameSwitcher;}

    //keys
    void setActiveUserByObject(const User& user){this->_userKey = getUserKey(user);}
    void setActiveUserByPhone(const std::string& phoneNumber){this-> _userKey = getUserKeyByPhone(phoneNumber);}
    void setActiveEmployeeByObject(const Employee& employee){this->_employeeKey = getEmployeeKey(employee);}
    void setActiveEmployeeByPhone(const std::string& phoneNumber){this->_employeeKey = getEmployeeKeyByPhone(phoneNumber);}
    void setActiveRoomByObject(const Room& room){this->_roomKey = getRoomKey(room);}
    void setIsEmployee(const bool& isemployee){this->_isEmployee = isemployee;}
    void setIsUser(const bool& isuser){this->_isUser = isuser;}

    ///functions
    std::string getUserKey(const User& user); //get matching key
    std::string getUserKeyByPhone(const std::string& phoneNumber);//get matching key by phone
    std::string getEmployeeKey(const Employee& employee); //get matching key
    std::string getEmployeeKeyByPhone(const std::string& phoneNumber);//get matching key by phone
    unsigned int getRoomKey(const Room& room);
    void readInHotel();
    void writeHotel();
    bool hasUser(const std::string& phoneNumber) const {
        return _users.find(phoneNumber) != _users.end();
    }

    bool hasEmployee(const std::string& phoneNumber) const {
        return _employees.find(phoneNumber) != _employees.end();
    }

    //Add
    void addUser(User& user);
    void addEmployee(Employee& employee);
    void addRoom(Room& room);
    //delete
    void removeUser(User& user);
    void removeEmployee(Employee& employee);
    void removeRoom(Room& room);

    //debug
    void printEmployees();
    void printUsers();
    void printRooms();

};
#endif //COASTALOASIS_HOTELL_H
