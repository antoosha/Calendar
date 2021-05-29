#pragma once
#include <memory>

#include "../Calendar/CCalendar.h"
#include "../Calendar/CDate.h"

class CPostpone {
public:
    int moveEvent(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar);
};


