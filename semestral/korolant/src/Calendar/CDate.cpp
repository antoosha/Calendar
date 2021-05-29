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

std::string CDate::dateToString() const {
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

void CDate::moveMinutes(int minutes) {
    if(minute + minutes > 59){
        moveHours(1);
        minute = 60- (minute + minutes);
        if(minute < 0) minute*=-1;
    }
    else{
        minute += minutes;
    }
}

void CDate::moveHours(int hours) {
    if(hour + hours > 23){
        moveDays(1);
        hour = 24 - (hour + hours);
        if(hour < 0) hour*=-1;
    }
    else{
        hour += hours;
    }
}

void CDate::moveDays(int days) {
    if(day + days > numberOfDays(month-1, year)){
        day = (numberOfDays(month-1, year) - (day + days));
        moveMonths(1);
        if(day < 0) day*=-1;
    }
    else{
        day += days;
    }
}

void CDate::moveMonths(int months) {

    if(month + months > 12){
        moveYears(1);
        month = 12 - (month + months);
        if(month < 0) month*=-1;

    }
    else{
        month += months;
    }
    if(day > numberOfDays(month-1,year)){
        int were = day;
        int became =  numberOfDays(month-1,year);
        //were 31 became 30
        if(were == 31 && became == 30){
            moveMonths(1);
            day = 1;
        }
            //were 31 became 29
        else if(were == 31 && became == 29){
            moveMonths(1);
            day = 2;
        }
            //were 31 became 28
        else if(were == 31 && became == 28){
            moveMonths(1);
            day = 3;
        }
            //were 30 became 29
        else if(were == 30 && became == 29){
            moveMonths(1);
            day = 1;
        }
            //were 30 became 28
        else if(were == 30 && became == 28){
            moveMonths(1);
            day = 2;
        }
            //were 29 became 28
        else if(were == 29 && became == 28){
            moveMonths(1);
            day = 1;
        }
    }
}

void CDate::moveYears(int years) {
    if(month == 2){
        if((numberOfDays(2, year) != numberOfDays(2, year + years)) && day == 29){
            year += years;
            month++;
            day = 1;
        }
        else{
            year += years;
        }

    }
    else{
        year += years;
    }
}

void CDate::moveMinutesBack(int minutes) {
    if(minute - minutes < 0){
        moveHoursBack(1);
        minute = 60 + minute - minutes;
    }
    else{
        minute-=minutes;
    }
}

void CDate::moveHoursBack(int hours) {
    if(hour - hours < 0){
        moveDaysBack(1);
        hour = 24 + hour - hours;
    }
    else{
        hour-=hours;
    }
}

void CDate::moveDaysBack(int days) {

    if(day - days < 1){
        moveMonthsBack(1); // true poradi
        day = numberOfDays(month-1, year) + day - days;
    }
    else{
        day-=days;
    }
}

void CDate::moveMonthsBack(int months) {
    if(month - months < 1){
        moveYearsBack(1);
        month = 12 + month - months ;

    }
    else{
        month-=months;
    }
    if(day > numberOfDays(month-1,year)){
        int were = day;
        int became =  numberOfDays(month-1,year);
        //were 31 became 30
        if(were == 31 && became == 30){
            moveMonthsBack(1);
            day = numberOfDays(month-1, year);
        }
            //were 31 became 29
        else if(were == 31 && became == 29){
            moveMonthsBack(1);
            day =  numberOfDays(month-1, year) - 1;
        }
            //were 31 became 28
        else if(were == 31 && became == 28){
            moveMonthsBack(1);
            day =  numberOfDays(month-1, year) - 2 ;
        }
            //were 30 became 29
        else if(were == 30 && became == 29){
            moveMonthsBack(1);
            day =  numberOfDays(month-1, year);
        }
            //were 30 became 28
        else if(were == 30 && became == 28){
            moveMonthsBack(1);
            day =  numberOfDays(month-1, year) - 1;
        }
            //were 29 became 28
        else if(were == 29 && became == 28){
            moveMonthsBack(1);
            day =  numberOfDays(month-1, year) ;
        }
    }
}

void CDate::moveYearsBack(int years) {
    if(month == 2){
        if((numberOfDays(2, year) != numberOfDays(2, year - years)) && day == 29){
            year -= years;
            month--;
            day = 31;
        }
        else{
            year -= years;
        }
    }
    else{
        year -= years;
    }
}

/*
CDate::CDate(const string &dateIn) : date(dateIn) {}
 }

std::string CDate::returnDate() const {
    return date;
}
*/

