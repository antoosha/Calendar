#pragma once
#include "CCalendar.h"
#include "CDate.h"

#include <utility>
#include <iostream>
#include <string>


class CEvent {
public:
    CEvent() = default;

    CEvent( const int & idIn, const std::string & nameIn, const std::shared_ptr<CDate> & dateFromIn, const std::shared_ptr<CDate> & dateToIn,
            const std::string & placeIn, const std::vector<std::string> & membersIn, const std::string & descriptionIn)
            : id(idIn), name(nameIn), dateFrom(dateFromIn), dateTo(dateToIn), place(placeIn), members(membersIn), description(descriptionIn) {}

    virtual std::shared_ptr<CDate> & returnDateFrom() = 0;

    virtual std::shared_ptr<CDate> & returnDateTo() = 0;

    virtual void printFunc(std::ostream & os) const = 0;
protected:
    int id = 0;
    std::string name;
    std::shared_ptr<CDate> dateFrom;
    std::shared_ptr<CDate> dateTo;
    std::string place;
    std::vector<std::string> members;
    std::string description;

};


