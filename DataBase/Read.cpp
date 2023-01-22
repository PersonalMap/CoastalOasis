#include "Read.h"
void Read::readUsers(std::map<std::string, User>& users, const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::string key;
        User user;
        std::istringstream iss(line);
        iss >> key >> user;
        users[key] = user;
    }
    file.close();
}
void Read::readEmployees(std::map<std::string, Employee>& employees, const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        std::string key;
        Employee employee;
        std::istringstream iss(line);
        iss >> key >> employee;
        employees[key] = employee;
    }
    file.close();
}

void Read::readRooms(std::map<unsigned int, Room>& rooms, const std::string& fileName) {
    std::ifstream file(fileName);
    std::string line;
    while (std::getline(file, line)) {
        unsigned int key;
        Room room;
        std::istringstream iss(line);
        iss >> key >> room;
        rooms[key] = room;
    }
    file.close();
}
