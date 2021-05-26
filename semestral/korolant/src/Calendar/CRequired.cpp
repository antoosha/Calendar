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
       << " - " << dateTo.returnDay() << "/" << dateTo.returnMonth() << "/" << dateTo.returnYear() << "]" << " Name: " <<
       name << std::endl;
    os << "\tPlace: " << place << std::endl;

    if(!members.empty()) {
        os << "\tMembers:" << std::endl;
        for (size_t i = 0; i < members.size(); i++) {
            os << "\t" << i+1 << ") " << members[i] << std::endl;
        }
    }
    os << "\tDescription: " << description << std::endl;

}
