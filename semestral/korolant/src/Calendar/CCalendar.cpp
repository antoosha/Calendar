#include "CCalendar.h"
using namespace std;

void CCalendar::createEvent(const int & idEvent, const string &name, const CDate & dateFrom, const CDate & dateTo,
                            const string &place, const vector<std::string> &members, const string &description) {
    //TODO
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
std::map<std::string, std::shared_ptr<CEvent>> &CCalendar::returnMapByName() {
    return mapOfEventsByName;
}
