#ifndef DATE_HPP
#define DATE_HPP

#include <string>

class Date {
private:
    int day, month, year;

public:
    Date(int day = 1, int month = 1, int year = 2000);
    void addDays(int days);
    void addMonths(int months);
    void addYears(int years);
    int daysBetween(const Date& other) const;
    std::string toString() const;
};

#endif // DATE_HPP
