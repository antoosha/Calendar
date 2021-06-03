#pragma once
#include "CCalendar.h"
#include "CEvent.h"

class CRequired : public CEvent {
public:
    /**
     * Constructor CRequired, which use costructor of CEvent.
     * @param idIn
     * @param nameIn
     * @param dateFromIn
     * @param dateToIn
     * @param placeIn
     * @param membersIn
     * @param descriptionIn
     */
    CRequired (const int & idIn, const std::string & nameIn, const CDate & dateFromIn, const CDate & dateToIn,
               const std::string & placeIn, const std::vector<std::string> & membersIn, const std::string & descriptionIn)
            : CEvent(idIn, nameIn, dateFromIn, dateToIn, placeIn, membersIn, descriptionIn){};

    void printFunc(std::ostream & os) const override;
};


