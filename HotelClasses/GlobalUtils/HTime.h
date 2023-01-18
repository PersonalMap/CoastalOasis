#ifndef COASTALOASIS_TIME_H
#define COASTALOASIS_TIME_H
#include <vector>
#include <map>


class HTime {

private:

   unsigned int _year;
   unsigned int _month;
   unsigned int _day;
   unsigned int _hour;
   unsigned int _minute;

public:

    ///constructors
    HTime();
    HTime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute);
    ~HTime();

    ///GETTER & SETTERS

    const std::pair<unsigned int&, unsigned int&> getHourMinute(){return std::pair<unsigned int&, unsigned int&>(_hour, _minute);}
    const std::pair<unsigned int&, unsigned int&> getMonthDay(){return std::pair<unsigned int&, unsigned int&>(_month, _day);}

    std::string getFullDateString(); // with seconds minutes
    std::string getDateString(); //without seconds minutes
    ///operators
    HTime operator-(const HTime &time2) const;
    HTime operator+(const HTime &time2) const;

    friend std::ostream& operator<< (std::ostream& o, const HTime& t);

    ///Functions

};
#endif //COASTALOASIS_TIME_H
