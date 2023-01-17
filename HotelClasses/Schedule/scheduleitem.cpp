#include "scheduleitem.h"


///Constructors

ScheduleItem::ScheduleItem(std::string activityName, long long startTime, long long endTime, bool booked)
                                : _activityName(activityName), _booked(booked),
                                _duration(std::make_pair(startTime, endTime)){};
ScheduleItem::~ScheduleItem(){};

///Operators

    bool ScheduleItem::operator==(const ScheduleItem& other) const { return this->_duration == other._duration;}
///Functions


void ScheduleItem::debug() const {
    std::cout << _activityName << " Duration: " << convertToTime().first << "-" << convertToTime().second << std::endl;
}


std::pair<std::string, std::string> ScheduleItem::convertTimeToDate() //CONVERTS to 0109 format mmdd
{
    errorCheckTime();

    size_t StartLenght = std::to_string(_duration.first).length();
    std::string start_str = std::to_string(_duration.first).substr(2, StartLenght-8);
    std::string end_str = std::to_string(_duration.first).substr(4, StartLenght-6);

    return std::make_pair(std::string(start_str), std::string(end_str));
}

std::pair<std::string, std::string> ScheduleItem::convertToTime() const  //converts to hhmm format
{
    errorCheckTime();

    std::string start_str = std::to_string(_duration.first).substr(8);
    std::string end_str = std::to_string(_duration.second).substr(8);

    return std::make_pair(std::string(start_str), std::string(end_str));
}


void ScheduleItem::errorCheckTime()const //is time valid? error checking
{
    try {
        //MORE THAN ZERO?
        if (this->_duration.first <= 0 || this->_duration.second <= 0) {
            throw std::invalid_argument("Invalid time");
        }

        } catch (const std::invalid_argument& e) {
            // code to handle the exception
            std::cout << "Error: " << e.what() << std::endl;
        }
}