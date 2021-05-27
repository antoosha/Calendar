#include "CDate.h"
using namespace std;

CDate::CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn)
             : day(dayIn), month(monthIn), year(yearIn), hour(hourIn), minute(minuteIn) {};

int CDate::returnDay() const {
    return day;
}

int CDate::returnMonth() const {
    return month;
}

int CDate::returnYear() const {
    return year;
}



 void CDate::editDate(const CDate & date) {
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    this->hour = date.hour;
    this->minute = date.minute;
}

std::string CDate::dateToString() {
    string dateToString;
    dateToString = to_string(year) + to_string(month) + to_string(day) + to_string(hour) + to_string(minute);
    return dateToString;
}

int CDate::dayNumber(int day, int month, int year) const {
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int CDate::numberOfDays(int monthNumber, int year) const {
    // January
    if (monthNumber == 0)
        return (31);

    // February
    if (monthNumber == 1)
    {
        // If the year is leap then February has
        // 29 days
        if (year % 400 == 0 ||
            (year % 4 == 0 && year % 100 != 0))
            return (29);
        else
            return (28);
    }

    // March
    if (monthNumber == 2)
        return (31);

    // April
    if (monthNumber == 3)
        return (30);

    // May
    if (monthNumber == 4)
        return (31);

    // June
    if (monthNumber == 5)
        return (30);

    // July
    if (monthNumber == 6)
        return (31);

    // August
    if (monthNumber == 7)
        return (31);

    // September
    if (monthNumber == 8)
        return (30);

    // October
    if (monthNumber == 9)
        return (31);

    // November
    if (monthNumber == 10)
        return (30);

    // December
    if (monthNumber == 11)
        return (31);
    return -1;
}

std::string CDate::getMonthName(int monthNumber) const {
    std::string months[] = {"January", "February", "March",
                            "April", "May", "June",
                            "July", "August", "September",
                            "October", "November", "December"
    };

    return (months[monthNumber]);
}

/*
CDate::CDate(const string &dateIn) : date(dateIn) {}
 }

std::string CDate::returnDate() const {
    return date;
}
*/

