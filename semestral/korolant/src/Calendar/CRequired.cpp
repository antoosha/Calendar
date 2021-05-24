#include "CRequired.h"

CDate & CRequired::returnDateFrom(){
    return dateFrom;
}

CDate & CRequired::returnDateTo(){
    return dateTo;
}


/*void CRequired::printFunc(std::ostream &os) const {
    os << "[Required][" << dateFrom.returnDate() << " - " << dateTo.returnDate() << "]" << "Name: " <<
       name << std::endl;
}*/

void CRequired::printFunc(std::ostream &os) const {
    os << "[Required][" << dateFrom.returnDay() << "/" << dateFrom.returnMonth() << "/" << dateFrom.returnYear()
       << " - " << dateTo.returnDay() << "/" << dateTo.returnMonth() << "/" << dateTo.returnYear() << "]" << "Name: " <<
       name << std::endl;
}
