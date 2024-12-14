#include "Time.hpp"
#include <iostream>
#include <sstream>

Time::Time(int hours, int minutes, int seconds) : hours(hours), minutes(minutes), seconds(seconds) {}

void Time::addSeconds(int seconds) {
    this->seconds += seconds;
    while (this->seconds >= 60) {
        this->seconds -= 60;
        minutes++;
    }
    while (minutes >= 60) {
        minutes -= 60;
        hours++;
    }
    hours %= 24; // Ensure hours wrap around
}

int Time::secondsBetween(const Time& other) const {
    return ((other.hours - hours) * 3600) + ((other.minutes - minutes) * 60) + (other.seconds - seconds);
}

std::string Time::toString() const {
    std::ostringstream oss;
    oss << (hours < 10 ? "0" : "") << hours << ":"
        << (minutes < 10 ? "0" : "") << minutes << ":"
        << (seconds < 10 ? "0" : "") << seconds;
    return oss.str();
}
