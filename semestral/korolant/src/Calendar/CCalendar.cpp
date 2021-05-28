#include "CCalendar.h"


using namespace std;

int CCalendar::createEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {

    CDate * cDate;
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

            if (dayFrom > cDate->numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1) {
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

            if (dayTo > cDate->numberOfDays(monthTo - 1, yearTo) || dayTo < 1) {
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

    id = generateId(cCalendar);
    cCalendar.addEvent(id, name, dateFrom, dateTo, place, members, description, obligation);

    m_Out << "Event has been created." << endl;
    cout << endl;
    (cCalendar.returnMapById()).at(id)->printFunc(cout);
    cout << endl;
    return 0;

}
int CCalendar::editEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {

    int id;
    CDate * cDate;
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
    m_Out << "3) Name" << endl;
    m_Out << "4) Place" << endl;
    m_Out << "5) Members" << endl;
    m_Out << "6) Description" << endl;
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

            if(dayFrom > cDate->numberOfDays(monthFrom-1, yearFrom) || dayFrom < 1){
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

            if(dayTo > cDate->numberOfDays(monthTo-1, yearTo) || dayTo < 1){
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
    else if(number == 3){
        //name
        string newName;
        m_Out << "Write new name of this event and press 'Enter':" << endl;
        getline(m_In, newName);
        if(newName.empty()){
            m_Out << "Name is not changed, new name is empty, try again.." << endl;
            return -4;
        }
        cCalendar.returnMapById().at(id)->returnName() = newName;
        m_Out << "Name was successfully changed." << endl;
        return 0;
    }
    else if(number == 4){
        //place
        string newPlace;
        m_Out << "Write place of this event and press 'Enter':" << endl;
        std::getline(m_In, newPlace);
        if(newPlace.empty()){
            m_Out << "Place is not changed, new place is empty, try again.." << endl;
            return -4;
        }
        cCalendar.returnMapById().at(id)->returnPlace() = newPlace;
        m_Out << "Place was successfully changed." << endl;
        return 0;
    }
    else if(number == 5){
        //members
        char sign;
        m_Out << "Write sign what you want to do:" << endl;
        m_Out << "Write \"+\" if you want to add new member and press 'Enter'" << endl;
        m_Out << "Write \"-\" if you want to delete member and press 'Enter'" << endl;
        m_In >> sign;
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(sign == '+'){
            m_Out << "Write person, who you want to add to this event and press 'Enter':" << endl;
            string memberIn;
            getline(m_In, memberIn);
            if(memberIn.empty()){
                m_Out << "Member is not changed, new member is empty, try again.." << endl;
                return -4;
            }

            cCalendar.returnMapById().at(id)->returnMembers().push_back(memberIn);

            m_Out << "Person " << memberIn << " has been successfully added." << endl;
            return 0;
        }
        else if(sign == '-'){
            m_Out << "List of members:" << endl;
            int index;
            for(size_t i = 0; i < cCalendar.returnMapById().at(id)->returnMembers().size(); i++){
                m_Out << i << ") " <<  cCalendar.returnMapById().at(id)->returnMembers()[i] << endl;
            }
            m_Out << "Write index of person, who you want to delete from this event and press 'Enter':" << endl;
            m_In >> index;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            if(index <= 0 || index >  cCalendar.returnMapById().at(id)->returnMembers().size()){
                m_Out << "Index is not correct, try again.." << endl;
                return -4;
            }
            auto indexIter = cCalendar.returnMapById().at(id)->returnMembers().begin() + index - 1 ; // -1 beacouse in vector in 0 1 2 3... but for user is 1 2 3
            cCalendar.returnMapById().at(id)->returnMembers().erase(indexIter);
            m_Out << "Person has been successfully deleted." << endl;
            return 0;
        }
        else{
            m_Out << "Please write sign \"+\" or \"-\" in correct way, try again.." << endl;
            return -4;
        }


    }
    else if(number == 6){
        //description
        string newDescription;
        m_Out << "Write description of this event and press 'Enter':" << endl;
        std::getline(m_In, newDescription);
        if(newDescription.empty()){
            m_Out << "Description is not changed, new description is empty, try again.." << endl;
            return -4;
        }
        cCalendar.returnMapById().at(id)->returnDescription() = newDescription;
        m_Out << "Description was successfully changed." << endl;
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
int CCalendar::findEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) const {
    int number;
    m_Out << "Choose number by which parameter you want to find the event and press 'Enter':" << endl;
    m_Out << "1) Name:" << endl;
    m_Out << "2) Place:" << endl;
    m_Out << "3) Name and place:" << endl;
    m_In >> number;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(number != 1 && number != 2 && number != 3){
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }
    if(mapOfEventsByName.empty()){
        m_Out << "Any events have not been found, calendar has not any events." << endl;
        return 0;
    }
    if(number == 1){
        string nameFind;
        vector<shared_ptr<CEvent>> events;
        m_Out << "Write name of event and press 'Enter':" << endl;
        getline(m_In, nameFind);
        for(auto i = cCalendar.returnMapByName().begin(); i != cCalendar.returnMapByName().end(); i++){
            if(!strcasecmp(i->first.c_str(), nameFind.c_str())){
                events.emplace_back(i->second);
            }
        }
        if(events.empty()){
            m_Out << "Any events have not been found." << endl;
            return 0;
        }
        else{
            for(auto i = events.begin(); i != events.end(); i++){
                i->get()->printFunc(m_Out);
            }
            return 0;
        }

    }
    else if(number == 2){
        string placeFind;
        vector<shared_ptr<CEvent>> events;
        m_Out << "Write place of event and press 'Enter':" << endl;
        getline(m_In, placeFind);
        for(auto i = cCalendar.returnMapByName().begin(); i != cCalendar.returnMapByName().end(); i++){
            if(!strcasecmp(i->second->returnPlace().c_str(), placeFind.c_str())){
                events.emplace_back(i->second);
            }
        }
        if(events.empty()){
            m_Out << "Any events have not been found." << endl;
            return 0;
        }
        else{
            for(auto i = events.begin(); i != events.end(); i++){
                i->get()->printFunc(m_Out);
            }
            return 0;
        }
    }
    else if(number == 3){
        string nameFind;
        string placeFind;
        vector<shared_ptr<CEvent>> events;
        m_Out << "Write name of event and press 'Enter':" << endl;
        getline(m_In, nameFind);
        m_Out << "Write place of event and press 'Enter':" << endl;
        getline(m_In, placeFind);
        for(auto i = cCalendar.returnMapByName().begin(); i != cCalendar.returnMapByName().end(); i++){
            if(!strcasecmp(i->second->returnPlace().c_str(), placeFind.c_str()) && !strcasecmp(i->first.c_str(), nameFind.c_str())){
                events.emplace_back(i->second);
            }
        }
        if(events.empty()){
            m_Out << "Any events have not been found." << endl;
            return 0;
        }
        else{
            for(auto i = events.begin(); i != events.end(); i++){
                i->get()->printFunc(m_Out);
            }
            return 0;
        }
    }
    return 0;
}

std::map<int, std::shared_ptr<CEvent>> & CCalendar::returnMapById()   {
    return mapOfEventsById;
}
std::multimap<std::string, std::shared_ptr<CEvent>> &CCalendar::returnMapByName() {
    return mapOfEventsByName;
}

void CCalendar::addEvent(const int & id, const std::string & name, const CDate & dateFrom, const CDate & dateTo, const std::string place,
                         const std::vector<std::string>& members, const std::string & description, const std::string & obligation) {
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

int CCalendar::deleteEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {
    int idToDelete;
    m_Out << "Write id of event to delete and press 'Enter':" << endl;
    m_In >> idToDelete;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cCalendar.returnMapById().count(idToDelete)){
        m_Out << "Event with id " << idToDelete << "does not exist, try again.."  << endl;
        return -4;
    }
    else{
        cCalendar.returnMapById().erase(idToDelete);
        for(auto i = cCalendar.returnMapByName().begin(); i != cCalendar.returnMapByName().end(); i++){
            if(i->second->returnId() == idToDelete){
                mapOfEventsByName.erase(i);
                break;
            }
        }
        m_Out << "Event was successfully deleted." << endl;
        return 0;
    }

    return 0;
}

int CCalendar::moveEvent(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    int idToMove;
    m_Out << "Write id of event you want to move and press 'Enter':" << endl;
    m_In >> idToMove;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cCalendar.returnMapById().count(idToMove)){
        m_Out << "Event with id " << idToMove << " does not exist, try again.."  << endl;
        return -4;
    }
    int numberForWay;
    m_Out << "Choose number what you want to move and press 'Enter':" << endl;
    m_Out << "1) Rewind date forward" << endl;
    m_Out << "2) Rewind date back" << endl;
    m_In >> numberForWay;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(numberForWay != 1 && numberForWay != 2){
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }

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
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(number < 1 || number > 6){
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }

    if(number == 1 ){
        int minutes;
        m_Out << "Write for how many minutes you want to move event and press 'Enter':" << endl;
        m_In >> minutes;
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(minutes < 1 || minutes > 59){
            m_Out << "Minutes should be between 1 to 59, try again.." << endl;
            return -4;
        }
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
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(hours < 1 || hours > 23){
            m_Out << "Hours should be between 1 to 23, try again.." << endl;
            return -4;
        }
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
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(days < 1 || days > minOfDaysFirstOrLastMonth - 1 ){
            m_Out << "Days should be between 1 to " << minOfDaysFirstOrLastMonth-1  << ", try again.." << endl;
            return -4;
        }
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
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(months < 1 || months > 11){
            m_Out << "Months should be between 1 to 11, try again.." << endl;
            return -4;
        }
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
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(years < 0){
            m_Out << "Year should be positive, try again.." << endl;
            return -4;
        }
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

int CCalendar::repeatEvent(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    int id;
    m_Out << "Write id of event what you want to repeat and press 'Enter':" << endl;
    m_In >> id;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cCalendar.returnMapById().count(id)){
        m_Out << "Event with id " << id << "does not exist, try again.."  << endl;
        return -4;
    }
    int howManyTimesToRepeat;
    m_Out << "Write how many times you want to repeat this event and press 'Enter':" << endl;
    m_In >> howManyTimesToRepeat;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(howManyTimesToRepeat < 1){
        m_Out << "Number of times should be greater than 0, try again.."  << endl;
        return -4;
    }
    int number;
    m_Out << "Choose at what interval you want to repeat this event and press 'Enter':" << endl;
    m_Out << "1) Every day" << endl;
    m_Out << "2) Every week" << endl;
    m_Out << "3) Every month" << endl;
    m_Out << "4) Every year" << endl;
    m_In >> number;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(number < 1 || number > 4){
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }
    if(number == 1){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveDays(1);
            newDateTo.moveDays(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)generateId(cCalendar)-1;
        }
    }
    else if(number == 2){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveDays(7);
            newDateTo.moveDays(7);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)generateId(cCalendar)-1;
        }
    }
    else if(number == 3){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveMonths(1);
            newDateTo.moveMonths(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)generateId(cCalendar)-1;
        }
    }
    else if(number == 4){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveYears(1);
            newDateTo.moveYears(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)generateId(cCalendar)-1;
        }
    }
    m_Out << "Event was repeated." << endl;
    return 0;
}

void CCalendar::listEvents(istream &m_In, ostream &m_Out, CCalendar &cCalendar) const {

    if(!cCalendar.mapOfEventsById.empty()) {
        for (auto i = cCalendar.mapOfEventsById.begin(); i != cCalendar.mapOfEventsById.end(); i++) {
            i->second->printFunc(m_Out);
        }
    }
    else{
        m_Out << "Calendar has not any events." << endl;
    }
}

size_t CCalendar::generateId(CCalendar &cCalendar) {
   return cCalendar.returnMapById().size();
}
