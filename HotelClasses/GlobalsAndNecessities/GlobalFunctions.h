#ifndef COASTALOASIS_GLOBALFUNCTIONS_H
#define COASTALOASIS_GLOBALFUNCTIONS_H
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

namespace myGlobalFunctions
{
   static std::string subtractTime(const std::string& time1, const std::string& time2) {
        int year1 = std::stoi(time1.substr(0, 4));
        int year2 = std::stoi(time2.substr(0, 4));
        int month1 = std::stoi(time1.substr(4, 2));
        int month2 = std::stoi(time2.substr(4, 2));
        int day1 = std::stoi(time1.substr(6, 2));
        int day2 = std::stoi(time2.substr(6, 2));
        int hour1 = std::stoi(time1.substr(8, 2));
        int hour2 = std::stoi(time2.substr(8, 2));
        int minute1 = std::stoi(time1.substr(10, 2));
        int minute2 = std::stoi(time2.substr(10, 2));

        int diffYear = year1 - year2;
        int diffMonth = month1 - month2;
        int diffDay = day1 - day2;
        int diffHour = hour1 - hour2;
        int diffMinute = minute1 - minute2;

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

        std::string result = std::to_string(diffYear) + std::to_string(diffMonth) + std::to_string(diffDay) + std::to_string(diffHour) + std::to_string(diffMinute);
        return result;
    }

    static std::string getCurrentDateTime() {
        auto now = std::time(nullptr);
        auto localtime = std::localtime(&now);

        std::stringstream ss;
        ss << std::put_time(localtime, "%Y%m%d %H%M");
        return ss.str();
    }




}

#endif
