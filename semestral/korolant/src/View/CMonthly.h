#pragma once
#include "CView.h"

class CMonthly : public CView {
public:

    ~CMonthly() override = default;

    void show(std::ostream &os, CCalendar & cCalendar) const override;

    int setup( std::istream & in, std::ostream & os) override;
};


