//
// Created by Viktor Liljenberg on 2023-01-15.
//
#include <iostream>
#include <algorithm>
#include "WeeklySchedule.h"



WeeklySchedule::WeeklySchedule(std::vector<ScheduleItem> s)
{
    for(auto item: s)
    {
        addActivity(item);
    }
};

WeeklySchedule::~WeeklySchedule()
{

};


void WeeklySchedule::addActivity(ScheduleItem& s)
{
    if (!isBooked(s)) {
        auto duration = s.getDuration();
        //first
        int start_year = duration.first / 100000000;
        int start_month = (duration.first / 1000000) % 100;
        int start_day = (duration.first / 10000) % 100;

        _schedule[start_year][start_month][start_day].push_back(s);
    }
    else
    {
        std::cout << "ERROR: Activities overlap" << std::endl;
        throw std::runtime_error("Activities overlap");
    }

}

bool WeeklySchedule::isOverlaping(const ScheduleItem& s1, const ScheduleItem& s2) {
    // Get the duration of each ScheduleItem
    auto s1_duration = s1.getDuration();
    auto s2_duration = s2.getDuration();

    // Check if the start time of the first ScheduleItem is between the start and end times of the second ScheduleItem
    if (s1_duration.first > s2_duration.first && s1_duration.first < s2_duration.second) {
        return true;
    }

    // Check if the end time of the first ScheduleItem is between the start and end times of the second ScheduleItem
    if (s1_duration.second > s2_duration.first && s1_duration.second < s2_duration.second) {
        return true;
    }

    // If neither of the above cases are true, then there is no overlap
    return false;
}


bool WeeklySchedule::isBooked(ScheduleItem& s) {
    auto duration = s.getDuration();
    int year = duration.first / 100000000;
    int month = (duration.first / 1000000) % 100;
    int day = (duration.first / 10000) % 100;

    for (auto item : _schedule[year][month][day]) {
        if (isOverlaping(s, item)) {
            return true;
        }
    }
    return false;
}




void WeeklySchedule::debug() {
    for (const auto& [year, year_schedule] : _schedule) {
        std::cout << "Year: " << year << std::endl;
        for (const auto& [month, month_schedule] : year_schedule) {
            std::cout << "  Month: " << month << std::endl;
            for (const auto& [day, day_schedule] : month_schedule) {
                std::cout << "    Day: " << day << std::endl;
                for (const auto& s : day_schedule) {
                    s.debug();
                }
            }
        }
    }
}


