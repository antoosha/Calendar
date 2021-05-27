#include "CImportExport.h"


using namespace std;

int CImportExport::importData(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {
    int howManyEventsHasBeenRead = 0;
    int howManyEventsHasBeenSkipped = 0;
    ifstream indata; // indata is like cin
    string fileName;
    m_Out << "Write path to file, from where you want to import data from calendar and press 'Enter':" << endl;
    m_Out << "Example: \"C:\\Users\\PC\\Desktop\\file.txt\"" << endl;
    m_In >> fileName;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    indata.open(fileName); // opens the file
    if(!indata) { // file couldn't be opened
        m_Out << "Error: file could not be opened, try again.." << endl;
        return -4;
    }
    if(indata.eof()){
        m_Out << "File is empty. Nothing was recorded." << endl;
        indata.close();
        return 0;
    }



    while ( !indata.eof() ) { // keep reading until end-of-file
        string commandNew = "";
        while(getline(indata, commandNew) && strcasecmp(commandNew.c_str(), "new")){
            // word is not new, we are skipping other linew from event, which was earlier
            //we are going to next event
            continue;
        }

        CDate * cDate;
        int id;
        string name;
        string dateFromIn;
        string dateToIn;
        string place;
        vector<string> members;
        string description;
        string obligation;
        int dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom;
        int dayTo, monthTo, yearTo, hourTo, minuteTo;

        CDate dateFrom;
        CDate dateTo;

        indata >> id;
        if(cCalendar.returnMapById().count(id) != 0){
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        getline(indata, name);

        indata >> yearFrom;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (yearFrom < 1600) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> monthFrom;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (monthFrom < 1 || monthFrom > 12) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> dayFrom;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (dayFrom > cDate->numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> hourFrom;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (hourFrom > 23 || hourFrom < 0) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> minuteFrom;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (minuteFrom > 59 || minuteFrom < 0) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        dateFrom = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);

        indata >> yearTo;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (yearTo < 1600) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> monthTo;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (monthTo < 1 || monthTo > 12) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> dayTo;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (dayTo > cDate->numberOfDays(monthTo - 1, yearTo) || dayTo < 1) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> hourTo;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (hourTo > 23 || hourTo < 0) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        indata >> minuteTo;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        if (minuteTo > 59 || minuteTo < 0) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        dateTo = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);

        if (dateFrom.dateToString() > dateTo.dateToString()) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        std::getline(indata, place);

        while(1) {
            char sign;
            indata >> sign;
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            if(sign == '+'){
                string memberIn;
                getline(indata, memberIn);
                members.emplace_back(memberIn);
                continue;
            }
            else{
                break;
            }
        }

        getline(indata, description);

        indata >> obligation;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');
        if(strcasecmp(obligation.c_str(), "required") < 0){
            if(strcasecmp(obligation.c_str(), "optional") < 0){
                howManyEventsHasBeenSkipped++;
                continue;
            }
        }


        cCalendar.addEvent(id, name, dateFrom, dateTo, place, members, description, obligation);

        howManyEventsHasBeenRead++;
    }

    m_Out << howManyEventsHasBeenRead << "/" << howManyEventsHasBeenRead + howManyEventsHasBeenSkipped << " events has been loaded." << endl;

    indata.close();
    return 0;
}

int CImportExport::exportData (std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {
    string fileName;
    m_Out << "Write path to file, where you want to export data from calendar and press 'Enter':" << endl;
    m_Out << "Example: \"C:\\Users\\PC\\Desktop\\file.txt\"" << endl;
    m_In >> fileName;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

    ofstream outdata; // outdata is like cin
    outdata.open(fileName); // opens the file
    if( !outdata ) { // file couldn't be opened
        m_Out << "Error: file could not be opened, try again.." << endl;
        return -4; //something went wrong
    }

    if(cCalendar.returnMapById().empty()){
        m_Out << "Events has not been saved, calendar has not any events." << endl;
        outdata.close();
        return 0;
    }

    for(auto i = cCalendar.returnMapById().begin(); i != cCalendar.returnMapById().end(); i++){
        i->second->printFunc(outdata);
        outdata << std::endl;
    }

    m_Out << "Events has been saved." << endl;
    outdata.close();
    return 0;
}
