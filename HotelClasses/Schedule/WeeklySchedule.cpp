//
// Created by Viktor Liljenberg on 2023-01-15.
//
#include <algorithm>
#include "WeeklySchedule.h"



WeeklySchedule::WeeklySchedule(std::vector<ScheduleItem> s)
{
    for(auto item: s)
    {
        addItem(item);
    }
};

WeeklySchedule::~WeeklySchedule()
{

};

void WeeklySchedule::debug()
{

};

void WeeklySchedule::addItem(ScheduleItem& s)
{

    if((getFirstWeekDay(s).first < 52 && getFirstWeekDay(s).second < 7) && !isBooked(s)) //light error check + availableCheck
    {
           schedule[getFirstWeekDay(s).first][getFirstWeekDay(s).second].push_back(s);
    }
    else
    {
        throw std::invalid_argument("must be in format, (week-week, day - day)");
    }
};

bool WeeklySchedule::isBooked(ScheduleItem& s)
{
    bool booked = false;
    //** GÖR DENNA INTE FÄRDIG **//

    for(auto i = schedule[getFirstWeekDay(s).first][getFirstWeekDay(s).second].begin(); i != schedule[getFirstWeekDay(s).first][getFirstWeekDay(s).second].end(); i++ )
    {
        if((s.getFirstHourMinute() <= i->getSecondHourMinute() && s.getFirstHourMinute() >= i->getFirstHourMinute())
        || (s.getSecondHourMinute() >= i->getFirstHourMinute() && s.getSecondHourMinute() <= i->getSecondHourMinute()))
        {
            booked = true;
        }
    }
    return booked;
}

template<typename T, std::size_t N>int WeeklySchedule::findIndexOf(const T(&arr)[N], const T &obj)
{
    auto iter = std::find(std::begin(arr), std::end(arr), obj);
    if(iter != std::end(arr))
    {
        return std::distance(std::begin(arr), iter);
    }
    return -1;
}