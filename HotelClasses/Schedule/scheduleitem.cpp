#include "scheduleitem.h"


///Constructors

ScheduleItem::ScheduleItem(std::string activityName, const HTime& startTime, const HTime& endTime)
                                : _activityName(std::move(activityName)),
                                _duration(std::make_pair(startTime, endTime)){};
ScheduleItem::~ScheduleItem() = default;

///Operators

    bool ScheduleItem::operator==(const ScheduleItem& other) const
        { return this->_duration.first.getDebugDateString() == other._duration.first.getDebugDateString();}
///Functions



void ScheduleItem::debug() const {
        std::string isZero1 = "";
    std::string isZero2 = "";
        if(std::stoi(_duration.first.getRawHourMinute().substr(2)) == 0){isZero1 = "0";}
    if(std::stoi(_duration.second.getRawHourMinute().substr(2)) == 0){isZero2 = "0";}


    std::cout << _activityName << " Duration: " << _duration.first.getRawHourMinute()
      << isZero1 << "-" << _duration.second.getRawHourMinute() << isZero2 << std::endl;
}



