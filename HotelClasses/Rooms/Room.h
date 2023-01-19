#ifndef COASTALOASIS_ROOM_H
#define COASTALOASIS_ROOM_H
#include "WeeklySchedule.h"
#include "room_scheduleitem.h"
#include "HotelEnums.h"
#include "user.h"
#include <string>

class Room {

private:
    unsigned int _roomNumber;
    unsigned int _price;
    std::string _description;
    WeeklySchedule _reservations;

public:

    ///Constructors
    Room(unsigned roomNumber, unsigned price);
    Room(std::string description, unsigned roomNumber, unsigned price);
    Room(WeeklySchedule reservations, std::string description, unsigned roomNumber, unsigned price);
    ~Room();

    ///Getters & Setters
    const unsigned int& getRoomNumber()const{return this->_roomNumber;}
    const unsigned int& getPrice()const{return this->_price;}
    const std::string& getDescription()const{return this->_description;}
    const WeeklySchedule& getWeeklySchedule()const{return this->_reservations;}
    WeeklySchedule& getWeeklyScheduleRef(){return this->_reservations;} //used to modify schedule, be careful

    void setRoomNumber(const unsigned int& roomNumber){this->_roomNumber = roomNumber;}
    void setPrice(const unsigned int& price){this->_price = price;}
    void setDescription(const std::string& description){this->_description = description;}
    void setSchedule(const WeeklySchedule& reservations){this->_reservations = reservations;}

    ///Functions
    void AddReservationByObject(Room_scheduleitem& reservations);
    void AddReservationByDate(const HTime& start, const HTime& end, const User&);
    void RemoveReservationByDate(const HTime& startDate, const HTime& endDate);
    void RemoveReservationByObject(const Room_scheduleitem& reservations);
    bool IsRoomAvailable(const HTime& start, const HTime& end);




};

#endif
