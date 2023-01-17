#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H
#include <string>
#include <iostream>
#include <ctime>


class ScheduleItem
{
private:

    std::string _activityName;
    std::pair<long long,long long> _duration; // start : yyyymmddhhmm, end : yyyymmddhhmm
    bool _booked;

public:

    ///Constructors
    ScheduleItem(std::string activityName, long long startTime, long long endTime, bool booked);
    ~ScheduleItem();

    ///getters & setters
    const std::string& getActivityName()const{return _activityName;}
    const std::pair<long long, long long>& getDuration() const{return this->_duration;}
    const bool& getBooked()const{return this->_booked;}
    unsigned int getFirstHourMinute()const{return std::stoi(std::to_string(_duration.first).substr(4));}
    unsigned int getSecondHourMinute()const{return std::stoi(std::to_string(_duration.second).substr(4));}

    void setActivityName(const std::string& newActivityName){_activityName = newActivityName;}
    void setDuration(const std::pair<long long, long long>& duration){this->_duration = duration;}
    void setBooked(const bool isBooked){this->_booked = isBooked;}

    ///operators
    void debug() const; //debug
    bool operator==(const ScheduleItem& other) const; // defines how calss should be compared

    ///Functions
    protected:

    /* CONVERSIONS AND ERROR-CHECKING*/
    std::pair<std::string, std::string> convertTimeToDate(); // returns 0109 etc. 9th january
    std::pair<std::string, std::string> convertToTime() const;//only get time 19:30, 18:30 etc.
    void errorCheckTime()const;//error checking time
};

#endif
