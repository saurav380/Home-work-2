#ifndef TIME_HPP
#define TIME_HPP

#include <string>

class Time {
private:
    int hours, minutes, seconds;

public:
    Time(int hours = 0, int minutes = 0, int seconds = 0);
    void addSeconds(int seconds);
    int secondsBetween(const Time& other) const;
    std::string toString() const;
};

#endif // TIME_HPP
