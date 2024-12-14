#include "Date.hpp"
#include <iostream>
#include <sstream>

Date::Date(int day, int month, int year) : day(day), month(month), year(year) {}

void Date::addDays(int days) {
    day += days;
    while (day > 30) {  // Simplified: assume 30 days in a month
        day -= 30;
        addMonths(1);
    }
}

void Date::addMonths(int months) {
    month += months;
    while (month > 12) {
        month -= 12;
        addYears(1);
    }
}

void Date::addYears(int years) {
    year += years;
}

int Date::daysBetween(const Date& other) const {
    return ((other.year - year) * 360) + ((other.month - month) * 30) + (other.day - day);
}

std::string Date::toString() const {
    std::ostringstream oss;
    oss << year << "-" << (month < 10 ? "0" : "") << month << "-" << (day < 10 ? "0" : "") << day;
    return oss.str();
}
