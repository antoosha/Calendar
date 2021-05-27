#pragma once
#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
#include "../Calendar/CCalendar.h"

class CView {
public:
    virtual void show(std::ostream & os, CCalendar & cCalendar) const = 0;

};



