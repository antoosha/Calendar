#pragma once
#include "CView.h"

class CMonthly : CView {
public:
    void show(std::ostream &os, CCalendar * cCalendar) const override;
};


