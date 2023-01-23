#include "SingleRoom.h"

///constructors
SingleRoom::SingleRoom(){};
SingleRoom::SingleRoom(unsigned roomNumber, unsigned price):
        Room(MyEnums::RoomType::Single, roomNumber, price)
                , _windows(2)
                {
                    setBedSize(MyEnums::BedType::Single140);
                };
SingleRoom::SingleRoom(unsigned int windows,MyEnums::BedType bedSize,std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Single,description,roomNumber,price)
                     , _windows(windows){};
SingleRoom::SingleRoom(unsigned int windows,MyEnums::BedType bedSize,const WeeklySchedule& reservations,
                       std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Single,getWeeklySchedule(),description,roomNumber,price)
                    , _windows(windows){};
SingleRoom::~SingleRoom() = default;