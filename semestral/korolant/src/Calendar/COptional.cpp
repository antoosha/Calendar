#include "COptional.h"


CDate & COptional::returnDateFrom() {
    return dateFrom;
}

CDate & COptional::returnDateTo(){
    return dateTo;
}

void COptional::printFunc(std::ostream &os) const {
    os << "[Optional][" << dateFrom.returnDate() << " - " << dateTo.returnDate() << "]" << "Name: " <<
       name << std::endl;
}

