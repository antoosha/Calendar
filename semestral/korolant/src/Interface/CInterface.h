#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>
#include "../View/CView.h"
#include "../Calendar/CCalendar.h"
#include "../View/CMonthly.h"
#include "../ImportExport/CImportExport.h"
#include "../Postpone/CPostpone.h"
#include "../Repeat/CRepeat.h"

class CInterface {

public:
    CInterface ( std::istream & in, std::ostream & out, const CCalendar & cCalendarIn);

    int doSmthWithCommand();

    void getCommand();

protected:
    std::istream & m_In;
    std::ostream & m_Out;
    std::vector<std::string> words;
    CCalendar cCalendar;
};


