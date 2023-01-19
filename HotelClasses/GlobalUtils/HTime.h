#ifndef COASTALOASIS_TIME_H
#define COASTALOASIS_TIME_H
#include <vector>
#include <map>
#include <string>


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
    explicit HTime(const std::string& data);
    ~HTime();

    ///GETTER & SETTERS

    std::pair<unsigned int&, unsigned int&> getHourMinute() {return std::pair<unsigned int&, unsigned int&>(_hour, _minute);}
    std::pair<unsigned int&, unsigned int&> getMonthDay() {return std::pair<unsigned int&, unsigned int&>(_month, _day);}
    const unsigned int& getYear() const{return this->_year;}
    const unsigned int& getMonth() const{return this->_month;}
    const unsigned int& getDay() const{return this->_day;}
    const unsigned int& getHour() const{return this->_hour;}
    const unsigned int& getMinute() const{return this->_minute;}
    long long getAsNumbers() const{return std::stoll(getRawFullDateString());}

    std::string getDebugFullDateString() const; // with seconds minutes + contains '/'
    std::string getDebugDateString() const; //without seconds minutes + contains '/'
    std::string getRawFullDateString() const; //pure numbers
    std::string getRawDateString() const; //pure numbers - hour & minute
    std::string getRawHourMinute() const; // pure numbers - only hour & minute


    ///operators
    HTime operator-(const HTime &time2) const;
    HTime operator+(const HTime &time2) const;

    friend std::ostream& operator<< (std::ostream& o, const HTime& t);

    ///Functions
    static void errorCheckTime(const std::string& dataString);//error checking time

};
#endif
