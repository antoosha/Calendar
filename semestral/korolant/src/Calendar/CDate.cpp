#include "CDate.h"

CDate::CDate(const int & day, const int & month, const int & year)
             : day(day), month(month), year(year) {}

void CDate::editDate(const std::shared_ptr<CDate> &dateFrom, const std::shared_ptr<CDate> &dateTo) {
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

