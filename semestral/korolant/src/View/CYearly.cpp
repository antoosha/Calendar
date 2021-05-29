#include "CYearly.h"

void CYearly::show(std::ostream &os, CCalendar &cCalendar) const {
    CDate * cDate;
    int year = 2021;

    printf ("         Calendar - %d\n\n", year);
    int days;

    // Index of the day from 0 to 6
    int current = cDate->dayNumber(1, 1, year);

    // i --> Iterate through all the months
    // j --> Iterate through all the days of the
    //       month - i
    for (int i = 0; i < 12; i++) {
        days = cDate->numberOfDays(i, year);

        // Print the current month name
        printf("\n  ------------%s-------------\n",cDate->getMonthName (i).c_str());

        // Print the columns
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");

        // Print appropriate spaces
        int k;
        for (k = 0; k < current; k++) {
            printf("     ");
        }

        for (int j = 1; j <= days; j++) {

            printf("%5d", j);

            if (++k > 6) {
                k = 0;
                printf("\n");
            }
        }

        if (k)
        {
            printf("\n");
        }

        current = k;

        // Print events from this month
        std::multimap<std::string, std::shared_ptr<CEvent>> printMap = cCalendar.returnMapByName();

        for(auto l = printMap.begin(); l != printMap.end(); l++){
            if(l->second->returnDateFrom().returnMonth() == i){
                l->second->printFunc(os);
            }
        }
    }
}

void CYearly::setup(std::istream &in, std::ostream &os, CCalendar &cCalendar) {

}
