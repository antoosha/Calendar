#include "CMonthly.h"

using namespace std;


//need to change to ostream(not to COUT!)
void CMonthly::show(ostream &m_Out, CCalendar & cCalendar) const {
    CDate cDate = {};

    m_Out << endl;
    m_Out << "          Calendar - " << year << endl;
    int days;

    // Index of the day from 0 to 6
    //using for spaces "   "
    int current = cDate.dayNumber(1, month, year);

    // j --> Iterate through all the days of the
    //       month - i
    int i = month - 1;
    days = cDate.numberOfDays(i, year);

    // Print the current month name
    m_Out << endl;
    m_Out << "  ";
    for(size_t k = 0 ; k < 33; k++){
        if(k == (33/2 - cDate.getMonthName(i).size()/2)){
            m_Out << cDate.getMonthName(i);
            k+=cDate.getMonthName(i).size();
        }
        m_Out << "-";
    }
    m_Out << endl;

    // Print the columns
    m_Out << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

    // Print appropriate spaces
    int k;
    for (k = 0; k < current; k++) {
        m_Out << "     ";
    }

    for (int j = 1; j <= days; j++) {

        printf("%5d", j);

        if (++k > 6) {
            k = 0;
            m_Out << endl;
        }
    }

    if (k) m_Out << endl;

    // Print events from this month
    bool hasBeenWritten = false;
    m_Out << endl;
    for(auto l = cCalendar.returnMapByDate().begin(); l != cCalendar.returnMapByDate().end(); l++){
        if( //for a year
            (l->second->returnDateFrom().returnYear() < year && l->second->returnDateTo().returnYear() > year)
            ||
            //for a month
            (l->second->returnDateFrom().returnYear() < year && l->second->returnDateTo().returnYear() == year &&
             l->second->returnDateTo().returnMonth()-1 >= i)
            ||
            (l->second->returnDateFrom().returnYear() == year && l->second->returnDateTo().returnYear() > year &&
             l->second->returnDateFrom().returnMonth()-1 <= i)
            ||
            (l->second->returnDateFrom().returnMonth()-1 <= i && l->second->returnDateTo().returnMonth()-1 >= i &&
             l->second->returnDateFrom().returnYear() == year && l->second->returnDateTo().returnYear() == year))
        {
            hasBeenWritten = true;
            l->second->printFunc(m_Out);
        }
    }
    if(!hasBeenWritten) m_Out << "    Any events has not been found." << endl;
    m_Out << endl;
}

int CMonthly::setup(istream &m_In, ostream &m_Out) {
    m_Out << "Write year, you want to show:" << endl;
    m_In >> year;

    if(year < 1600 || year > 9999 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Year is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    m_Out << "Write month, you want to show:" << endl;
    m_In >> month;

    if(month < 1 || month > 12 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Month is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}
