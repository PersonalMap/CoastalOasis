
#include "Read.h"
#include "Contractor.h"
#include "Hourly.h"
#include "Intern.h"
#include "Manager.h"
#include "SingleRoom.h"
#include "DoubleRoom.h"
#include "Suite.h"

void Read::readUsers(std::map<std::string, std::shared_ptr<User>>& users) {
    std::ifstream file(UserFilePath);
    std::string line;
    while (std::getline(file, line)) {
        User user;
        user.parse(line);
        std::shared_ptr<User> user_ptr = std::make_shared<User>(std::move(user));
        users.emplace(user_ptr->getPhone(), std::move(user_ptr)); //flytta smartptr av user till users

    }
    file.close();
}
void Read::readEmployees(std::map<std::string, std::shared_ptr<Employee>>& employees) {
    std::ifstream file(EmployeeFilePath);
    std::string line;
    while (std::getline(file, line)) {
        if(line.substr(0,10) == "Contractor"){
            auto contractor = std::make_shared<Contractor>();
            contractor->parse(line);
            employees.emplace(contractor->getPhone(),std::move(contractor));
        }
        else if(line.substr(0,6) == "Hourly"){
            auto hourly = std::make_shared<Hourly>();
            hourly->parse(line);
            employees.emplace(hourly->getPhone(),std::move(hourly));
        }
        else if(line.substr(0,6) == "Intern"){
            auto intern = std::make_shared<Intern>();
            intern->parse(line);
            employees.emplace(intern->getPhone(),std::move(intern));
        }
        else if(line.substr(0,7) == "Manager"){
            auto manager = std::make_shared<Manager>();
            manager->parse(line);
            employees.emplace(manager->getPhone(),std::make_shared<Manager>(*manager));
            _managers.push_back(manager->getPhone());
        }
    }
    file.close();
    for (auto& [key, manager] : employees) {
        manager->AddEmpFromKey(employees);
    }

    //add emp from key
}





void Read::readRooms(std::map<unsigned int, std::shared_ptr<Room>>& rooms) {
    std::ifstream file(RoomFilePath);
    std::string line;
    while (std::getline(file, line)) {
        if(line.substr(0,6) == "Single"){
            auto room = std::make_shared<SingleRoom>();
            room->parse(line);
            rooms.emplace(room->getRoomNumber(),std::move(room));
        }
        else if(line.substr(0,6) == "Double"){
            auto room = std::make_shared<DoubleRoom>();
            room->parse(line);
            rooms.emplace(room->getRoomNumber(),std::move(room));
        }
        else if(line.substr(0,6) == "Suite"){
            auto room = std::make_shared<Suite>();
            room->parse(line);
            rooms.emplace(room->getRoomNumber(),std::move(room));
        }

    }

    file.close();
}
