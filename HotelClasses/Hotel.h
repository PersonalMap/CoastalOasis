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
#include "Write.h"
class Hotel {

private:

     bool _isEmployee;

     std::string _userKey;
     std::string _employeeKey;
     unsigned int _roomKey;
     Write _write;
     Read _read;

     std::map<std::string, std::unique_ptr<User>> _users; //phone
     std::map<std::string, std::unique_ptr<Employee>> _employees;

    std::map<unsigned int, std::unique_ptr<Room>> _rooms; //room number


public:
    ///Constructors

    Hotel();
    ~Hotel();

    ///getters & setters

    //maps
    const std::unique_ptr<User>& getUser()const{return _users.at(this->_userKey);}
    const std::unique_ptr<User>& getUser(const std::string& userKey)const{return _users.at(userKey);}
    const std::unique_ptr<Employee>& getEmployee()const{return _employees.at(this->_employeeKey);}
    const std::unique_ptr<Employee>& getEmployee(const std::string& employeeKey)const{return _employees.at(employeeKey);}
    const std::unique_ptr<Room>& getRoom()const{return _rooms.at(this->_roomKey);}
    const std::unique_ptr<Room>& getRoom(unsigned int key)const{return this->_rooms.at(key);}
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
    void readInHotel();
    void writeHotel();
    //Add
    void addUser(std::unique_ptr<User> user);
    void addEmployee(std::unique_ptr<Employee> employee);
    void addRoom(std::unique_ptr<Room> room);
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
