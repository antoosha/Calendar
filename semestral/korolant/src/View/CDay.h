#pragma once
#include "CView.h"
#include <string>
class CDay : public CView {
public:
    void show(std::ostream & os, CCalendar & cCalendar) const override;
};


