#pragma once
#include "CCalendar.h"
#include "CEvent.h"

class COptional : public CEvent {
public:
    COptional (const int & idIn, const std::string & nameIn, const CDate & dateFromIn, const CDate & dateToIn,
               const std::string & placeIn, const std::vector<std::string> & membersIn, const std::string & descriptionIn)
            : CEvent(idIn, nameIn, dateFromIn, dateToIn, placeIn, membersIn, descriptionIn){};

    CDate & returnDateFrom() override;

    CDate & returnDateTo() override;

    void printFunc(std::ostream & os) const override;
};
