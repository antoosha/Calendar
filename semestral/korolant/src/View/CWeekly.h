#pragma once
#include "CView.h"

class CWeekly : public CView {
public:
    ~CWeekly() override = default;

    void show(std::ostream &os, CCalendar & cCalendar) const override;

    int setup( std::istream & in, std::ostream & os) override;
};


