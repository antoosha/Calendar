#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "../Calendar/CCalendar.h"
class CImportExport {
public:

    void importData(const std::string & fileName) const;

    void exportData(const std::string & fileName) const;
};


