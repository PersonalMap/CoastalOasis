
#include "Read.h"
#include "Contractor.h"
#include "Hourly.h"
#include "Intern.h"
#include "Manager.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "Suite.h"

void Read::readUsers(std::map<std::string, std::unique_ptr<User>>& users) {
    std::ifstream file(UserFilePath);
    std::string line;
    while (std::getline(file, line)) {
        User user;
        user.parse(line);
        std::unique_ptr<User> user_ptr = std::make_unique<User>(std::move(user));
        users.emplace(user_ptr->getPhone(), std::move(user_ptr)); //flytta smartptr av user till users

    }
    file.close();
}
void Read::readEmployees(std::map<std::string, std::unique_ptr<Employee>>& employees) {
    std::ifstream file(EmployeeFilePath);
    std::string line;
    while (std::getline(file, line)) {
        if(line.substr(0,10) == "Contractor"){
            auto contractor = std::make_unique<Contractor>();
            contractor->parse(line);
            employees.emplace(contractor->getPhone(),std::move(contractor));
        }
        else if(line.substr(0,6) == "Hourly"){
            auto hourly = std::make_unique<Hourly>();
            hourly->parse(line);
            employees.emplace(hourly->getPhone(),std::move(hourly));
        }
        else if(line.substr(0,6) == "Intern"){
            auto intern = std::make_unique<Intern>();
            intern->parse(line);
            employees.emplace(intern->getPhone(),std::move(intern));
        }
        else if(line.substr(0,7) == "Manager"){
            auto manager = std::make_unique<Manager>();
            manager->parse(line);
            employees.emplace(manager->getPhone(),std::move(manager));
        }
    }
    file.close();
}





void Read::readRooms(std::map<unsigned int, std::unique_ptr<Room>>& rooms) {
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
        rooms.emplace(room.getRoomNumber(), std::make_unique<Room>(std::move(room))); //flytta msart ptr till rooms
    }
    file.close();
}
