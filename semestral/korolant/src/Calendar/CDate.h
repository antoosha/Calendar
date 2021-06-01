#pragma once
#include <memory>
#include <string>

class CDate {
public:

    CDate() = default;

    CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn );

    void editDate(const CDate & date);

    std::string dateToString() const;

    int dayNumber(int day, int month, int year) const;

    void moveMinutes(int minutes);

    void moveHours(int hours);

    void moveDays(int days);

    void moveMonths(int months);

    void moveYears(int years);

    void moveMinutesBack(int minutes);

    void moveHoursBack(int hours);

    void moveDaysBack(int days);

    void moveMonthsBack(int months);

    void moveYearsBack(int years);

    std::string getMonthName(int monthNumber) const;

    int numberOfDays (int monthNumber, int year) const;

    std::string dateToShortString(int yearIn, int monthIn, int dayIn) const;

    int returnDay() const;

    int returnMonth() const;

    int returnYear() const;

    int returnHour() const;

    int returnMinute() const;

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;

};


