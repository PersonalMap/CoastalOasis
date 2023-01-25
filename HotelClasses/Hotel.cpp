#include "Hotel.h"

///Constructors
Hotel::Hotel(): _roomKey(), _userKey(), _employeeKey(), _users(), _employees(), _rooms(), _read(), _write()
{

    readInHotel();

}
Hotel::~Hotel()
{
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

void Hotel::addRoom(std::unique_ptr<Room> room){
    auto roomNmbr = room->getRoomNumber();
    _rooms.emplace(roomNmbr, std::move(room));
    writeHotel();
}

void Hotel::addEmployee(std::unique_ptr<Employee> employee) {
    auto phone = employee->getPhone();
    _employees.emplace(phone, std::move(employee));
    writeHotel();
}


void Hotel::addUser(std::unique_ptr<User> user) {
    _users.insert({user->getPhone(), std::move(user)});
    writeHotel();
}
//delete
void Hotel::removeUser(User &user){
    auto it = _users.find(user.getPhone());
    if (it != _users.end()) {
        _users.erase(it);
        writeHotel();
    }
}

void Hotel::removeEmployee(Employee& employee) {
    auto it = _employees.find(employee.getPhone());
    if (it != _employees.end()) {
        _employees.erase(it);
        writeHotel();
    }
}

void Hotel::removeRoom(Room& room) {
    auto it = _rooms.find(room.getRoomNumber());
    if (it != _rooms.end()) {
        _rooms.erase(it);
        writeHotel();
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
    for (const auto& [key, employee]: _employees) {
        std::cout << *employee;
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