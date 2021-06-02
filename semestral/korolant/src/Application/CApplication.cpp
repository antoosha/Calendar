#include "CApplication.h"
#include <fstream>

using namespace std;

/*
 * return 0 = all is OK
 * return -1 = nothing was written
 * return -2 = command does not exist
 * return -3 = command "quit"
 * return -4 = something went wrong
*/
void CApplication::run() {

    views.emplace("showDaily", new CDaily());
    views.emplace("showWeekly", new CWeekly());
    views.emplace("showMonthly", new CMonthly());
    views.emplace("showYearly", new CYearly());

    //ofstream MyFile("C:\\Users\\Anton\\Desktop\\file.txt");
    CCalendar cCalendar;
    CInterface  a(cin, cout, cCalendar);
    while(true){
        cout << "Write your command. If you want to see the list of commands, write \"help\"" << endl;
        a.getCommand();
        if(a.doSmthWithCommand(views) == -3){
            //MyFile.close();
            for(auto i = views.begin(); i != views.end(); i++){
                delete i->second;
            }
            return;
        }
    }
}
/*g++ main.cpp Application\CApplication.cpp Calendar\CCalendar.cpp Calendar\CDate.cpp Calendar\CEvent.cpp Calendar\COptional.cpp Calendar\CRequired.cpp ImportExport\CImportExport.cpp Interface\CInterface.cpp Postpone\CPostpone.cpp Repeat\CRepeat.cpp View\CDaily.cpp View\CMonthly.cpp View\CWeekly.cpp View\CYearly.cpp
*/
