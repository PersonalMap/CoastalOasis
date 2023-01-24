#ifndef COASTALOASIS_WRITE_H
#define COASTALOASIS_WRITE_H

#include <fstream>
#include <string>
#include <map>
#include <libgen.h>
#include <filesystem>

#include "user.h"
#include "employee.h"
#include "Contractor.h"
#include "Hourly.h"
#include "Manager.h"
#include "Intern.h"
#include "Room.h"
#include "HotelEnums.h"

class Write {
private:

    std::string EmployeeFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Employees.txt";
    std::string UserFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Users.txt";
    std::string RoomFilePath = "/Users/vango/CLionProjects/CoastalOasis/DataBase/Data/Rooms.txt";

public:
    void writeUsers(const std::map<std::string, User>& users);
    void writeRooms(const std::map<unsigned int, Room>& rooms);

    template <typename T>
    std::string writeEmployee(const T& employee) {
        std::string keyWord = getKeyWord(employee);
        if (typeid(employee) == typeid(Contractor)) {
            const Contractor& c = dynamic_cast<const Contractor&>(employee);
            return keyWord + ":" + c.to_string();
        } else {
            return keyWord + ":" + employee.to_string();
        }
    }

    void writeEmployees(const std::map<std::string, std::unique_ptr<Employee>>& employees);


    std::string getKeyWord(const Employee& employee)const;
    std::string getRoomKeyWord(const Room& room);

};
#endif //COASTALOASIS_WRITE_H
