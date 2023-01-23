#include "Suite.h"

///constructors
Suite::Suite(){};
Suite::Suite(unsigned roomNumber, unsigned price):
        Room(MyEnums::RoomType::Suite, roomNumber, price),
        _hasBalcony(false), _hasSpa(false)
        {
            this->setBedSize(MyEnums::BedType::KingBed);
        };
Suite::Suite(bool hasBalcony, bool hasSpa,MyEnums::BedType bedSize,std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Suite,description,roomNumber,price),
        _hasSpa(hasSpa), _hasBalcony(hasBalcony){};
Suite::Suite(bool hasBalcony, bool hasSpa,MyEnums::BedType bedSize,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price):
        Room(bedSize,MyEnums::RoomType::Suite,getWeeklySchedule(),description,roomNumber,price),
        _hasSpa(hasSpa), _hasBalcony(hasBalcony){};
Suite::~Suite() = default;