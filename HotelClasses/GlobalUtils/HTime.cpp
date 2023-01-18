#include "HTime.h"
#include <string>
#include "Utilities.h"
#include "HotelEnums.h"

///Constructors
HTime::HTime(): _year(0), _month(0), _day(0), _hour(0), _minute(0){};
HTime::HTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute)
                :_year(year), _month(month), _day(day),_hour(hour), _minute(minute){}
HTime::~HTime(){};

///operators
HTime HTime::operator+(const HTime &time2) const {
    int sumYear = _year + time2._year;
    int sumMonth = _month + time2._month;
    int sumDay = _day + time2._day;
    int sumHour = _hour + time2._hour;
    int sumMinute = _minute + time2._minute;
    if (sumMinute >= 60) {
        sumMinute -= 60;
        sumHour += 1;
    }
    if (sumHour >= 24) {
        sumHour -= 24;
        sumDay += 1;
    }
    if (sumDay >= 30) {
        sumDay -= 30;
        sumMonth += 1;
    }
    if (sumMonth >= 12) {
        sumMonth -= 12;
        sumYear += 1;
    }
    return HTime(sumYear,sumMonth,sumDay,sumHour,sumMinute);
}

HTime HTime::operator-(const HTime &time2) const {
    int diffYear = _year - time2._year;
    int diffMonth = _month - time2._month;
    int diffDay = _day - time2._day;
    int diffHour = _hour - time2._hour;
    int diffMinute = _minute - time2._minute;

    // Handle negative values
    if (diffMinute < 0) {
        diffMinute += 60;
        diffHour -= 1;
    }
    if (diffHour < 0) {
        diffHour += 24;
        diffDay -= 1;
    }
    if (diffDay < 0) {
        diffDay += 30;
        diffMonth -= 1;
    }
    if (diffMonth < 0) {
        diffMonth += 12;
        diffYear -= 1;
    }
    return HTime(diffYear,diffMonth,diffDay,diffHour,diffMinute);
}

std::ostream& operator<< (std::ostream& o, const HTime& t)
{
    std::string day_ending = Utilities::getCounterEnder(t._day);
    std::string month_name = MyEnums::monthMap[static_cast<MyEnums::months>(t._month)];
    o << t._day << day_ending << " " << month_name << " " << t._year;
    return o;
}

///Functions


std::string HTime::getFullDateString()// with seconds minutes
{
    std::string s = std::to_string(this->_year) + '/' + std::to_string(this->_month) + "/" +
                    std::to_string(this->_day) + " " + std::to_string(this->_hour) + ":" + std::to_string(this->_minute);
    return s;
}
std::string HTime::getDateString() //without seconds minutes
{
    std::string s = std::to_string(this->_year) + "/" + std::to_string(this->_month) + "/" +
                    std::to_string(this->_day);
    return s;
}