#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "../Calendar/CCalendar.h"


class CView {
public:

    virtual void show(std::ostream & os, CCalendar & cCalendar) const = 0;

    //TODO in all classes do osetreseni vstupu like in CCalendar
    virtual int setup( std::istream & in, std::ostream & os, CCalendar & cCalendar) = 0;

protected:
    int day;
    int month;
    int year;
    int week;

};



