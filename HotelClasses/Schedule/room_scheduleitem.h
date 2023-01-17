#ifndef ROOM_SCHEDULEITEM_H
#define ROOM_SCHEDULEITEM_H
#include "../Clients/External/user.h"
#include "scheduleitem.h"
class Room_scheduleitem: public ScheduleItem
{
private:
    User _booker;
public:
    ///Constructors
    Room_scheduleitem(User booker, bool booked, std::string activityName,
                      long long startTime, long long endTime);
    ~Room_scheduleitem();

    ///getters & setters
    const User& getUser()const{return this->_booker;}

    void setBooker(const User& newBooker){this->_booker = newBooker;}

    ///Operators

    ///Functions
};

#endif // ROOM_SCHEDULEITEM_H
