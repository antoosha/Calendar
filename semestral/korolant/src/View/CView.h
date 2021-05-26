#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "../Calendar/CCalendar.h"

class CView {
public:
    //virtual void show(std::ostream & os, const CCalendar & cCalendar) const;

    int dayNumber(int day, int month, int year) const{
        static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
        year -= month < 3;
        return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
    }

    std::string getMonthName(int monthNumber) const {
        std::string months[] = {"January", "February", "March",
                           "April", "May", "June",
                           "July", "August", "September",
                           "October", "November", "December"
        };

        return (months[monthNumber]);
    }

    int numberOfDays (int monthNumber, int year) const {
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

};



