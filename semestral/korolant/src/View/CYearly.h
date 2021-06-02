#pragma once
#include "CView.h"

class CYearly : public CView {
public:

    ~CYearly() override = default;

    void show(std::ostream &os, CCalendar & cCalendar) const override;

    int setup( std::istream & in, std::ostream & os) override;
};

