#include "Room.h"

#include <utility>

///Constructors
Room::Room(){};
Room::Room(MyEnums::RoomType roomType,unsigned roomNumber, unsigned price)
            :_bedSize(MyEnums::BedType::Single120),_roomType(roomType) ,_reservations(),
            _description(""),_roomNumber(roomNumber),_price(price){};
Room::Room(MyEnums::BedType bedSize,MyEnums::RoomType roomType,std::string description, unsigned roomNumber, unsigned price)
            :_bedSize(bedSize),_roomType(roomType),_reservations()
            ,_description(std::move(description)),_roomNumber(roomNumber),_price(price){};
Room::Room(MyEnums::BedType bedSize,MyEnums::RoomType roomType,const WeeklySchedule& reservations, std::string description, unsigned roomNumber, unsigned price)
            :_bedSize(bedSize),_roomType(roomType),_reservations(reservations),
            _description(std::move(description)),_roomNumber(roomNumber),_price(price){};
Room::~Room()=default;

///operators

std::ostream& operator<<(std::ostream& os, const Room& r) {
    return os << "Room Number: " << r._roomNumber << "\n"
              << "Price: " << r._price << "$\n"
              << "Description: " << r._description << "\n"
              << "Room Type: " << MyEnums::roomTypeMap[r._roomType] << "\n"
              << "Bed Size: " << MyEnums::bedTypeMap[r._bedSize] << std::endl;
}

///Functions

void Room::AddReservationByObject(Room_scheduleitem& reservation)
{
    this->_reservations.addActivity(reservation);
}

void Room::AddReservationByDate(const HTime& start, const HTime& end, const User& user)
{
    Room_scheduleitem r = Room_scheduleitem(user, true, start, end);
}

void Room::RemoveReservationByDate(const HTime& startDate)
{
    _reservations.removeReservationByDate(startDate);
}

void Room::RemoveReservationByObject(const Room_scheduleitem& reservation)
{
    this->_reservations.removeReservationByObject(reservation);
}

bool Room::IsRoomAvailable(const HTime& start, const HTime& end)
{
    bool activityThatDay = false;
    auto dayOfMonth = MyEnums::daysOfMonth[start.getMonth()];
    int itterations = Utilities::getNumberOfDays(start, end);

    for(int i = 0; i < itterations; i++)
    {
        int j = i;
        int monthAddition = 0;
        if(i > dayOfMonth){j = 0 + i;monthAddition = 1;};
        activityThatDay = this->_reservations.isThereActivityThatDay(HTime(
                                                    start.getYear(),
                                                   start.getMonth()+monthAddition,
                                                   start.getDay() + j,
                                                   12,
                                                   30
        ));
    };
    if(activityThatDay){return false;}
    else {return true;}
}


void Room::parse(std::string data) const
{

}
std::string Room::to_string()const
{

}
