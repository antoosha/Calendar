#pragma once
#include <iostream>
#include <string>
#include "../Calendar/CCalendar.h"

class CView {
public:

    virtual ~CView() = default;

    /**
     * This method is overwritten by CDaily(show for a day), CWeekly(show for a week),
     *  CMonthly(show for a month), CYearly(show for a year) and represents day/week/month/year with events in it.
     *
     * @param os is output stream
     * @param cCalendar is reference to an object of CCalendar
     */
    virtual void show(std::ostream & os, CCalendar & cCalendar) const = 0;

    /**
     * This method write and save parameters from user. Then this parameters uses method show. How many and what
     * parameters will be written depends on "how user want to show events"
     * This virtual method is overwritten by CDaily(show for a day), CWeekly(show for a week),
     *  CMonthly(show for a month), CYearly(show for a year). Each of classes needs own setup.
     *
     * @param in is input stream
     * @param os is output stream
     * @return 0 is all is OK
     * @return -4 is input is not correct
     */
    virtual int setup( std::istream & in, std::ostream & os) = 0;

protected:
    int day;
    int month;
    int year;
    int week;

};



