#pragma once
#ifndef COASTALOASIS_READ_H
#define COASTALOASIS_READ_H
#include <fstream>
#include <string>
#include <map>
#include "user.h"
#include "employee.h"
#include "Manager.h"
#include "Room.h"

class Read {
private:
    std::vector<std::string> _managers;
    std::string EmployeeFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Employees.txt";
    std::string UserFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Users.txt";
    std::string RoomFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Rooms.txt";
public:
    void readUsers(std::map<std::string, std::shared_ptr<User>>& users);
    void readEmployees(std::map<std::string, std::shared_ptr<Employee>>& employees);
    void readRooms(std::map<unsigned int, std::shared_ptr<Room>>& rooms);

};
#endif //COASTALOASIS_READ_H
