#pragma once
#include <iostream>
#include <string>
#include "../Calendar/CCalendar.h"

class CView {
public:

    virtual void show(std::ostream & os, CCalendar & cCalendar) const = 0;

    virtual int setup( std::istream & in, std::ostream & os) = 0;

protected:
    int day;
    int month;
    int year;
    int week;

};



