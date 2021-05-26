#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>

#include "../Calendar/CCalendar.h"
#include "../View/CView.h"
class CImportExport {
public:

    int importData(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) ;

    int exportData(std::istream & in, std::ostream & out, CCalendar & cCalendar) ;
};


