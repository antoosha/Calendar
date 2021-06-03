#pragma once
#include <memory>

#include "../Calendar/CCalendar.h"
#include "../Calendar/CDate.h"

class CPostpone {
public:
    /**
     * This method move event forward or back to a date or for some days/weeks/months/years which user writes.
     * Could postpone event using munites, hours, days, months, years or even to a first working day(Mon, Tue, Wed, Thu, Fri)
     * Could postpone forward or back to time.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 if all is OK
     * @return-4 if something went wrong
     */
    int moveEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);
};


