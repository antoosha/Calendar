#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <cstring>

#include "CEvent.h"
#include "COptional.h"
#include "CRequired.h"
#include "CDate.h"

class CCalendar {

public:
    CCalendar() = default;

    void createEvent(const int & idEvent, const std::string & name, const CDate & dateFrom, const CDate & dateTo,
                     const std::string & place, const std::vector<std::string> & members, const std::string & description,
                     const std::string & obligation);

    void editEvent( const int & idEvent, const std::string & name);

    std::vector<std::shared_ptr<CEvent>> findEvent(const int & idEvent, const std::string & name, const std::string & place);

    std::shared_ptr<CEvent> returnEvent(const int & idEvent);

    std::map<int, std::shared_ptr<CEvent>> & returnMapById();

    std::multimap<std::string, std::shared_ptr<CEvent>> &  returnMapByName();

protected:
    std::map<int, std::shared_ptr<CEvent>> mapOfEventsById;
    std::multimap<std::string, std::shared_ptr<CEvent>> mapOfEventsByName;
};

