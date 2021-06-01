#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <cstring>
#include <limits>
#include <typeinfo>

#include "CEvent.h"
#include "COptional.h"
#include "CRequired.h"
#include "CDate.h"

class CCalendar {

public:
    CCalendar() = default;

    int createEvent(std::istream & in, std::ostream & out, CCalendar & cCalendar);

    void addEvent(const int & id, const std::string & name, const CDate & dateFrom, const CDate & dateTo, const std::string & place,
                  const std::vector<std::string>& members, const std::string & description, const std::string & obligation);

    int editEvent( std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    int findEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) const;

    int deleteEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    void listEvents( std::ostream & m_Out, CCalendar & cCalendar) const;

    size_t generateId(CCalendar & cCalendar);

    int findFirstPossible(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    std::map<int, std::shared_ptr<CEvent>> & returnMapById();

    std::multimap<std::string, std::shared_ptr<CEvent>> &  returnMapByName();

    std::multimap<std::string, std::shared_ptr<CEvent>> &  returnMapByDate();

protected:
    std::map<int, std::shared_ptr<CEvent>> mapOfEventsById;
    std::multimap<std::string, std::shared_ptr<CEvent>> mapOfEventsByName;
    std::multimap<std::string, std::shared_ptr<CEvent>> mapOfEventsByDate;

private:
    CDate cDate{};
};


