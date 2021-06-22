#pragma once
#include <iostream>
#include "../Interface/CInterface.h"
#include "../View/CDaily.h"
#include "../View/CWeekly.h"
#include "../View/CMonthly.h"
#include "../View/CYearly.h"

/**
 * This class is the foundation of program.
 * It serves as class, which union all application and start it.
 */
class CApplication {
public:
    CApplication () = default;

    /** Copy-cons is deleted, because copy of application is not applicable. */
    CApplication ( const CApplication & ) = delete;

    CApplication & operator= ( const CApplication & cApplication ) = delete;

    ~CApplication () = default;

    /** Method, which starts the application.*/
    void run();

private:
    /** Map of objects CDily, CWeekly, CMonthly, CYearly, as CView, which represent the showing events in calendar. */
    std::map<std::string, CView*> views;
};


