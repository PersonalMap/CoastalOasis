#ifndef COASTALOASIS_WRITE_H
#define COASTALOASIS_WRITE_H

#include <fstream>
#include <string>
#include <map>

#include "user.h"
#include "employee.h"
#include "Room.h"
class Write {
public:
    void writeUsers(const std::map<std::string, User>& users, const std::string& fileName);
    void writeEmployees(const std::map<std::string, Employee>& employees, const std::string& fileName);
    void writeRooms(const std::map<unsigned int, Room>& rooms, const std::string& fileName);

};
#endif //COASTALOASIS_WRITE_H
