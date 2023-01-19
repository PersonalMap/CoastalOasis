#ifndef ROOM_SCHEDULEITEM_H
#define ROOM_SCHEDULEITEM_H
#include "../Clients/External/user.h"
#include "scheduleitem.h"
class Room_scheduleitem: public ScheduleItem
{
private:
    User _booker;
    bool _booked;
public:
    ///Constructors
    Room_scheduleitem(User booker, bool booked, std::string activityName,
                      const HTime& startTime, const HTime& endTime);
    ~Room_scheduleitem();

    ///getters & setters
    const User& getUser()const{return this->_booker;}
    const bool& getBooked()const{return this->_booked;}

    void setBooker(const User& newBooker){this->_booker = newBooker;}
    void setBooked(const bool& isBooked){this->_booked = isBooked;}

};

#endif // ROOM_SCHEDULEITEM_H
