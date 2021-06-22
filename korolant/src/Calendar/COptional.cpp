#include "COptional.h"

void COptional::printFunc(std::ostream &os) const  {
    char s1[17];
    s1[16] = '\0';
    char s2[17];
    s2[16] = '\0';
    std::sprintf(s1, "%02d/%02d/%04d %02d:%02d",dateFrom.returnDay(), dateFrom.returnMonth(),
                 dateFrom.returnYear(), dateFrom.returnHour(), dateFrom.returnMinute());
    std::sprintf(s2, "%02d/%02d/%04d %02d:%02d",dateTo.returnDay(), dateTo.returnMonth(),
                 dateTo.returnYear(), dateTo.returnHour(), dateTo.returnMinute());


    os << "[ID:"<< id << "][Optional][" << s1 << " - " << s2  << "] Name: " <<
       name << std::endl;
    os << "\tPlace: " << place << std::endl;

    if(!members.empty()) {
        os << "\tMembers:" << std::endl;
        for (size_t i = 0; i < members.size(); i++) {
            os << "\t " << i+1 << ") " << members[i] << std::endl;
        }
    }
    if(!description.empty()){
        os << "\tDescription: " << description << std::endl;
    }
}


