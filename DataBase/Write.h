#pragma once
#ifndef COASTALOASIS_WRITE_H
#define COASTALOASIS_WRITE_H

#include <fstream>
#include <string>
#include <map>
#include <libgen.h>
#include <filesystem>

#include "user.h"
#include "Contractor.h"
#include "Hourly.h"
#include "Manager.h"
#include "Intern.h"
#include "Room.h"

class Write {
private:

    std::string EmployeeFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Employees.txt";
    std::string UserFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Users.txt";
    std::string RoomFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Rooms.txt";

public:
    void writeUsers(const std::map<std::string, std::unique_ptr<User>>& users);
    void writeRooms(const std::map<unsigned int, std::unique_ptr<Room>>& rooms);
    void writeEmployees(const std::map<std::string, std::unique_ptr<Employee>>& employees);

    std::string getKeyWord(const Employee& employee);
    std::string getRoomKeyWord(const Room& room);

};
#endif //COASTALOASIS_WRITE_H
