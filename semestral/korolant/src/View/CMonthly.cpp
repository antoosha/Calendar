#include "CMonthly.h"
#include "../Calendar/CCalendar.h"
using namespace std;


//need to change to ostream(not to COUT!)
void CMonthly::show(ostream &os,  CCalendar * cCalendar) const {
    CView cView;
    time_t t = time(nullptr);
    tm* timePtr = localtime(&t);
    int year = timePtr->tm_year;


    os << "         Calendar - " << year << "\n\n";
    //printf ("         Calendar - %d\n\n", year);
    int days;

    // Index of the day from 0 to 6
    int current = cView.dayNumber(1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++) {
        days = cView.numberOfDays(i, year);

        // Print the current month name
        os << "\n  ------------" << cView.getMonthName(i).c_str() << "-------------\n";
        //printf("\n  ------------%s-------------\n",cView.getMonthName (i).c_str());

        // Print the columns
        os << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n";
        //printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++) {
            os << "     ";
            //printf("     ");
        }

        for (int j = 1; j <= days; j++) {

            os << j;
            //printf("%5d", j);

            if (++k > 6) {
                k = 0;
                os << endl;
                //printf("\n");
            }
        }

        if (k)
        {
            os << endl;
            //printf("\n");
        }

        current = k;

        // Print events from this month
        std::map<std::string, std::shared_ptr<CEvent>> printMap = cCalendar->returnMapByName();
        for(auto l = printMap.begin(); l != printMap.end(); l++){
            if(l->second->returnDateFrom()->returnMonth() == i){
                l->second->printFunc(os);
            }
        }
    }
}
