#pragma once
#include <iostream>
#include "../Interface/CInterface.h"
#include "../View/CDaily.h"
#include "../View/CWeekly.h"
#include "../View/CMonthly.h"
#include "../View/CYearly.h"

class CApplication {
public:
    CApplication () = default;
    CApplication ( const CApplication & ) = delete;
    CApplication & operator= ( const CApplication & ) = delete;
    ~CApplication () = default;

    void run();

    std::map<std::string, CView*> views;
};


