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
/*
CDate::CDate(const string &dateIn) : date(dateIn) {}
 }

std::string CDate::returnDate() const {
    return date;
}
*/

