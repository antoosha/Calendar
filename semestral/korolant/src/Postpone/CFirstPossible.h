#pragma once
#include "CPostpone.h"

class CFirstPossible : CPostpone {
    bool postponeEvent(const int &id, const std::shared_ptr<CDate> &dateFrom, const std::shared_ptr<CDate> &dateTo) override;
};


