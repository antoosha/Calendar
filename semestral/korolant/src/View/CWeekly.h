#pragma once
#include "CView.h"

class CWeekly : CView {
public:
    void show(std::ostream &os, CCalendar & cCalendar) const override;
};


