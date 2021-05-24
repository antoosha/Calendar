#include "CRequired.h"

CDate & CRequired::returnDateFrom(){
    return dateFrom;
}

CDate & CRequired::returnDateTo(){
    return dateTo;
}


void CRequired::printFunc(std::ostream &os) const {
    os << "[Required][" << dateFrom.returnDate() << " - " << dateTo.returnDate() << "]" << "Name: " <<
       name << std::endl;
}
