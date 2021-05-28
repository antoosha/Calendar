#include "COptional.h"

/*void COptional::printFunc(std::ostream &os) const {
    os << "[Optional][" << dateFrom.returnDate() << " - " << dateTo.returnDate() << "]" << "Name: " <<
       name << std::endl;
}
*/
void COptional::printFunc(std::ostream &os) const  {
    os << "[ID:"<< id << "][Optional][" << dateFrom.returnDay() << "/" << dateFrom.returnMonth() << "/" << dateFrom.returnYear()
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


