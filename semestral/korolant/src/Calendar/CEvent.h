#pragma once
#include "CCalendar.h"
#include "CDate.h"

#include <utility>
#include <iostream>
#include <string>


class CEvent {
public:
    CEvent() = default;

    CEvent( const int & idIn, const std::string & nameIn, const CDate & dateFromIn, const CDate & dateToIn,
            const std::string & placeIn, const std::vector<std::string> & membersIn, const std::string & descriptionIn)
            : id(idIn), name(nameIn), dateFrom(dateFromIn), dateTo(dateToIn), place(placeIn), description(descriptionIn) {
        for(auto i = membersIn.begin(); i != membersIn.end(); i++){
            members.emplace_back(*i);
        }
    }

    virtual CDate & returnDateFrom() = 0;

    virtual CDate & returnDateTo() = 0;

    virtual void printFunc(std::ostream & os) const = 0;

protected:
    int id = 0;
    std::string name;
    CDate dateFrom;
    CDate dateTo;
    std::string place;
    std::vector<std::string> members;
    std::string description;

};


