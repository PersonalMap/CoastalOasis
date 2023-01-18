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

    ///operators
    HTime operator-(const HTime &time2) const;
    HTime operator+(const HTime &time2) const;

    friend std::ostream& operator<< (std::ostream& o, const HTime& t);
};
#endif //COASTALOASIS_TIME_H
