#include "CDate.h"

CDate::CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn)
             : day(dayIn), month(monthIn), year(yearIn), hour(hourIn), minute(minuteIn) {}

void CDate::editDate(const CDate & dateFrom, const CDate & dateTo) {
    //TODO
}

int CDate::returnDay() const {
    return day;
}

int CDate::returnMonth() const {
    return month;
}

int CDate::returnYear() const {
    return year;
}

