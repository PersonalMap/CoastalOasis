#ifndef COASTALOASIS_READ_H
#define COASTALOASIS_READ_H
#include <fstream>
#include <string>
#include <map>
#include "user.h"
#include "employee.h"
#include "Room.h"

class Read {

    std::string EmployeeFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Employees.txt";
    std::string UserFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Users.txt";
    std::string RoomFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Rooms.txt";
public:
    void readUsers(std::map<std::string, User>& users);
    void readEmployees(std::map<std::string, std::unique_ptr<Employee>>& employees);
    void readRooms(std::map<unsigned int, Room>& rooms);

};
#endif //COASTALOASIS_READ_H
