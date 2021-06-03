#include "../Calendar/CCalendar.h"

class CRepeat {
public:
    /**
     * This method repeat event, which user will choose using id of event.
     * Is possible to repeat event by days, by month, by weeks and by years.
     * How many times to repeat event user writes. Maximum is 30 times.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return if all is OK
     * @return if something went wrong
     */
    int repeatEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);
};


