#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "../Calendar/CCalendar.h"

class CView {
public:
    //virtual void show(std::ostream & os, const CCalendar & cCalendar) const;

    int dayNumber(int day, int month, int year) const;

    std::string getMonthName(int monthNumber) const;

    int numberOfDays (int monthNumber, int year) const;

};



