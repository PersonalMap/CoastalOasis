#ifndef COASTALOASIS_WEEKLYSCHEDULE_H
#define COASTALOASIS_WEEKLYSCHEDULE_H

#include <string>
#include <map>
#include <array>
#include <vector>
#include "scheduleitem.h"
                                                              
class WeeklySchedule {

private:

    std::map<int, std::map<int, std::map<int, std::vector<ScheduleItem>>>> _schedule;

    //functions
public:
    WeeklySchedule() = default;
    WeeklySchedule(std::vector<ScheduleItem>);
    ~WeeklySchedule();

    // getters & setters


    //functions / operators
    bool isOverlaping(const ScheduleItem& s1, const ScheduleItem& s2); //check for overlaping
    void addActivity(ScheduleItem& s);
    bool isBooked(ScheduleItem& s);
    void debug();

};

#endif //COASTALOASIS_WEEKLYSCHEDULE_H