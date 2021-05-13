#pragma once
#include "CCalendar.h"
#include "CEvent.h"

class COptional : public CEvent {
public:
    COptional (const int & idIn, const std::string & nameIn, const std::shared_ptr<CDate> & dateFromIn, const std::shared_ptr<CDate> & dateToIn,
               const std::string & placeIn, const std::vector<std::string> & membersIn, const std::string & descriptionIn)
            : CEvent(idIn, nameIn, dateFromIn, dateToIn, placeIn, membersIn, descriptionIn){};

    std::shared_ptr<CDate> &returnDateFrom() override;

    std::shared_ptr<CDate> &returnDateTo() override;

    void printFunc(std::ostream & os) const override;
};


