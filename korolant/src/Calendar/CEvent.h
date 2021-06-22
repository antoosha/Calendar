#pragma once
#include "CDate.h"

#include <utility>
#include <iostream>
#include <string>
#include <vector>

/**
 * This abstract class review event. Has printing method to print event using format.
 */
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

    int & returnId();

    std::string &returnName();

    std::string &returnPlace();

    std::vector<std::string>  & returnMembers();

    std::string &returnDescription();

    CDate &returnDateFrom();

    CDate &returnDateTo();

    /**
     * This method prints an event with different obligation wich depends on obligation of event.
     *
     * @param os is output stream
     */
    virtual void printFunc(std::ostream & os) const = 0;

protected:
    int id = 0;
    std::string name;
    CDate dateFrom{};
    CDate dateTo{};
    std::string place;
    /**vector of members, which relates to this event*/
    std::vector<std::string> members;
    std::string description;

};


