#pragma once
#include <memory>

#include "../Calendar/CDate.h"

class CPostpone {
public:
    virtual bool postponeEvent(const int & id, const std::shared_ptr<CDate> & dateFrom, const std::shared_ptr<CDate> & dateTo);
};


