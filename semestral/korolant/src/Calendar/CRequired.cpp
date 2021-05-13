#include "CRequired.h"


std::shared_ptr<CDate> &CRequired::returnDateFrom(){
    return dateFrom;
}

std::shared_ptr<CDate> &CRequired::returnDateTo(){
    return dateTo;
}


void CRequired::printFunc(std::ostream &os) const {
    os << "[Required][" << dateFrom->returnDay() << "/" << dateFrom->returnMonth() << "/" << dateFrom->returnYear()
       << " - " << dateTo->returnDay() << "/" << dateTo->returnMonth() << "/" << dateTo->returnYear() << "]" << "Name: " <<
       name << std::endl;
}
