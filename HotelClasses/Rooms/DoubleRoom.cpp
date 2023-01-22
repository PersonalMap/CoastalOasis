#include "DoubleRoom.h"

///constructors

DoubleRoom::DoubleRoom(unsigned roomNumber, unsigned price):
        Room(MyEnums::RoomType::Double, roomNumber, price),
        _Beds(1), _Rooms(3)
        {
            setBedSize(MyEnums::BedType::DoubleBed);
        };
DoubleRoom::DoubleRoom(unsigned int beds, unsigned int rooms,MyEnums::BedType bedSize,std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Double,description,roomNumber,price),
            _Beds(beds), _Rooms(rooms){};
DoubleRoom::DoubleRoom(unsigned int beds, unsigned int rooms,MyEnums::BedType bedSize,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Double,getWeeklySchedule(),description,roomNumber,price),
            _Beds(beds), _Rooms(rooms){};
DoubleRoom::~DoubleRoom() = default;