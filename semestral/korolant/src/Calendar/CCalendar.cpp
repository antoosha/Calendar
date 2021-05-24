#include "CCalendar.h"
using namespace std;

void CCalendar::createEvent(const int & idEvent, const string &name, const CDate & dateFrom, const CDate & dateTo,
                            const string &place, const vector<std::string> &members, const string &description, const string & obligation) {


    if(!strcasecmp(obligation.c_str(), "required")){
        CRequired cRequired = CRequired(idEvent, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.emplace(name, make_shared<CRequired>(cRequired));
        mapOfEventsById.emplace(idEvent, make_shared<CRequired>(cRequired));

    }
    else if(!strcasecmp(obligation.c_str(), "optional")){
        COptional cOptional = COptional(idEvent, name, dateFrom, dateTo, place, members, description);
        mapOfEventsByName.insert({name, make_shared<COptional>(cOptional)});
        mapOfEventsById.insert({idEvent, make_shared<COptional>(cOptional)});
    }

}
void CCalendar::editEvent(const int &idEvent, const string &name) {
    //TODO
}
vector<shared_ptr<CEvent>> CCalendar::findEvent(const int & idEvent, const string &name, const string &place) {
    //TODO
    return vector<shared_ptr<CEvent>>();
}
std::shared_ptr<CEvent> CCalendar::returnEvent(const int &idEvent) {

    //TODO
    return std::shared_ptr<CEvent>();
}
std::map<int, std::shared_ptr<CEvent>> &CCalendar::returnMapById() {
    return mapOfEventsById;
}
std::multimap<std::string, std::shared_ptr<CEvent>> &CCalendar::returnMapByName() {
    return mapOfEventsByName;
}
