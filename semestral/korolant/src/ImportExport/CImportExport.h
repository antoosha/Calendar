#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>

#include "../Calendar/CCalendar.h"
class CImportExport {
public:
    /**
     * This method imports data to calendar.
     * Works like createEvent in CCalendar, but does not have outputs when imports data.
     * Has some outputs before importing will be started.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 if all is OK
     * @return -4 if something went wrong(ussualy, uncorrect input from user(id does not exist) or file has not been opened)
     */
    int importData(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) ;

    /**
     * This method export data to file, path to file user will write, from calendar using method to print events from CEvent.
     *
     * @param in is input stream
     * @param out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 is all is OK
     * @return -4 if something went wrong(ussualy, uncorrect input from user(id does not exist) or file has not been opened)
     */
    int exportData(std::istream & in, std::ostream & out, CCalendar & cCalendar) const;
};


