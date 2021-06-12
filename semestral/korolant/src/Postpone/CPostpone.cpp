#include "CPostpone.h"
using namespace std;

int CPostpone::moveEvent(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    int idToMove;
    m_Out << "Write id of event you want to move and press 'Enter':" << endl;
    m_In >> idToMove;
    if(m_In.eof()){
        return -3;
    }

    if(idToMove < 0 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "ID should be greater than 0, try again.."  << endl;
        return -4;
    }
    if(!cCalendar.returnMapById().count(idToMove) || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Event with id " << idToMove << " does not exist, try again.."  << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    int numberForWay;
    m_Out << "Choose number what you want to move and press 'Enter':" << endl;
    m_Out << "1) Rewind date forward" << endl;
    m_Out << "2) Rewind date back" << endl;
    m_In >> numberForWay;
    if(m_In.eof()){
        return -3;
    }

    if((numberForWay != 1 && numberForWay != 2) || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    int number;
    m_Out << "Choose number what you want to move and press 'Enter':" << endl;
    m_Out << "1) Minutes (1 to 59 minutes)" << endl;
    m_Out << "2) Hours (1 to 23 hours)" << endl;
    int minOfDaysFirstOrLastMonth;
    if(cCalendar.returnMapById().at(idToMove)->returnDateFrom().numberOfDays(cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnMonth()-1,
                                                                             cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnYear())
       >
       cCalendar.returnMapById().at(idToMove)->returnDateTo().numberOfDays(cCalendar.returnMapById().at(idToMove)->returnDateTo().returnMonth()-1,
                                                                           cCalendar.returnMapById().at(idToMove)->returnDateTo().returnYear())){
        minOfDaysFirstOrLastMonth = cCalendar.returnMapById().at(idToMove)->returnDateTo().numberOfDays(cCalendar.returnMapById().at(idToMove)->returnDateTo().returnMonth()-1,
                                                                                                        cCalendar.returnMapById().at(idToMove)->returnDateTo().returnYear());
    }
    else{
        minOfDaysFirstOrLastMonth = cCalendar.returnMapById().at(idToMove)->returnDateFrom().numberOfDays(cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnMonth()-1,
                                                                                                          cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnYear());
    }
    m_Out << "3) Days (1 to " << (minOfDaysFirstOrLastMonth-1) << ")"<< endl;
    m_Out << "4) Months (1 to 11 months)" << endl;
    m_Out << "5) Years"<< endl;
    m_Out << "6) Move this event to the nearest working day with same time (Monday, Tuesday, Wednesday, Thursday, Friday)"<< endl;
    m_In >> number;
    if(m_In.eof()){
        return -3;
    }

    if(number < 1 || number > 6 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    if(number == 1 ){
        int minutes;
        m_Out << "Write for how many minutes you want to move event and press 'Enter':" << endl;
        m_In >> minutes;
        if(m_In.eof()){
            return -3;
        }

        if(minutes < 1 || minutes > 59 || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Minutes should be between 1 to 59, try again.." << endl;
            return -4;
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');

        if(numberForWay == 1){
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveMinutes(minutes);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveMinutes(minutes);
        }
        else{
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveMinutesBack(minutes);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveMinutesBack(minutes);
        }

    }
    else if(number == 2){
        int hours;
        m_Out << "Write for how many hours you want to move event and press 'Enter':" << endl;
        m_In >> hours;
        if(m_In.eof()){
            return -3;
        }

        if(hours < 1 || hours > 23 || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Hours should be between 1 to 23, try again.." << endl;
            return -4;
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');

        if(numberForWay == 1){
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveHours(hours);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveHours(hours);
        }
        else{
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveHoursBack(hours);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveHoursBack(hours);
        }

    }
    else if(number == 3){
        int days;
        m_Out << "Write for how many days you want to move event and press 'Enter':" << endl;
        m_In >> days;
        if(m_In.eof()){
            return -3;
        }

        if(days < 1 || days > minOfDaysFirstOrLastMonth - 1 || m_In.fail() ){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Days should be between 1 to " << minOfDaysFirstOrLastMonth-1  << ", try again.." << endl;
            return -4;
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');

        if(numberForWay == 1){
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveDays(days);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveDays(days);
        }
        else{
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveDaysBack(days);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveDaysBack(days);
        }

    }
    else if(number == 4){
        int months;
        m_Out << "Write for how many months you want to move event and press 'Enter':" << endl;
        m_In >> months;
        if(m_In.eof()){
            return -3;
        }

        if(months < 1 || months > 11 || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Months should be between 1 to 11, try again.." << endl;
            return -4;
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');

        if(numberForWay == 1){
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveMonths(months);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveMonths(months);
        }
        else{
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveMonthsBack(months);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveMonthsBack(months);
        }
    }
    else if(number == 5){
        int years;
        m_Out << "Write for how many years you want to move event and press 'Enter':" << endl;
        m_In >> years;
        if(m_In.eof()){
            return -3;
        }

        if(years < 0 || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Year should be positive, try again.." << endl;
            return -4;
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');

        if(numberForWay == 1){
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveYears(years);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveYears(years);
        }
        else{
            if(years >  cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnYear() ){
                m_Out << "Year should be less than year of event, try again.." << endl;
                return -4;
            }
            cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveYearsBack(years);
            cCalendar.returnMapById().at(idToMove)->returnDateTo().moveYearsBack(years);
        }

    }
    else if(number == 6 && numberForWay == 1){
        int dayNumber = cCalendar.returnMapById().at(idToMove)->returnDateFrom().dayNumber(cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnDay(),
                                                                                           cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnMonth(),
                                                                                           cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnYear());
        int howManyDaysToMove;
        if(dayNumber == 1 || dayNumber == 2 || dayNumber == 3 || dayNumber == 4 || dayNumber == 7) howManyDaysToMove = 1;
        else if(dayNumber == 5) howManyDaysToMove = 3;
        else if(dayNumber == 6) howManyDaysToMove = 2;
        else{
            m_Out << "Something went wrong.. try again.." << endl;
            return -4;
        }
        cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveDays(howManyDaysToMove);
        cCalendar.returnMapById().at(idToMove)->returnDateTo().moveDays(howManyDaysToMove);
    }
    else if(number == 6 && numberForWay == 2){
        int dayNumber = cCalendar.returnMapById().at(idToMove)->returnDateFrom().dayNumber(cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnDay(),
                                                                                           cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnMonth(),
                                                                                           cCalendar.returnMapById().at(idToMove)->returnDateFrom().returnYear());
        int howManyDaysToMoveBack;
        if(dayNumber == 2 || dayNumber == 3 || dayNumber == 4 || dayNumber == 5 || dayNumber == 6 ) howManyDaysToMoveBack = 1;
        else if(dayNumber == 1) howManyDaysToMoveBack = 3;
        else if(dayNumber == 7) howManyDaysToMoveBack = 2;
        else{
            m_Out << "Something went wrong.. try again.." << endl;
            return -4;
        }
        cCalendar.returnMapById().at(idToMove)->returnDateFrom().moveDaysBack(howManyDaysToMoveBack);
        cCalendar.returnMapById().at(idToMove)->returnDateTo().moveDaysBack(howManyDaysToMoveBack);
    }
    m_Out << "Event has been moved." << endl;
    return 0;
}
