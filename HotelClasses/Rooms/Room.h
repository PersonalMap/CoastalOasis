#ifndef COASTALOASIS_ROOM_H
#define COASTALOASIS_ROOM_H
#include "WeeklySchedule.h"
#include "room_scheduleitem.h"
#include "HotelEnums.h"
#include "user.h"
#include "Utilities.h"
#include <string>

class Room {

private:
    unsigned int _roomNumber;
    unsigned int _price;
    std::string _description;
    WeeklySchedule _reservations;
    MyEnums::RoomType _roomType;
    MyEnums::BedType _bedSize; //default is 120

public:

    ///Constructors
    Room(MyEnums::RoomType roomType, unsigned roomNumber, unsigned price);
    Room(MyEnums::BedType bedSize,MyEnums::RoomType roomType,std::string description, unsigned roomNumber, unsigned price);
    Room(MyEnums::BedType bedSize,MyEnums::RoomType roomType,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price);
    ~Room();

    ///Getters & Setters
    const unsigned int& getRoomNumber()const{return this->_roomNumber;}
    const unsigned int& getPrice()const{return this->_price;}
    const std::string& getDescription()const{return this->_description;}
    const WeeklySchedule& getWeeklySchedule()const{return this->_reservations;}
    WeeklySchedule& getWeeklyScheduleRef(){return this->_reservations;} //used to modify schedule, be careful
    const MyEnums::RoomType& getRoomType(){return this->_roomType;}
    const MyEnums::BedType& getBedSize(){return this->_bedSize;}

    void setRoomNumber(const unsigned int& roomNumber){this->_roomNumber = roomNumber;}
    void setRoomType(const MyEnums::RoomType& roomType){this->_roomType = roomType;}
    void setPrice(const unsigned int& price){this->_price = price;}
    void setDescription(const std::string& description){this->_description = description;}
    void setSchedule(const WeeklySchedule& reservations){this->_reservations = reservations;}
    void setBedSize(const MyEnums::BedType& bedSize){this->_bedSize = bedSize;}

    ///Functions
    void AddReservationByObject(Room_scheduleitem& reservations);
    static void AddReservationByDate(const HTime& start, const HTime& end, const User&);
    void RemoveReservationByDate(const HTime& startDate);
    void RemoveReservationByObject(const Room_scheduleitem& reservations);
    bool IsRoomAvailable(const HTime& start, const HTime& end);

    //operator

    bool operator==(const Room& rhs) const {
        return this->_roomNumber == rhs.getRoomNumber() && this->_roomNumber == rhs.getRoomNumber();
    }


};

#endif
