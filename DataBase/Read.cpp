#include "Read.h"
#include "Contractor.h"
#include "Hourly.h"
#include "Intern.h"
#include "Manager.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "Suite.h"

void Read::readUsers(std::map<std::string, User>& users) {
    std::ifstream file(UserFilePath);
    std::string line;
    while (std::getline(file, line)) {
        User user;
        user.parse(line);
        users.insert({user.getPhone(), user});
    }
    file.close();
}
void Read::readEmployees(std::map<std::string, Employee>& employees) {
    std::ifstream file(EmployeeFilePath);
    std::string line;
    while (std::getline(file, line)) {
        Employee employee;
        if(line.substr(0,10) == "Contractor")
            employee = Contractor();
        else if(line.substr(0,6) == "Hourly")
            employee = Hourly();
        else if(line.substr(0,6) == "Intern")
            employee = Intern();
        else if(line.substr(0,7) == "Manager")
            employee = Manager();
        employee.parse(line);
        employees.insert({employee.getPhone(), employee});
    }
    file.close();
}



void Read::readRooms(std::map<unsigned int, Room>& rooms) {
    std::ifstream file(RoomFilePath);
    std::string line;
    while (std::getline(file, line)) {
        Room room;
        if(line.substr(0,6) == "Single")
            room = SingleRoom();
        else if(line.substr(0,6) == "Double")
            room = DoubleRoom();
        else if(line.substr(0,6) == "Suite")
            room = Suite();
        room.parse(line);
        rooms.insert({room.getRoomNumber(), room});
    }
    file.close();
}
