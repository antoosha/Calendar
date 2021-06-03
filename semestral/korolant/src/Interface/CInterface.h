#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include "../View/CView.h"
#include "../Calendar/CCalendar.h"
#include "../ImportExport/CImportExport.h"
#include "../Postpone/CPostpone.h"
#include "../Repeat/CRepeat.h"

class CInterface {

public:

    /**
     * Constructor of CInterface
     *
     * @param in is input stream
     * @param out  is output stream
     * @param cCalendarIn is a const reference on object of type CCalendar
     */
    CInterface ( std::istream & in, std::ostream & out, const CCalendar & cCalendarIn);

    /**
     * This method decides what to do the next with the command(input from user) stored in the vector "words".
     * If user will write command in expected format, then the method will call other methods,
     * otherwise it will not call any methods and will return -1 or -2 as
     * If in program next something will go wrong, whis method returns -4
     *
     * List of commands, which this method catches.
     * new ...  - create new event.
     * delete ... delete event.
     * listEvents - lists all events from calendar.
     * repeat ... - set repeat for event with user's time interval.
     * move ... - postopne event, which user will choose.
     * findFirstPossible ... - find first possible date to pospone event.
     * showDaily ... - show calendar and all events for day.
     * showWeekly ... - show calendar and all events for week.
     * showMonthly ... - show calendar and all events for month.
     * showYearly ... - show calendar and all events for year.
     * find ... - find event.
     * load [filename] - upload all events from the file called \"filename\".
     * save [filename] - save all events to the file called \"filename\".
     * edit ... - edit event.
     * help - show all commands.
     * quit - end the program.
     *
     * @return 0 = all is OK
     * @return -1 = nothing was written
     * @return -2 = command does not exist
     * @return -3 = command "quit"
     * @return -4 = something went wrong
     */
    int doSmthWithCommand(std::map<std::string, CView*> & views);

    /**
     * This method catches the input from user and put the input to the vector of strings called "words".
     */
    void getCommand();

private:
    std::istream & m_In;
    std::ostream & m_Out;
    /**
     * vector of command(inputs) from user
     */
    std::vector<std::string> words;
    CCalendar cCalendar;
};


