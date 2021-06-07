#pragma once
#include <iostream>
#include <string>
#include "../Calendar/CCalendar.h"

/**
 * This abstract class represents a view of show events in calendar. There different ways to show events and show calendar.
 */
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
     * This method writes and save parameters from user. Then this parameters uses method show. How many and what
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

    /**
     * This method works as navigation, it will ask user what to do next, there are 3 commands:
     * 1)Go forward
     * 2)Go back
     * 3)Close navigation
     *
     * @param in is input stream
     * @param os is output stream
     * @return 1 user want to navigate in calendar
     * @return 0 user want to close navigation
     * @return -4 something went wrong(ussualy 3/3 tries from user or year < 1600 or number is wrong not(1 or 2 or 3))
     */
    virtual int navigation( std::istream & in, std::ostream & os) = 0;



protected:
    int day;
    int month;
    int year;
    int week;

};



