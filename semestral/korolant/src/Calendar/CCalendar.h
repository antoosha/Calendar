#pragma once
#include <map>
#include <string>
#include <memory>
#include <vector>
#include <utility>
#include <cstring>
#include <limits>
#include <typeinfo>
#include <algorithm>

#include "CEvent.h"
#include "COptional.h"
#include "CRequired.h"
#include "CDate.h"

class CCalendar {

public:
    CCalendar() = default;

    /**
     * This method will get necessary parameters from user and then using method addEvent will add this event to
     * "database" of events, to three maps sorted by ID, name, date.
     * If something went wront, method returns -4
     *
     * @param in is input stream
     * @param out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0, all is OK
     * @return -4, something went wrong(usually it is wrong input from user)
     */
    int createEvent(std::istream & in, std::ostream & out, CCalendar & cCalendar);

    /**
     * This method will add event type CEvent to "database" maps with different ordering.
     *
     * @param id is index of event, type is int
     * @param name is name of event, type is string
     * @param dateFrom is date from(object of type CDate) of event
     * @param dateTo if date to(object of type CDate) of event
     * @param place is place, type is string
     * @param members is vector of members, who relates this event, type of member is string
     * @param description type is string
     * @param obligation string, which should be "optional" or "required"
     */
    void addEvent(const int & id, const std::string & name, const CDate & dateFrom, const CDate & dateTo, const std::string & place,
                  const std::vector<std::string>& members, const std::string & description, const std::string & obligation);

    /**
     * This method edits events if all parameters is correctly written by user.
     * Otherwise returns -4. This method can edit all parameters of event.
     * To edit event is better to know it index.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return -4 if event with input index does not exist OR number of variant to choose is not correct
     */
    int editEvent( std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    /**
     * This method finds event. There is 3 variants to find event:
     * 1)by name
     * 2)by place
     * 3)by name and place at once
     * Method will find and print events, which have been found or will write a messege, that any events have not been found.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 if all is OK
     * @return -4 if something went wrong(usually it is input from user or unexisting event with input id)
     */
    int findEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) const;

    /**
     * Method, which delete event from database using it ID(index).
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 if all is OK
     * @return -4 if event with id from user's input does not exist
     */
    int deleteEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    /**
     * This method prints all events which are stored in database in calendar.
     *
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     */
    void listEvents( std::ostream & m_Out, CCalendar & cCalendar) const;

    /**
     * This method generate new and unique index for event.
     *
     * @param cCalendar is a reference to an object of CCalendar
     * @return new and unique id of size_t type.
     */
    size_t generateId(CCalendar & cCalendar);

    /**
     * This method find first possible term to postpone event between other events in database of events in calendar.
     * Method will print the date, where user could postpone this event.
     * If any windows will not be found, date will be printed as a date after the last event.
     *
     * @param m_In is input stream
     * @param m_Out is output stream
     * @param cCalendar is a reference to an object of CCalendar
     * @return 0 if all is OK
     * @return -4 if input id from user is not correct
     */
    int findFirstPossible(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);

    std::map<int, std::shared_ptr<CEvent>> & returnMapById();

    std::multimap<std::string, std::shared_ptr<CEvent>> &  returnMapByName();

    std::multimap<std::string, std::shared_ptr<CEvent>> &  returnMapByDate();

protected:
    /**
     * map of Events, ordered ascending by id, whose type is int, second param is smart pointer to object of type CEvent
     * each id(index) has just one event. Another words, index is unique.
     */
    std::map<int, std::shared_ptr<CEvent>> mapOfEventsById;
    /**
     * multimap of Events, ordered ascending by name with type string, second param is smart pointer to object of type CEvent
     * name of event is not unique at this calendar
     */
    std::multimap<std::string, std::shared_ptr<CEvent>> mapOfEventsByName;
    /**
     * multimap of Events, ordered ascending by "Date from", converted to string, second param is smart pointer to object of type CEvent
     * kay is not unique, calendar could has some events with same dates
     */
    std::multimap<std::string, std::shared_ptr<CEvent>> mapOfEventsByDate;

private:
    CDate cDate{};
};


