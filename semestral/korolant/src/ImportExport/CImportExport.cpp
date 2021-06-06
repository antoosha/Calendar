#include "CImportExport.h"


using namespace std;

CDate * cDate;

int CImportExport::importData(std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) {
    int howManyEventsHasBeenRead = 0;
    int howManyEventsHasBeenSkipped = 0;
    ifstream indata; // indata is like cin
    string fileName;
    m_Out << "Write path to file, from where you want to import data to calendar and press 'Enter':" << endl;
    m_In >> fileName;

    indata.open(fileName); // opens the file
    if(!indata) { // file couldn't be opened
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Error: file could not be opened, try again.." << endl;
        return -4;
    }
    if(indata.eof()){
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "File is empty. Nothing was recorded." << endl;
        indata.close();
        return 0;
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');



    while ( !indata.eof() ) { // keep reading until end-of-file
        string commandNew;
        while(getline(indata, commandNew) && strcasecmp(commandNew.c_str(), "new")){
            if(indata.eof()){
                m_Out << howManyEventsHasBeenRead << "/" << howManyEventsHasBeenRead + howManyEventsHasBeenSkipped << " events has been loaded." << endl;
                indata.close();
                return 0;
            }
            // word is not new, we are skipping other line from event, which was earlier
            //we are going to next event
            continue;
        }


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

        CDate dateFrom = {};
        CDate dateTo = {};

        id = cCalendar.generateId(cCalendar);
        if(cCalendar.returnMapById().count(id) != 0){
            howManyEventsHasBeenSkipped++;
            continue;
        }

        getline(indata, name);
        if(indata.eof()) continue;
        if(name.empty()){
            continue;
        }

        indata >> yearFrom;

        if (yearFrom < 1600 || yearFrom > 9999 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> monthFrom;

        if (monthFrom < 1 || monthFrom > 12 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> dayFrom;

        if (dayFrom > cDate->numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> hourFrom;

        if (hourFrom > 23 || hourFrom < 0 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> minuteFrom;

        if (minuteFrom > 59 || minuteFrom < 0 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        dateFrom = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);

        indata >> yearTo;

        if (yearTo < 1600 || yearTo > 9999 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> monthTo;

        if (monthTo < 1 || monthTo > 12 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> dayTo;

        if (dayTo > cDate->numberOfDays(monthTo - 1, yearTo) || dayTo < 1 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> hourTo;

        if (hourTo > 23 || hourTo < 0 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        indata >> minuteTo;

        if (minuteTo > 59 || minuteTo < 0 || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            howManyEventsHasBeenSkipped++;
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');

        dateTo = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);

        if (dateFrom.dateToString() > dateTo.dateToString()) {
            howManyEventsHasBeenSkipped++;
            continue;
        }

        std::getline(indata, place);
        if(place.empty()){
            continue;
        }

        while(1) {
            char sign;
            indata >> sign;
            if((sign != '+' && sign != '-') || indata.fail() ){
                indata.clear();
                indata.ignore(numeric_limits<streamsize>::max(), '\n');
                break;
            }
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            if(sign == '+'){
                string memberIn;
                getline(indata, memberIn);
                if(memberIn.empty()){
                    continue;
                }
                members.emplace_back(memberIn);
                continue;
            }
            else{
                break;
            }
        }


        char sign = ' ';
        indata >> sign;
        if ((sign != '+' && sign != '-') || indata.fail()) {
            indata.clear();
            indata.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        indata.ignore(numeric_limits<streamsize>::max(), '\n');
        if (sign == '+') {
            getline(indata, description);
            if (description.empty()) {
                continue;
            }
        }

        indata >> obligation;
        indata.ignore(numeric_limits<streamsize>::max(), '\n');
        if(strcasecmp(obligation.c_str(), "required") != 0){
            if(strcasecmp(obligation.c_str(), "optional") != 0){
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

int CImportExport::exportData (std::istream & m_In, std::ostream & m_Out, CCalendar & cCalendar) const {
    string fileName;
    m_Out << "Write path to file, where you want to export data from calendar and press 'Enter':" << endl;
    m_Out << "Attantion! The data in the file will be overwritten." << endl;
    m_In >> fileName;

    ofstream outdata; // outdata is like cin
    outdata.open(fileName); // opens the file
    if( !outdata ) { // file couldn't be opened
        m_In.clear();
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        m_Out << "Error: file could not be opened, try again.." << endl;
        return -4; //something went wrong
    }
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

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
