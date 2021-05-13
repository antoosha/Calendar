#include "COptional.h"


std::shared_ptr<CDate> &COptional::returnDateFrom(){
    return dateFrom;
}

std::shared_ptr<CDate> &COptional::returnDateTo(){
    return dateTo;
}

void COptional::printFunc(std::ostream &os) const {
    os << "[Optional][" << dateFrom->returnDay() << "/" << dateFrom->returnMonth() << "/" << dateFrom->returnYear()
    << " - " << dateTo->returnDay() << "/" << dateTo->returnMonth() << "/" << dateTo->returnYear() << "]" << "Name: " <<
    name << std::endl;
}
