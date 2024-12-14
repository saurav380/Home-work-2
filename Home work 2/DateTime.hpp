#ifndef DATETIME_HPP
#define DATETIME_HPP

#include "Date.hpp"
#include "Time.hpp"

class DateTime {
private:
    Date date;
    Time time;

public:
    DateTime(int day, int month, int year, int hours, int minutes, int seconds);
    void addSeconds(int seconds);
    int differenceInSeconds(const DateTime& other) const;
    std::string format(const std::string& formatString) const;
};

#endif // DATETIME_HPP
