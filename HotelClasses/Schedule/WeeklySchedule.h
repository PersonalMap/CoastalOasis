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
    explicit WeeklySchedule(const std::vector<ScheduleItem>&);
    ~WeeklySchedule();

    /// getters & setters
    const std::map<int, std::map<int, std::map<int, std::vector<ScheduleItem>>>>& getSchedule(){return _schedule;}

    ///Operators

    /// functions
    static bool isOverlaping(const ScheduleItem& s1, const ScheduleItem& s2); //check for overlaping
    void addActivity(ScheduleItem& s);
    bool isBooked(ScheduleItem& s);
    void debug();
    void removeReservationByDate(const HTime& Date); //removes first one that day, meant for rooms
    void removeReservationByObject(const ScheduleItem& object);
    bool isThereActivityThatDay(const HTime& Date); //only info down to day is being used

};

#endif