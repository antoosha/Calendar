#include "CDaily.h"
using namespace std;

void CDaily::show(ostream &m_Out, CCalendar & cCalendar) const {
    m_Out << endl;
    CDate cDate = {};
    m_Out << "Events for a";
    int dayNumber = cDate.dayNumber(day, month, year);
    if(dayNumber == 0){
        m_Out << " sunday ";
    }
    else if(dayNumber == 1){
        m_Out << " monday ";
    }
    else if(dayNumber == 2){
        m_Out << " tuesday ";
    }
    else if(dayNumber == 3){
        m_Out << " wednesday ";
    }
    else if(dayNumber == 4){
        m_Out << " thursday ";
    }
    else if(dayNumber == 5){
        m_Out << " friday " ;
    }
    else if(dayNumber == 6){
        m_Out << " saturday ";
    }
    printf(" %02d/%02d/%04d:\n", day, month, year);
    bool hasBeenWritten = false;
    for(auto l = cCalendar.returnMapByDate().begin(); l != cCalendar.returnMapByDate().end(); l++){
        string from = cDate.dateToShortString(l->second->returnDateFrom().returnYear(), l->second->returnDateFrom().returnMonth(), l->second->returnDateFrom().returnDay());
        string to = cDate.dateToShortString(l->second->returnDateTo().returnYear(), l->second->returnDateTo().returnMonth(), l->second->returnDateTo().returnDay());;
        string curr = cDate.dateToShortString(year, month, day);
        if(curr >= from && curr <= to)
        {
            hasBeenWritten = true;
            l->second->printFunc(m_Out);
        }
    }
    if(!hasBeenWritten) m_Out << "Any events have not been found." << endl;
    m_Out << endl;
}

int CDaily::setup(istream &m_In, ostream &m_Out) {
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

    m_Out << "Write day, you want to show:" << endl;
    m_In >> day;
    if(m_In.eof()){
        return -3;
    }
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


int CDaily::navigation(std::istream &m_In, std::ostream &m_Out) {
    int flagNavigation = 0;
    CDate cDate = {};
    while(true) {
        m_Out << "++++++++++++++++++++++| Navigation |++++++++++++++++++++++" << endl;
        m_Out << "| Choose variant you want to do, write and click 'Enter' |" << endl;
        m_Out << "|                   1 -> Next day <- 1                   |" << endl;
        m_Out << "|                 2 -> Previous day <- 2                 |" << endl;
        m_Out << "|               3 -> Close navigation <- 3               |" << endl;
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
            if(cDate.numberOfDays(month-1, year) == day){ //last day in month
                day = 1;
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
                day++;
                return 1; // do sho
            }

        }
        if(number == 2){
            if(day == 1){
                if(month == 1){
                    if(year > 1600){
                        month = 12;
                        year--;
                        day = cDate.numberOfDays(month - 1, year); // last day
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
                    day = cDate.numberOfDays(month - 1, year); // last day
                    return 1; // do show
                }
            }
            else{
                day--;
                return 1; // do show
            }

        }
        if(number == 3){
            m_Out << "Navigation has been closed." << endl;
            return 0; //close
        }
    }
}





