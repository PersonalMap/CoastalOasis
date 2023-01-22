#include <iostream>
#include <algorithm>
#include "WeeklySchedule.h"
#include "HotelEnums.h"

/// Constructors
WeeklySchedule::WeeklySchedule(const std::vector<ScheduleItem>& s): _schedule() //init with vector
{
    for(auto item: s)
    {
        addActivity(item);
    }
}

WeeklySchedule::~WeeklySchedule()=default;

/// Operators

/// Functions
void WeeklySchedule::addActivity(ScheduleItem& s)
{
    if (!isBooked(s)) {
         const auto& duration = s.getDuration();
        _schedule[(int)duration.first.getYear()][(int)duration.first.getMonth()][(int)duration.first.getDay()].push_back(s);
    }
    else
    {
        std::cout << "ERROR: Activities overlap" << std::endl;
        throw std::runtime_error("Activities overlap");
    }

}

bool WeeklySchedule::isOverlaping(const ScheduleItem& s1, const ScheduleItem& s2) {
    // Get the duration of each ScheduleItem
    const auto& s1_duration = s1.getDuration();
    const auto& s2_duration = s2.getDuration();
    const auto s11 = s1_duration.first.getAsNumbers();
    const auto s12 = s1_duration.second.getAsNumbers();
    const auto s21 = s2_duration.first.getAsNumbers();
    const auto s22 = s2_duration.second.getAsNumbers();


    // Check if the start time of the first ScheduleItem is between the start and end times of the second ScheduleItem
    if (s11 > s21 && s11 < s22) {
        return true;
    }

    // Check if the end time of the first ScheduleItem is between the start and end times of the second ScheduleItem
    if (s12 > s21 && s12< s22) {
        return true;
    }

    // If neither of the above cases are true, then there is no overlap
    return false;
}


bool WeeklySchedule::isBooked(ScheduleItem& s) {
    const auto& duration = s.getDuration();
    for (const auto& item : _schedule[(int)duration.first.getYear()][(int)duration.first.getMonth()][(int)duration.first.getDay()]) {
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
            std::cout << "  Month: " << MyEnums::monthMap[static_cast<MyEnums::months>(month)] << std::endl;
            for (const auto& [day, day_schedule] : month_schedule) {
                std::cout << "    Day: " << day << std::endl;
                for (const auto& s : day_schedule) {
                    s.debug();
                }
            }
        }
    }
}

void WeeklySchedule::removeReservationByDate(const HTime& Date)
{
    _schedule[(int)Date.getYear()][(int)Date.getMonth()][(int)Date.getDay()].erase(
                _schedule[(int)Date.getYear()][(int)Date.getMonth()][(int)Date.getDay()].begin(),
                _schedule[(int)Date.getYear()][(int)Date.getMonth()][(int)Date.getDay()].end());
}

void WeeklySchedule::removeReservationByObject(const ScheduleItem& object)
{
    //find first key
    auto outerMapIter = _schedule.find((int)object.getDuration().first.getYear());
    if (outerMapIter != _schedule.end()) {
        //find second key
        auto middleMapIter = outerMapIter->second.find((int)object.getDuration().first.getMonth());
        if (middleMapIter != outerMapIter->second.end()) {
            //find third key
            auto innerMapIter = middleMapIter->second.find((int)object.getDuration().first.getDay());
            if (innerMapIter != middleMapIter->second.end()) {
                auto& itemVector = innerMapIter->second; // this is our vector with object
                auto itemIter = std::find(itemVector.begin(), itemVector.end(), object);
                if (itemIter != itemVector.end()) {
                    itemVector.erase(itemIter);
                }
            }
        }
    }

}


bool WeeklySchedule::isThereActivityThatDay(const HTime& Date)
{
    int key1 = (int)(Date.getYear());
    int key2 = (int)(Date.getMonth());
    int key3 = (int)(Date.getDay());

    auto outerMapIter = _schedule.find(key1);
    if (outerMapIter != _schedule.end()) {
        auto middleMapIter = outerMapIter->second.find(key2);
        if (middleMapIter != outerMapIter->second.end()) {
            auto innerMapIter = middleMapIter->second.find(key3);
            if (innerMapIter != middleMapIter->second.end()) {
                auto& itemVector = innerMapIter->second;
                if (itemVector.empty()) {
                    return false;
                    // the vector is empty at key1, key2, key3
                } else {
                    return true;
                    // the vector is not empty at key1, key2, key3
                }
            } else {
                return false;
                // key3 is not present in the map
            }
        } else {
            return false;
            // key2 is not present in the map
        }
    } else {
        return false;
        // key1 is not present in the map
    }


}