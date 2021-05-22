#include "COptional.h"


CDate & COptional::returnDateFrom() {
    return dateFrom;
}

CDate & COptional::returnDateTo(){
    return dateTo;
}

void COptional::printFunc(std::ostream &os) const {
    os << "[Optional][" << dateFrom.returnDay() << "/" << dateFrom.returnMonth() << "/" << dateFrom.returnYear()
    << " - " << dateTo.returnDay() << "/" << dateTo.returnMonth() << "/" << dateTo.returnYear() << "]" << "Name: " <<
    name << std::endl;
}
