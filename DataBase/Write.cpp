#include "Write.h"

void Write::writeUsers(const std::map<std::string, User>& users, const std::string& fileName) {
    std::ofstream file(fileName);
    for (const auto& [key, user] : users) {
        file << key << " " << user.toString() << std::endl;
    }
    file.close();
}
void Write::writeEmployees(const std::map<std::string, Employee>& employees, const std::string& fileName) {
    std::ofstream file(fileName);
    for (const auto& [key, employee] : employees) {
        file << key << " " << employee.toString() << std::endl;
    }
    file.close();
}
void Write::writeRooms(const std::map<unsigned int, Room>& rooms, const std::string& fileName) {
    std::ofstream file(fileName);
    for (const auto& [key, room] : rooms) {
        file << key << " " << room.toString() << std::endl;
    }
    file.close();
}