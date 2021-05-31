#include "CWeekly.h"
#include <chrono>
using namespace std;

void CWeekly::show(ostream &m_Out, CCalendar & cCalendar) const {
    CDate cDate = {};

    int dayFrom = -1;
    int dayLast = -1;
    if(week == 1){
        dayFrom = 1;
        dayLast = 7;
    }
    else if(week == 2){
        dayFrom = 8;
        dayLast = 14;
    }
    else if(week == 3){
        dayFrom = 15;
        dayLast = 21;
    }
    else if(week == 4){
        dayFrom = 22;
        dayLast = 28;
    }
    else if(week == 5){
        dayFrom = 29;
        dayLast = cDate.numberOfDays(month-1, year);
    }
    for(int i = dayFrom; (i <= cDate.numberOfDays(month-1, year) && i <dayFrom+7 ); i++ ){
        int dayOfWeek = cDate.dayNumber(i,month-1,year);
        if(dayOfWeek == 0){
            m_Out<<"[Sun]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 1){
            m_Out<<"[Mon]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 2){
            m_Out<<"[Tue]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 3){
            m_Out<<"[Wed]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 4){
            m_Out<<"[Thu]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 5){
            m_Out<<"[Fri]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
        else if(dayOfWeek == 6){
            m_Out<<"[Sat]";
            printf("[%02d/%02d/%04d]", i,month,year);
            m_Out << endl;
            continue;
        }
    }
    m_Out << "Events for this week:" << endl;


    // Print events from this month
    m_Out << endl;
    for(auto l = cCalendar.returnMapByDate().begin(); l != cCalendar.returnMapByDate().end(); l++){
        CDate cDate = {};
        string from = cDate.dateToShortString(l->second->returnDateFrom().returnYear(), l->second->returnDateFrom().returnMonth(), l->second->returnDateFrom().returnDay());
        string to = cDate.dateToShortString(l->second->returnDateTo().returnYear(), l->second->returnDateTo().returnMonth(), l->second->returnDateTo().returnDay());;
        string currFirst = cDate.dateToShortString(year, month, dayFrom);
        string currLast = cDate.dateToShortString(year, month, dayLast);
        if((currFirst >= from && currFirst <= to) || (currLast >= from && currLast <= to) )
        {
            l->second->printFunc(m_Out);
        }
    }
    m_Out << endl;
}

int CWeekly::setup(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    m_Out << "Write year, you want to show:" << endl;
    m_In >> year;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(year < 1600){
        m_Out << "Year is not correct, try again.." << endl;
        return -4;
    }
    m_Out << "Write month, you want to show:" << endl;
    m_In >> month;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(month < 1 || month > 12){
        m_Out << "Month is not correct, try again.." << endl;
        return -4;
    }
    m_Out << "Write week, you want to show:" << endl;
    m_In >> week;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    CDate cDate = {};
    if(week < 1 || week > 5 || (cDate.numberOfDays(month-1, year) < 29 && week == 5)){
        m_Out << "Week is not correct, try again.." << endl;
        return -4;
    }

    return 0;
}
