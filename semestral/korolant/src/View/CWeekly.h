#pragma once
#include "CView.h"

class CWeekly : public CView {
public:

    void show(std::ostream &os, CCalendar & cCalendar) const override;

    void setup( std::istream & in, std::ostream & os, CCalendar & cCalendar) override;
};


