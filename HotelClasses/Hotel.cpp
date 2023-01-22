#include "Hotel.h"

///Constructors
Hotel::Hotel(): _roomKey(), _userKey(), _employeeKey(), _users(), _employees(), _rooms()
{
    Read read = Read(); //lets read in some data
    read.readEmployees(_employees, "./Data/Employees");
    read.readUsers(_users, "./Data/Users");
    read.readRooms(_rooms, "./Data/Rooms");

}
Hotel::~Hotel()
{
    Write write = Write(); //lets write over the information from this seassion
    write.writeEmployees(_employees, "./Data/Employees");
    write.writeUsers(_users, "./Data/Users");
    write.writeRooms(_rooms, "./Data/Rooms");
}

/// KEY RELATED
std::string Hotel::getUserKey(const User& user) {
    for (const auto& pair : _users) {
        if (pair.second == user) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getEmployeeKey(const Employee& employee) {
    for (const auto& pair : _employees) {
        if (pair.second == employee) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getUserKeyByPhone(const std::string& phoneNumber) {
    for (const auto& pair : _users) {
        if (pair.second.getPhone() == phoneNumber) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getEmployeeKeyByPhone(const std::string& phoneNumber) {
    for (const auto& pair : _employees) {
        if (pair.second.getPhone() == phoneNumber) {
            return pair.first;
        }
    }
    return "";
}

unsigned int Hotel::getRoomKey(const Room& room)
{
    for (const auto& pair : _rooms) {
        if (pair.second == room) {
            return pair.first;
        }
    }
    return 0;
}


/// ADDING & DELETING from MAP

void Hotel::addUser(User& user){this->_users.insert({user.getPhone(), user});}
void Hotel::addEmployee(Employee& employee){this->_employees.insert({employee.getPhone(), employee});}
void Hotel::addRoom(Room& room){this->_rooms.insert({room.getRoomNumber(), room});}
//delete
void Hotel::removeUser(User& user){_users.erase(this->getUserKey(user));}
void Hotel::removeEmployee(Employee& employee){_employees.erase(this->getEmployeeKey(employee));} //erase employee with our getKey function
void Hotel::removeRoom(Room& room){_rooms.erase(this->getRoomKey(room));}