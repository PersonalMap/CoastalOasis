#ifndef SCHEDULEITEM_H
#define SCHEDULEITEM_H
#include <string>
#include <iostream>
#include <ctime>


class ScheduleItem
{
private:
    std::string _debug = "";

    std::string _activityName;
    std::pair<long long,long long> _duration; // wwdd-hhmm
    bool _booked;

public:
    ScheduleItem(std::string activityName, long long startTime, long long endTime, bool booked) :
        _activityName(activityName), _booked(booked), _duration(std::make_pair(startTime, endTime))
    {
    }
    ~ScheduleItem();

    //getters & setters

    const std::string& getActivityName(){return _activityName;}
    const std::pair<long long, long long>& getDuration(){return this->_duration;}
    const bool& getBooked(){return this->_booked;}
    const unsigned int& getFirstHourMinute(){return std::stoi(std::to_string(_duration.first).substr(4));}
    const unsigned int& getSecondHourMinute(){return std::stoi(std::to_string(_duration.second).substr(4));}

    void setActivityName(const std::string& newActivityName){_activityName = newActivityName;}
    void setDuration(const std::pair<long long, long long>& duration){this->_duration = duration;}
    void setBooked(const bool isBooked){this->_booked = isBooked;}

    //operators
    bool operator==(const ScheduleItem& other) const {
        // Compare the relevant member variables of the ScheduleItem class here
        // For example, if the class has a "name" member variable, you would compare
        // the values of "name" in the current object and "other" object
        return this->_duration == other._duration;
    }

    inline std::string& debug() //debug operator
    {
        _debug = "";
        _debug = convertTimeToHourMinute().first + " - " + convertTimeToHourMinute().second;
        return _debug;
    }

protected: //derived classes can acces but not others
    /* CONVERTS TO DATE*/
   inline std::pair<std::string, std::string> convertTimeToDate() {

           errorCheckTime();

           size_t StartLenght = std::to_string(_duration.first).length();
           size_t EndLenght = std::to_string(_duration.second).length();
           std::string start_str = std::to_string(_duration.first).substr(0, StartLenght-4);
           std::string end_str = std::to_string(_duration.second).substr(0, EndLenght-4);

        return std::make_pair(std::string(start_str), std::string(end_str));
    }

    /* CONVERTS TO TIME*/
    inline std::pair<std::string, std::string> convertTimeToHourMinute() {

        errorCheckTime();

        std::string start_str = std::to_string(_duration.first).substr(8);
        std::string end_str = std::to_string(_duration.second).substr(8);

        return std::make_pair(std::string(start_str), std::string(end_str));
    }

    //error checking time

    inline void errorCheckTime()
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



};

#endif // SCHEDULEITEM_H
