#include "CFirstPossible.h"

bool CFirstPossible::postponeEvent(const int &id, const std::shared_ptr<CDate> &dateFrom,
                                   const std::shared_ptr<CDate> &dateTo) {
    //TODO posponeFirtPossible
    return CPostpone::postponeEvent(id, dateFrom, dateTo);
}
