#ifndef COASTALOASIS_WEEKLYSCHEDULE_H
#define COASTALOASIS_WEEKLYSCHEDULE_H
#include <map>
#include <array>
#include <vector>
#include "scheduleitem.h"
                                                              
class WeeklySchedule {

private:

    std::map<int, std::map<int, std::map<int, std::vector<ScheduleItem>>>> _schedule;

public:

    ///Constructors
    WeeklySchedule() = default;
    WeeklySchedule(std::vector<ScheduleItem>);
    ~WeeklySchedule();

    /// getters & setters
    const std::map<int, std::map<int, std::map<int, std::vector<ScheduleItem>>>>& getSchedule(){return _schedule;}

    ///Operators

    /// functions
    bool isOverlaping(const ScheduleItem& s1, const ScheduleItem& s2); //check for overlaping
    void addActivity(ScheduleItem& s);
    bool isBooked(ScheduleItem& s);
    void debug();

};

#endif