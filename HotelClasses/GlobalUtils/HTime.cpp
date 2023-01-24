#include "HTime.h"
#include <string>
#include "Utilities.h"
#include "HotelEnums.h"

///Constructors
HTime::HTime(): _year(0), _month(0), _day(0), _hour(0), _minute(0){};
HTime::HTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute)
                :_year(year), _month(month), _day(day),_hour(hour), _minute(minute){}
HTime::HTime(const std::string& data)
{
    errorCheckTime(data); //runs error checks

    auto dataNmr = std::stoll(data);
    this->_year = dataNmr / 100000000;
    this->_month = (dataNmr / 1000000) % 100;
    this->_day = (dataNmr / 10000) % 100;
    this->_hour = (dataNmr / 100) % 100;
    this->_minute = dataNmr % 100;

}

HTime::~HTime()= default;

///operators
HTime HTime::operator+(const HTime &time2) const {
    int sumYear = (int)_year + (int)time2._year;
    int sumMonth = (int)_month + (int)time2._month;
    int sumDay = (int)_day + (int)time2._day;
    int sumHour = (int)_hour + (int)time2._hour;
    int sumMinute = (int)_minute + (int)time2._minute;
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
    int diffYear = (int)_year - (int)time2._year;
    int diffMonth = (int)_month - (int)time2._month;
    int diffDay = (int)_day - (int)time2._day;
    int diffHour = (int)_hour - (int)time2._hour;
    int diffMinute = (int)_minute - (int)time2._minute;

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


std::string HTime::getDebugFullDateString() const// with seconds minutes
{
    std::string s = std::to_string(this->_year) + '/' + std::to_string(this->_month) + "/" +
                    std::to_string(this->_day) + " " + std::to_string(this->_hour) + ":" + std::to_string(this->_minute);
    return s;
}
std::string HTime::getDebugDateString() const //without seconds minutes
{
    std::string s = std::to_string(this->_year) + "/" + std::to_string(this->_month) + "/" +
                    std::to_string(this->_day);
    return s;
}

std::string HTime::getRawFullDateString() const
{
    std::string s = std::to_string(_year);
    if(_month < 10)
    {
        s += "0" + std::to_string(_month);
    }else{s += std::to_string(_month);}
    if(_day < 10)
    {
        s += "0" + std::to_string(_day);
    }else{s += std::to_string(_day);}
    if(_hour < 10)
    {
        s += "0" + std::to_string(_hour);
    }else{s += std::to_string(_hour);}
    if(_minute < 10)
    {
        s += "0" + std::to_string(_minute);
    }else{s += std::to_string(_minute);}

    return s;


}
std::string HTime::getRawDateString() const
{
    std::string s = std::to_string(this->_year) + std::to_string(this->_month) +
                    std::to_string(this->_day);
    return s;
}
std::string HTime::getRawHourMinute() const
{
    std::string s = std::to_string(this->_hour) + std::to_string(this->_minute);
    return s;
}

/* Error checking*/
 void HTime::errorCheckTime(const std::string& dateString) //is time valid? error checking
{

    //MORE THAN ZERO?
    try {
        if (std::stoll(dateString) <= 0) {
            throw std::invalid_argument("Invalid time");
        }
    } catch (const std::invalid_argument& e) {
        // code to handle the exception
        std::cout << "Error: " << e.what() << std::endl;
    }

    try{
        auto dataNmr = std::stoll(dateString);
        int year = (int)(dataNmr / 100000000);
        int month = (int)(dataNmr / 1000000) % 100;
        int day = (int)((dataNmr / 10000) % 100);
        int hour = (int)((dataNmr / 100) % 100);
        int minute = (int)(dataNmr % 100);
            if(year < 2023 || year >= 2100 || month > 13 || day >= 32
                || hour > 24 || minute > 60)
            {
                throw std::invalid_argument("Time unit doesnt follow the format yyyymmddhhmm or has an invalid time unit");
            }
        } catch (const std::invalid_argument& e)
    {
        std::cout << "ERROR: " << e.what() << std::endl;
    }

}