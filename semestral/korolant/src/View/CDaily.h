#pragma once
#include "CView.h"
#include <string>
class CDaily : public CView {
public:
    void show(std::ostream & os, CCalendar & cCalendar) const override;

    int setup( std::istream & in, std::ostream & os) override;
};


