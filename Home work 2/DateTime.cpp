#include "DateTime.hpp"
#include <iostream>
#include <sstream>

DateTime::DateTime(int day, int month, int year, int hours, int minutes, int seconds)
    : date(day, month, year), time(hours, minutes, seconds) {}

void DateTime::addSeconds(int seconds) {
    time.addSeconds(seconds);
    if (seconds >= 86400) {
        date.addDays(seconds / 86400);
    }
}

int DateTime::differenceInSeconds(const DateTime& other) const {
    int dateDiff = date.daysBetween(other.date) * 86400;
    int timeDiff = time.secondsBetween(other.time);
    return dateDiff + timeDiff;
}

std::string DateTime::format(const std::string& formatString) const {
    std::ostringstream oss;
    for (size_t i = 0; i < formatString.length(); ++i) {
        if (formatString[i] == 'Y' && i + 3 < formatString.length() && formatString.substr(i, 4) == "YYYY") {
            oss << date.toString().substr(0, 4);
            i += 3;
        }
        else if (formatString[i] == 'M' && i + 1 < formatString.length() && formatString.substr(i, 2) == "MM") {
            oss << date.toString().substr(5, 2);
            i += 1;
        }
        else if (formatString[i] == 'D' && i + 1 < formatString.length() && formatString.substr(i, 2) == "DD") {
            oss << date.toString().substr(8, 2);
            i += 1;
        }
        else if (formatString[i] == 'H' && i + 1 < formatString.length() && formatString.substr(i, 2) == "HH") {
            oss << time.toString().substr(0, 2);
            i += 1;
        }
        else if (formatString[i] == 'm' && i + 1 < formatString.length() && formatString.substr(i, 2) == "MM") {
            oss << time.toString().substr(3, 2);
            i += 1;
        }
        else if (formatString[i] == 'S' && i + 1 < formatString.length() && formatString.substr(i, 2) == "SS") {
            oss << time.toString().substr(6, 2);
            i += 1;
        }
        else {
            oss << formatString[i];
        }
    }
    return oss.str();
}
