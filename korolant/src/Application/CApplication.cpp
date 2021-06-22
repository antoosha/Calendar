#include "CApplication.h"
#include <fstream>

using namespace std;

void CApplication::run() {

    views.emplace("showDaily", new CDaily());
    views.emplace("showWeekly", new CWeekly());
    views.emplace("showMonthly", new CMonthly());
    views.emplace("showYearly", new CYearly());

    CCalendar cCalendar;
    CInterface  a(cin, cout, cCalendar);
    while(true){
        cout << "+---------------------------------------------------------------------------+" << endl;
        cout << "| Write your command. If you want to see the list of commands, write \"help\" |" << endl;
        cout << "+---------------------------------------------------------------------------+" << endl;

        a.getCommand();
        if(cin.eof()){
            for(auto i = views.begin(); i != views.end(); i++){
                delete i->second;
            }
            return;
        }

        if(a.doSmthWithCommand(views) == -3){

            for(auto i = views.begin(); i != views.end(); i++){
                delete i->second;
            }

            return;
        }
    }
}

