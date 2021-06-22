#include "CEvent.h"

int & CEvent::returnId() {
    return id;
}

std::string &CEvent::returnName() {
    return name;
}

std::string &CEvent::returnPlace() {
    return place;
}

std::vector<std::string> &CEvent::returnMembers() {
    return members;
}

std::string &CEvent::returnDescription() {
    return description;
}

CDate &CEvent::returnDateFrom() {
    return dateFrom;
}

CDate &CEvent::returnDateTo() {
    return dateTo;
}
