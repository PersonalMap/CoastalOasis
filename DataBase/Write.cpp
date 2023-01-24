#include "Write.h"

void Write::writeUsers(const std::map<std::string, User>& users) {
    std::ofstream file(UserFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << UserFilePath << std::endl;;
    }
    else {
        for (const auto& [key, user] : users) {
            file << user.to_string() << std::endl;
        }
        file.close();
    }
}
void Write::writeEmployees(const std::map<std::string, Employee>& employees) {
    std::ofstream file(EmployeeFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << EmployeeFilePath << std::endl;
    }
    else {
        for (const auto &[key, employee]: employees) {
            std::string keyWord = getKeyWord(employee);
            file << keyWord << ":" << employee.to_string() << std::endl;
        }
        file.close();
    }
}
void Write::writeRooms(const std::map<unsigned int, Room>& rooms) {
    std::ofstream file(RoomFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << RoomFilePath << std::endl;;
    }
    else {
        for (const auto &[key, room]: rooms) {
            std::string keyWord = getRoomKeyWord(room);
            file << keyWord << ":" << room.to_string() << std::endl;
        }
        file.close();
    }
}

std::string Write::getKeyWord(const Employee& employee) {
   switch(employee.getWorkPosition())
   {
       case MyEnums::WorkPosition::Contractor: return "Contractor";
       break;
       case MyEnums::WorkPosition::Hourly: return "Hourly";
       break;
       case MyEnums::WorkPosition::Intern: return "Intern";
       break;
       case MyEnums::WorkPosition::Manager: return "Manager";
       break;
       default: return "";
   }
}

std::string Write::getRoomKeyWord(const Room& room) {
    switch(room.getRoomType())
    {
        case MyEnums::RoomType::Single : return "Single";
            break;
        case MyEnums::RoomType::Double : return "Double";
            break;
        case MyEnums::RoomType::Suite : return "Suite";
            break;
        default: return "";
    }
}