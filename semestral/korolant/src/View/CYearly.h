#pragma once
#include "CView.h"

class CYearly : public CView {
public:

    void show(std::ostream &os, CCalendar & cCalendar) const override;

    int setup( std::istream & in, std::ostream & os, CCalendar & cCalendar) override;
};

