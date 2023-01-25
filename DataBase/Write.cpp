#include "Write.h"

void Write::writeUsers(const std::map<std::string, std::unique_ptr<User>>& users) {
    std::cout << "Writing to file..." << std::endl;
    std::ofstream file(UserFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << UserFilePath << std::endl;;
    } else {
        for (auto &[key, value]: users) {
            if (value) {
                file << value->to_string() << std::endl;
            } else {
                std::cout << key << ": nullptr" << std::endl;
            }
        }
        file.close();
    }
}

void Write::writeEmployees(const std::map<std::string, std::unique_ptr<Employee>>& employees) {
    std::cout << "Writing to file..." << std::endl;
    std::ofstream file(EmployeeFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << EmployeeFilePath << std::endl;;
    } else {
        for (auto &[key, value]: employees) {
            if (value) {
                if (auto contractor = dynamic_cast<Contractor*>(value.get())) {
                    file << "Contractor" << ":" << contractor->to_string() << std::endl;
                } else if (auto intern = dynamic_cast<Intern*>(value.get())) {
                    file << "Intern" << ":" << intern->to_string() << std::endl;
                } else if (auto hourly = dynamic_cast<Hourly*>(value.get())) {
                    file << "Hourly" << ":" << hourly->to_string() << std::endl;
                } else if (auto manager = dynamic_cast<Manager*>(value.get())) {
                    file << "Manager" << ":" << manager->to_string() << std::endl;
                }

            } else {
                std::cout << key << ": nullptr" << std::endl;
            }
        }
        file.close();
    }
}

void Write::writeRooms(const std::map<unsigned int, std::unique_ptr<Room>>& rooms) {
    std::cout << "Writing to file..." << std::endl;
    std::ofstream file(RoomFilePath);
    if (!file.is_open()) {
        // handle the error here, e.g. throw an exception
        std::cout << "Error opening file " << RoomFilePath << std::endl;;
    } else {
        for (auto &[key, value]: rooms) {
            std::string keyWord = getRoomKeyWord(*value);
            if (value) {
                file << keyWord << ":" << value->to_string() << std::endl;
            } else {
                std::cout << key << ": nullptr" << std::endl;
            }
        }
        file.close();
    }
}

std::string Write::getKeyWord(const Employee& employee) {
    return Utilities::workPositionToString(employee.getWorkPosition());
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