#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H
#include <string>
#include <iostream>
#include "HTime.h"

class ScheduleItem
{
private:

    std::string _activityName;
    std::pair<HTime,HTime> _duration; // start : yyyymmddhhmm, end : yyyymmddhhmm

public:

    ///Constructors
    ScheduleItem(std::string activityName, const HTime& startTime, const HTime& endTime);
    ~ScheduleItem();

    ///getters & setters
    const std::string& getActivityName()const{return this->_activityName;}
    const std::pair<HTime, HTime>& getDuration() const{return this->_duration;}

    void setActivityName(const std::string& newActivityName){this->_activityName = newActivityName;}
    void setDuration(const std::pair<HTime, HTime>& duration){this->_duration = duration;}

    ///operators
    void debug() const; //debug
    bool operator==(const ScheduleItem& other) const; // defines how class should be compared



};

#endif
