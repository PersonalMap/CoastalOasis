#include "Hotel.h"

///Constructors
Hotel::Hotel(): _roomKey(), _userKey(), _employeeKey(), _users(), _employees(), _rooms(), _read(), _write()
{

    readInHotel();

}
Hotel::~Hotel()
{
    std::cout << "saving.. ~Hotel"<< std::endl;
    writeHotel();
}

/// KEY RELATED
std::string Hotel::getUserKey(const User& user) {
    for (const auto& pair : _users) {
        if (*pair.second == user) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getEmployeeKey(const Employee& employee) {
    for (const auto& pair : _employees) {
        if (*pair.second == employee) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getUserKeyByPhone(const std::string& phoneNumber) {
    for (const auto& pair : _users) {
        if (pair.second->getPhone() == phoneNumber) {
            return pair.first;
        }
    }
    return "";
}

std::string Hotel::getEmployeeKeyByPhone(const std::string& phoneNumber) {
    for (const auto& pair : _employees) {
        if (pair.second->getPhone() == phoneNumber) {
            return pair.first;
        }
    }
    return "";
}

unsigned int Hotel::getRoomKey(const Room& room)
{
    for (const auto& pair : _rooms) {
        if (*pair.second == room) {
            return pair.first;
        }
    }
    return 0;
}


/// ADDING & DELETING from MAP

void Hotel::addRoom(Room& room){
    _rooms.emplace(room.getRoomNumber(), std::make_shared<Room>(room));
}

void Hotel::addEmployee(Employee& employee) {
    _employees.emplace(employee.getPhone(), std::make_shared<Employee>(employee));
}



void Hotel::addUser(User& user) {
    _users.emplace(user.getPhone(), std::make_shared<User>(user));
}
//delete
void Hotel::removeUser(User &user){
    auto it = _users.find(user.getPhone());
    if (it != _users.end()) {
        _users.erase(it);
    }
}

void Hotel::removeEmployee(Employee& employee) {
    auto it = _employees.find(employee.getPhone());
    if (it != _employees.end()) {
        _employees.erase(it);
    }
}

void Hotel::removeRoom(Room& room) {
    auto it = _rooms.find(room.getRoomNumber());
    if (it != _rooms.end()) {
        _rooms.erase(it);
    }
}

void Hotel::readInHotel()
{
    _read.readEmployees(_employees);
    _read.readUsers(_users);
    _read.readRooms(_rooms);
}
void Hotel::writeHotel()
{

    _write.writeEmployees(_employees);
    _write.writeUsers(_users);
    _write.writeRooms(_rooms);
}


void Hotel::printEmployees()
{
    for (const auto& [key, employee]: _employees)
    {
        if (const auto derived = std::dynamic_pointer_cast<Manager>(employee))
        {
            std::cout << *derived << std::endl;
        }
        else
        {
            std::cout << *employee << std::endl;
        }
    }

}
void Hotel::printUsers()
{
    for (const auto& [key, user]: _users) {
        std::cout << user;
    }
}
void Hotel::printRooms()
{
    for (const auto& [key, room]: _rooms) {
        std::cout << room;
    }
}



