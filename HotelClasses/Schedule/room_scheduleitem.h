#ifndef ROOM_SCHEDULEITEM_H
#define ROOM_SCHEDULEITEM_H
#include "../Clients/External/user.h"
#include "scheduleitem.h"
class Room_scheduleitem: public ScheduleItem
{
private:
    User _booker;
public:
    Room_scheduleitem(User booker, bool booked, std::string activityName, long long startTime, long long endTime)
        :ScheduleItem(activityName, startTime, endTime, booked), _booker(booker){}
    ~Room_scheduleitem();
    //getters & setters

    const User& getUser(){return this->_booker;}

    void setBooker(const User& newBooker){this->_booker = newBooker;}
};

#endif // ROOM_SCHEDULEITEM_H
