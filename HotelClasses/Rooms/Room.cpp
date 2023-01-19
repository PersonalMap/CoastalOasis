#include "Room.h"

///Constructors

Room::Room(unsigned roomNumber, unsigned price):_roomNumber(roomNumber),_price(price){};
Room::Room(std::string description, unsigned roomNumber, unsigned price)
            :_description(description),_roomNumber(roomNumber),_price(price){};
Room::Room(WeeklySchedule reservations, std::string description, unsigned roomNumber, unsigned price)
            :_reservations(reservations),_description(description),_roomNumber(roomNumber),_price(price){};
Room::~Room()=default;

///Functions

void Room::AddReservationByObject(Room_scheduleitem& reservation)
{
    this->_reservations.addActivity(reservation);
}

void Room::AddReservationByDate(const HTime& start, const HTime& end, const User& user)
{
    Room_scheduleitem r = Room_scheduleitem(user, true, start, end);
}

void Room::RemoveReservationByDate(const HTime& startDate, const HTime& endDate)
{
    _reservations.removeReservationByDate(startDate, endDate);
}

void Room::RemoveReservationByObject(const Room_scheduleitem& reservation)
{  bool free = true;

    unsigned int startDay = reservation.getDuration().first.getDay();
    unsigned int endDay = reservation.getDuration().second.getDay();
    auto dayOfMonth = MyEnums::daysOfMonth[reservation.getDuration().first.getMonth()];
    auto tempRes = reservation;

    int itterations = 0;

    if(endDay > startDay)
    {
        itterations = endDay - startDay;
    }
    else
    {
        itterations = (dayOfMonth - startDay) + endDay;
    }

    for(int i = 0; i < itterations; i++)
    {
        int j = i;
        int monthAddition = 0;
        if(i > dayOfMonth){j = 0 + i;monthAddition = 1;};
        this->_reservations.removeReservationByDate(HTime(reservation.getDuration().first.getYear(),
                                      reservation.getDuration().first.getMonth()+monthAddition,
                                      startDay + j, 12, 30));
    }
}
bool Room::IsRoomAvailable(const HTime& start, const HTime& end)
{
  ///ofärdig
}
