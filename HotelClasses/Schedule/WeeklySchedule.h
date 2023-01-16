#ifndef COASTALOASIS_WEEKLYSCHEDULE_H
#define COASTALOASIS_WEEKLYSCHEDULE_H

#include <string>
#include <array>
#include <vector>
#include "scheduleitem.h"
                                                              
class WeeklySchedule {

private:

    static constexpr unsigned int NUM_WEEKS = 52;
    static constexpr unsigned int NUM_DAYS = 7;

    std::array<std::array<std::vector<ScheduleItem>, NUM_DAYS>, NUM_WEEKS> schedule;

    //functions
public:
    WeeklySchedule() = default;
    WeeklySchedule(std::vector<ScheduleItem>);
    ~WeeklySchedule();

    // getters & setters
    inline const std::pair<unsigned int, unsigned int> getFirstWeekDay(ScheduleItem& s)
    {
        std::pair<unsigned int, unsigned int> weekday;
        size_t StartLenght = std::to_string(s.getDuration().first).length();
        weekday.first = std::stoi(std::to_string(s.getDuration().first).substr(0, StartLenght - 6));
        weekday.second = std::stoi(std::to_string(s.getDuration().first).substr(2, StartLenght - 4));
        return weekday;
    }
    inline const std::pair<unsigned int, unsigned int> getSecondWeekDay(ScheduleItem& s)
    {
        std::pair<unsigned int, unsigned int> weekday;
        size_t StartLenght = std::to_string(s.getDuration().second).length();
        weekday.first = std::stoi(std::to_string(s.getDuration().second).substr(0, StartLenght - 6));
        weekday.second = std::stoi(std::to_string(s.getDuration().second).substr(2, StartLenght - 4));
        return weekday;
    }
    //functions / operators
    void debug();

    void addItem(ScheduleItem& s);
    bool isBooked(ScheduleItem& s);
    template<typename T, std::size_t N>int findIndexOf(const T(&arr)[N], const T &obj);

};

#endif //COASTALOASIS_WEEKLYSCHEDULE_H