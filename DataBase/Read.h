#ifndef COASTALOASIS_READ_H
#define COASTALOASIS_READ_H
#include <fstream>
#include <string>
#include <map>
#include "user.h"
#include "employee.h"
#include "Room.h"

class Read {

public:
    void readUsers(std::map<std::string, User>& users, const std::string& fileName);
    void readEmployees(std::map<std::string, Employee>& employees, const std::string& fileName);
    void readRooms(std::map<unsigned int, Room>& rooms, const std::string& fileName);

};
#endif //COASTALOASIS_READ_H
