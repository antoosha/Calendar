#include "CDaily.h"
using namespace std;

void CDaily::show(ostream &m_Out, CCalendar & cCalendar) const {
    printf("Events for a %02d/%02d/%04d:\n", day, month, year);
    for(auto l = cCalendar.returnMapByDate().begin(); l != cCalendar.returnMapByDate().end(); l++){
        CDate cDate = {};
        string from = cDate.dateToShortString(l->second->returnDateFrom().returnYear(), l->second->returnDateFrom().returnMonth(), l->second->returnDateFrom().returnDay());
        string to = cDate.dateToShortString(l->second->returnDateTo().returnYear(), l->second->returnDateTo().returnMonth(), l->second->returnDateTo().returnDay());;
        string curr = cDate.dateToShortString(year, month, day);
        if(curr >= from && curr <= to)
        {
            l->second->printFunc(m_Out);
        }
    }
    m_Out << endl;
}

int CDaily::setup(istream &m_In, ostream &m_Out) {
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

    m_Out << "Write day, you want to show:" << endl;
    m_In >> day;
    CDate cDate = {};

    if(day > cDate.numberOfDays(month-1, year || m_In.fail())){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Day is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    return 0;
}




