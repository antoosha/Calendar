#include "CWeekly.h"
#include <chrono>
using namespace std;

void CWeekly::show(ostream &m_Out, CCalendar & cCalendar) const {
    CDate cDate = {};
    int dayFrom = 1;
    int dayLast = 1;
    int days;

    m_Out << endl;

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
    int k = 0;

    for (k = 0; k < current; k++) {
        if(week == 1) {
            m_Out << "     ";
        }
    }


    int weekFlag = 1;
    for (int j = 1; j <= days; j++) {
        if(weekFlag == week){
            printf("%5d", j);
            dayLast = j; //last j, which we have already written
        }
        if (++k > 6) {
            k = 0;
            weekFlag++;
            if(weekFlag == week){
                dayFrom = j + 1; //+1 because at next cycle j we'l write
            }
        }
    }

    m_Out << endl;

    // Print events from this month
    m_Out << endl;
    bool hasBeenWritten = false;
    for(auto l = cCalendar.returnMapByDate().begin(); l != cCalendar.returnMapByDate().end(); l++){
        CDate cDate = {};
        string from = cDate.dateToShortString(l->second->returnDateFrom().returnYear(), l->second->returnDateFrom().returnMonth(), l->second->returnDateFrom().returnDay());
        string to = cDate.dateToShortString(l->second->returnDateTo().returnYear(), l->second->returnDateTo().returnMonth(), l->second->returnDateTo().returnDay());;
        string currFirst = cDate.dateToShortString(year, month, dayFrom);
        string currLast = cDate.dateToShortString(year, month, dayLast);
        if((from <= currLast && from >= currFirst) || (to >= currFirst && to <= currLast) || (from <= currFirst && to >= currLast))
        {
            hasBeenWritten = true;
            l->second->printFunc(m_Out);
        }
    }
    if(!hasBeenWritten) m_Out << "    Any events have not been found." << endl;
    m_Out << endl;
}

int CWeekly::setup(istream &m_In, ostream &m_Out) {
    m_Out << "Write year, you want to show:" << endl;
    m_In >> year;
    if(m_In.eof()){
        return -3;
    }

    if(year < 1600 || year > 9999 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Year is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    m_Out << "Write month, you want to show:" << endl;
    m_In >> month;
    if(m_In.eof()){
        return -3;
    }

    if(month < 1 || month > 12 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Month is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    m_Out << "Write week, you want to show:" << endl;
    m_In >> week;
    if(m_In.eof()){
        return -3;
    }
    CDate cDate = {};
    if(week < 1 || week > 5 || (cDate.numberOfDays(month-1, year) < 29 && cDate.dayNumber(1,month,year) == 0 && week == 5) || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Week is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    return 0;
}

int CWeekly::navigation(std::istream &m_In, std::ostream &m_Out) {
    int flagNavigation = 0;
    CDate cDate = {};
    while(true) {
        m_Out << "++++++++++++++++++++++| Navigation |++++++++++++++++++++++" << endl;
        m_Out << "| Choose variant you want to do, write and click 'Enter' |" << endl;
        m_Out << "|                   1 -> Next week <- 1                  |" << endl;
        m_Out << "|                 2 -> Previous week <- 2                |" << endl;
        m_Out << "|                3 -> Close navigation <- 3              |" << endl;
        m_Out << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
        int number;
        m_In >> number;
        if(m_In.eof()){
            return -3;
        }

        if (number < 1 || number > 3 || m_In.fail()) {
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            flagNavigation++;
            if(flagNavigation == 3){
                m_Out << "Number is not correct, try " << flagNavigation << "/3. Closing.." << endl;
                return -4; //close with error
            }
            m_Out << "Number is not correct, try " << flagNavigation << "/3, try again.." << endl;
            continue;
        }

        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(number == 1){
            if(week == 4){
                if(cDate.numberOfDays(month-1, year) < 29){
                    week = 1;
                    if(month == 12){
                        month = 1;
                        year++;
                    }
                    else{
                        month++;
                    }
                    return 1; // do show
                }
                else{
                    week = 5;
                    return 1; // do show
                }
            }
            else if(week == 5){
                week = 1;
                if(month == 12){
                    month = 1;
                    year++;
                }
                else{
                    month++;
                }
                return 1; // do show
            }
            else{
                week++;
                return 1; // do show
            }
        }
        if(number == 2){
            if(week == 1){
                if(cDate.numberOfDays(month-1, year) < 29){
                    week = 4;
                }
                else week = 5;

                if(month == 1){
                    if(year > 1600){
                        month = 12;
                        year--;
                        return 1; // do show
                    }
                    else{
                        m_Out << "Year could not be less than 1600." << endl;
                        m_Out << "Closing navigation.." << endl;
                        return 0; //close
                    }
                }
                else{
                    month--;
                    return 1; // do show
                }
            }
            else{
                week--;
                return 1; // do show
            }
        }
        if(number == 3){
            m_Out << "Navigation has been closed." << endl;
            return 0; //close
        }
    }
}