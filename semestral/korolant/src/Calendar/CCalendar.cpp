#include "CCalendar.h"


using namespace std;


int CCalendar::createEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {

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

    CDate dateFrom = {};
    CDate dateTo = {};


    m_Out << "Write name of this event and press 'Enter':" << endl;
    getline(m_In, name);

    int flagSecondGreaterThanFirst = 0;
    while(flagSecondGreaterThanFirst == 0) {
        int flagDateFrom = 0;
        while (flagDateFrom == 0) {
            m_Out << "Write year of date 'from' and press 'Enter':" << endl;
            m_In >> yearFrom;

            if (yearFrom < 1600 || yearFrom > 9999 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write month of date 'from' and press 'Enter':" << endl;
            m_In >> monthFrom;

            if (monthFrom < 1 || monthFrom > 12 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write day of date 'from' and press 'Enter':" << endl;
            m_In >> dayFrom;

            if (dayFrom > cDate.numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
            m_In >> hourFrom;

            if (hourFrom > 23 || hourFrom < 0 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
            m_In >> minuteFrom;

            if (minuteFrom > 59 || minuteFrom < 0 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            dateFrom = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);
            flagDateFrom = 1;
        }

        int flagDateTo = 0;
        while (flagDateTo == 0) {
            m_Out << "Write year of date 'to' and press 'Enter':" << endl;
            m_In >> yearTo;

            if (yearTo < 1600 || yearTo > 9999 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write month of date 'to' and press 'Enter':" << endl;
            m_In >> monthTo;

            if (monthTo < 1 || monthTo > 12 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write day of date 'to' and press 'Enter':" << endl;
            m_In >> dayTo;

            if (dayTo > cDate.numberOfDays(monthTo - 1, yearTo) || dayTo < 1 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
            m_In >> hourTo;

            if (hourTo > 23 || hourTo < 0 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
            m_In >> minuteTo;


            if (minuteTo > 59 || minuteTo < 0 || m_In.fail()) {
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

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

        if((sign != '+' && sign != '-') || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Please write sign \"+\" or \"-\" in correct way, try again.." << endl;
            continue;
        }
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
    int dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom;
    int dayTo, monthTo, yearTo, hourTo, minuteTo;
    int number;
    m_Out << "Write ID of event you want to change and press 'Enter':" << endl;
    m_In >> id;

    if(cCalendar.returnMapById().count(id) == 0 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "This ID does not exist, try again.." << endl;
        return -4;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    m_Out << "Choose number, which you want to change and press 'Enter':" << endl;
    m_Out << "1) Date from" << endl;
    m_Out << "2) Date to" << endl;
    m_Out << "3) Name" << endl;
    m_Out << "4) Place" << endl;
    m_Out << "5) Members" << endl;
    m_Out << "6) Description" << endl;
    m_In >> number;
    if(number < 1 || number > 6 || m_In.fail()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Please choose correct number, try again.." << endl;
        return -4;
    }


    if (number == 1) {

        CDate newDate = {};
        int flagDateFrom = 0;
        while(flagDateFrom == 0) {
            m_Out << "Write year of date 'from' and press 'Enter':" << endl;
            m_In >> yearFrom;

            if(yearFrom < 1600 || yearFrom > 9999 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write month of date 'from' and press 'Enter':" << endl;
            m_In >> monthFrom;

            if(monthFrom < 1 || monthFrom > 12 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write day of date 'from' and press 'Enter':" << endl;
            m_In >> dayFrom;

            if(dayFrom > cDate.numberOfDays(monthFrom-1, yearFrom) || dayFrom < 1 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
            m_In >> hourFrom;

            if(hourFrom > 23 || hourFrom < 0 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
            m_In >> minuteFrom;


            if(minuteFrom > 59 || minuteFrom < 0 ||  m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

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
        CDate newDate = {};
        int flagDateTo = 0;
        while(flagDateTo == 0) {
            m_Out << "Write year of date 'to' and press 'Enter':" << endl;
            m_In >> yearTo;

            if(yearTo < 1600 || yearTo > 9999 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Year is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write month of date 'to' and press 'Enter':" << endl;
            m_In >> monthTo;

            if(monthTo < 1 || monthTo > 12 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Month is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write day of date 'to' and press 'Enter':" << endl;
            m_In >> dayTo;

            if(dayTo > cDate.numberOfDays(monthTo-1, yearTo) || dayTo < 1 ||  m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Day is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
            m_In >> hourTo;

            if(hourTo > 23 || hourTo < 0 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Hour is not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
            m_In >> minuteTo;

            if(minuteTo > 59 || minuteTo < 0 || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Minutes are not correct, try again.." << endl;
                continue;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

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
        if((sign != '+' && sign != '-') || m_In.fail()){
            m_In.clear();
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            m_Out << "Please write sign \"+\" or \"-\" in correct way, try again.." << endl;
            return -4;
        }
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

            if(index <= 0 || (size_t)index >  cCalendar.returnMapById().at(id)->returnMembers().size() || m_In.fail()){
                m_In.clear();
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');
                m_Out << "Index is not correct, try again.." << endl;
                return -4;
            }
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');

            auto indexIter = cCalendar.returnMapById().at(id)->returnMembers().begin() + index - 1 ; // -1 beacouse in vector in 0 1 2 3... but for user is 1 2 3
            cCalendar.returnMapById().at(id)->returnMembers().erase(indexIter);
            m_Out << "Person has been successfully deleted." << endl;
            return 0;
        }
        else{
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
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
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

void CCalendar::addEvent(const int & id, const std::string & name, const CDate & dateFrom, const CDate & dateTo, const std::string & place,
                         const std::vector<std::string>& members, const std::string & description, const std::string & obligation) {
    if(!strcasecmp(obligation.c_str(), "required")){
        CRequired cRequired = CRequired(id, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.emplace(name, make_shared<CRequired>(cRequired));
        mapOfEventsById.emplace(id, make_shared<CRequired>(cRequired));
        mapOfEventsByDate.emplace(dateFrom.dateToString(), make_shared<CRequired>(cRequired));

    }
    else if(!strcasecmp(obligation.c_str(), "optional")){
        COptional cOptional = COptional(id, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.emplace(name, make_shared<COptional>(cOptional));
        mapOfEventsById.emplace(id, make_shared<COptional>(cOptional));
        mapOfEventsByDate.emplace(dateFrom.dateToString(), make_shared<COptional>(cOptional));
    }

}

int CCalendar::deleteEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {
    int idToDelete;
    m_Out << "Write id of event to delete and press 'Enter':" << endl;
    m_In >> idToDelete;

    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cCalendar.returnMapById().count(idToDelete)){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Event with id " << idToDelete << " does not exist, try again.."  << endl;
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



void CCalendar::listEvents(ostream &m_Out, CCalendar &cCalendar) const {

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

int CCalendar::findFirstPossible(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    int id;
    m_Out << "Write id of event you want to find first possible term to postpone it and press 'Enter':" << endl;
    m_In >> id;

    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(cCalendar.returnMapById().count(id) == 0){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "This ID does not exist, try again.." << endl;
        return -4;
    }
    string dateFromStr = cCalendar.mapOfEventsById.at(id)->returnDateFrom().dateToString();
    string dateToStr = cCalendar.mapOfEventsById.at(id)->returnDateTo().dateToString();
    for(auto i = cCalendar.mapOfEventsByDate.begin(); i != cCalendar.mapOfEventsByDate.end(); i++){
        if(dateFromStr > i->second->returnDateTo().dateToString()){
            continue;
        }
        auto nextIter = i;
        nextIter++;
        if(dateToStr <= nextIter->second->returnDateFrom().dateToString()){
            //show this place
            char s1[19];
            s1[18] = '\0';
            char s2[19];
            s2[18] = '\0';
            std::sprintf(s1, "[%02d/%02d/%04d %02d:%02d]",i->second->returnDateTo().returnDay(), i->second->returnDateTo().returnMonth(),
                         i->second->returnDateTo().returnYear(), i->second->returnDateTo().returnHour(), i->second->returnDateTo().returnMinute());
            std::sprintf(s2, "[%02d/%02d/%04d %02d:%02d]",nextIter->second->returnDateFrom().returnDay(), nextIter->second->returnDateFrom().returnMonth(),
                         nextIter->second->returnDateFrom().returnYear(), nextIter->second->returnDateFrom().returnHour(), nextIter->second->returnDateFrom().returnMinute());
            m_Out << "A window is between " << s1 << " and " << s2<< endl;

            return 0;
        }
        //continue to find
    }
    //the last place, after the last event
    auto i = returnMapByDate().end()--;
    char s1[19];
    s1[18] = '\0';
    std::sprintf(s1, "[%02d/%02d/%04d %02d:%02d]",i->second->returnDateTo().returnDay(), i->second->returnDateTo().returnMonth(),
                 i->second->returnDateTo().returnYear(), i->second->returnDateTo().returnHour(), i->second->returnDateTo().returnMinute());
    m_Out << "Sorry, but does not exist free window(space), exists term after the last event, after" << s1 << endl;
    //show this place
    return 0;

}

std::multimap<std::string, std::shared_ptr<CEvent>> &CCalendar::returnMapByDate() {
    return mapOfEventsByDate;
}
