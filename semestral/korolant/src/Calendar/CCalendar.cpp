#include "CCalendar.h"


using namespace std;

int CCalendar::createEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {

    CView cView;
    int id;
    string name;
    string dateFromIn;
    string dateToIn;
    string place;
    vector<string> members;
    string description;
    string obligation;
    int dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom;
    int dayTo, monthTo, yearTo, hourTo, minuteTo;

    CDate dateFrom;
    CDate dateTo;


    m_Out << "Write id of this event:" << endl;
    m_In >> id;
    if(cCalendar.returnMapById().count(id) != 0){
        m_Out << "Event with same id exists, try again.." << endl;
        return -4; // something went wrong
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');


    m_Out << "Write name of this event and press 'Enter':" << endl;
    getline(m_In, name);


    /*m_Out << "Write date 'from' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
    getline(m_In, dateFromIn);
    if(dateFromIn.size() != 16){
        m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
        return -4; // something went wrong
    }
    dateFrom = CDate(dateFromIn);*/

    int flagSecondGreaterThanFirst = 0;
    while(flagSecondGreaterThanFirst == 0) {
        int flagDateFrom = 0;
        while (flagDateFrom == 0) {
            m_Out << "Write year of date 'from' and press 'Enter':" << endl;
            m_In >> yearFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (yearFrom < 1600) {
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write month of date 'from' and press 'Enter':" << endl;
            m_In >> monthFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (monthFrom < 1 || monthFrom > 12) {
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write day of date 'from' and press 'Enter':" << endl;
            m_In >> dayFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (dayFrom > cView.numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1) {
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
            m_In >> hourFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (hourFrom > 23 || hourFrom < 0) {
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
            m_In >> minuteFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (minuteFrom > 59 || minuteFrom < 0) {
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }

            dateFrom = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);
            flagDateFrom = 1;
        }


        /*m_Out << "Write date 'to' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
        getline(m_In, dateToIn);
        if(dateToIn.size() != 16){
            m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
            return -4; // something went wrong
        }
        dateTo = CDate(dateToIn);
        */

        int flagDateTo = 0;
        while (flagDateTo == 0) {
            m_Out << "Write year of date 'to' and press 'Enter':" << endl;
            m_In >> yearTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (yearTo < 1600) {
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write month of date 'to' and press 'Enter':" << endl;
            m_In >> monthTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (monthTo < 1 || monthTo > 12) {
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write day of date 'to' and press 'Enter':" << endl;
            m_In >> dayTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (dayTo > cView.numberOfDays(monthTo - 1, yearTo) || dayTo < 1) {
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
            m_In >> hourTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (hourTo > 23 || hourTo < 0) {
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
            m_In >> minuteTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if (minuteTo > 59 || minuteTo < 0) {
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }

            dateTo = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);
            flagDateTo = 1;
        }
        if (dateFrom.dateToString() > dateTo.dateToString()) {
            m_Out << "First date is greater, than second, try again.." << endl;
            continue;
        }
        flagSecondGreaterThanFirst = 1;
    }

    m_Out << "Write place of this event and press 'Enter':" << endl;
    std::getline(m_In, place);

    while(1) {
        char sign;
        m_Out << "If you want to add member, write \"+\" and press 'Enter':" << endl;
        m_Out << "If you DO NOT want to add member, write \"-\" and press 'Enter':" << endl;
        m_In >> sign;
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(sign == '+'){
            m_Out << "Write person, who you want to add to this event and press 'Enter':" << endl;
            string memberIn;
            getline(m_In, memberIn);
            members.emplace_back(memberIn);
            m_Out << "Person " << memberIn << " has been successfully added." << endl;
            continue;
        }
        else{
            break;
        }
    }


    m_Out << "Write description of this event and press 'Enter':" << endl;
    getline(m_In, description);


    m_Out << "Choose obligation of this event, write \"required\" or \"optional\" and press 'Enter':" << endl;
    m_In >> obligation;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(strcasecmp(obligation.c_str(), "required") < 0){
        if(strcasecmp(obligation.c_str(), "optional") < 0){
            m_Out << "You should write obligation in correct format \"required\" or \"optional\", try again.." << endl;
            return -4; // something went wrong
        }
    }


    cCalendar.addEvent(id, name, dateFrom, dateTo, place, members, description, obligation);

    m_Out << "Event has been created." << endl;
    cout << endl;
    (cCalendar.returnMapById()).at(id)->printFunc(cout);
    cout << endl;
    return 0;

}
int CCalendar::editEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {

    int id;
    CView  * cView;
    int dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom;
    int dayTo, monthTo, yearTo, hourTo, minuteTo;
    int number;
    m_Out << "Write ID of event you want to change and press 'Enter':" << endl;
    m_In >> id;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(cCalendar.returnMapById().count(id) == 0){
        m_Out << "This ID does not exist, try again.." << endl;
        return -4;
    }
    m_Out << "Choose number, which you want to change and press 'Enter':" << endl;
    m_Out << "1) Date from" << endl;
    m_Out << "2) Date to" << endl;
    m_In >> number;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if (number == 1) {

        CDate newDate;
        int flagDateFrom = 0;
        while(flagDateFrom == 0) {
            m_Out << "Write year of date 'from' and press 'Enter':" << endl;
            m_In >> yearFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(yearFrom < 1600){
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write month of date 'from' and press 'Enter':" << endl;
            m_In >> monthFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(monthFrom < 1 || monthFrom > 12){
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write day of date 'from' and press 'Enter':" << endl;
            m_In >> dayFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(dayFrom > cView->numberOfDays(monthFrom-1, yearFrom) || dayFrom < 1){
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
            m_In >> hourFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(hourFrom > 23 || hourFrom < 0){
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
            m_In >> minuteFrom;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(minuteFrom > 59 || minuteFrom < 0){
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }

            newDate = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);

            if(newDate.dateToString() > cCalendar.returnMapById().at(id)->returnDateTo().dateToString()){
                m_Out << "First date is greater, than second, try again to edit date \"from\".." << endl;
                continue;
            }

            flagDateFrom = 1;
        }
        cCalendar.returnMapById().at(id)->returnDateFrom().editDate(newDate);
        m_Out << "Date was successfully changed." << endl;
        return 0;
    } else if (number == 2) {
        CDate newDate;
        int flagDateTo = 0;
        while(flagDateTo == 0) {
            m_Out << "Write year of date 'to' and press 'Enter':" << endl;
            m_In >> yearTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(yearTo < 1600){
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write month of date 'to' and press 'Enter':" << endl;
            m_In >> monthTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(monthTo < 1 || monthTo > 12){
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write day of date 'to' and press 'Enter':" << endl;
            m_In >> dayTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(dayTo > cView->numberOfDays(monthTo-1, yearTo) || dayTo < 1){
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
            m_In >> hourTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(hourTo > 23 || hourTo < 0){
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }

            m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
            m_In >> minuteTo;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            if(minuteTo > 59 || minuteTo < 0){
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }

            newDate = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);

            if(cCalendar.returnMapById().at(id)->returnDateFrom().dateToString() > newDate.dateToString() ){
                m_Out << "First date is greater, than second, try again to edit date \"to\".." << endl;
                continue;
            }

            flagDateTo = 1;
        }
        cCalendar.returnMapById().at(id)->returnDateTo().editDate(newDate);
        m_Out << "Date was successfully changed." << endl;
        return 0;
    }
    else{
        m_Out << "Please choose correct number, try again.." << endl;
        return -4;
    }

    m_Out << "Event has been edited." << endl;

    cout << endl;
    (cCalendar.returnMapById()).at(id)->printFunc(cout);
    cout << endl;
}
vector<shared_ptr<CEvent>> CCalendar::findEvent(const int & id, const string &name, const string &place) {
    //TODO
    return vector<shared_ptr<CEvent>>();
}
std::shared_ptr<CEvent> CCalendar::returnEvent(const int &id) {

    //TODO
    return std::shared_ptr<CEvent>();
}
std::map<int, std::shared_ptr<CEvent>> & CCalendar::returnMapById()   {
    return mapOfEventsById;
}
std::multimap<std::string, std::shared_ptr<CEvent>> &CCalendar::returnMapByName() {
    return mapOfEventsByName;
}

void CCalendar::addEvent(const int & id, const std::string & name, const CDate & dateFrom, const CDate & dateTo, const std::string place,
                         std::vector<std::string> members, const std::string & description, const std::string & obligation) {
    if(!strcasecmp(obligation.c_str(), "required")){
        CRequired cRequired = CRequired(id, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.emplace(name, make_shared<CRequired>(cRequired));
        mapOfEventsById.emplace(id, make_shared<CRequired>(cRequired));

    }
    else if(!strcasecmp(obligation.c_str(), "optional")){
        COptional cOptional = COptional(id, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.insert({name, make_shared<COptional>(cOptional)});
        mapOfEventsById.insert({id, make_shared<COptional>(cOptional)});
    }

}
