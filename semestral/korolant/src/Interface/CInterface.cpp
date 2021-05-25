#include "CInterface.h"

using namespace std;

CInterface::CInterface(istream &in, ostream &out, const CCalendar & cCalendarIn) : m_In(in), m_Out(out), cCalendar(cCalendarIn) {
    words.resize(0);
}

void CInterface::getCommand(){

    string word;
    string line;
    int flag = 0;

    if(!getline(m_In, line)){
        words.resize(0);
        return;
    }
    else
    {

        for(size_t i = 0; i < line.size(); i++) {
            if (isspace(line[i])) {
                continue;
            }
            flag++;
            size_t j = i;
            while(!isspace(line[j])) j++;
            word = line.substr(i, j-i);
            words.emplace_back(word);
            i = j;
        }
    }

}

/*
- `new ...` vytvoří novou událost, aplikace se dotáže na další parametry
-  `showDaily` denní zobrazení kalendáře s udalostí, které má
-  `showWeekly` tydenní zobrazení kalendáře s udalostí, které má
-  `showMonthly` měsíční zobrazení kalendáře s udalostí, které má
- `load [filename]` načte události ze souboru
- `save [filename]` uloží události do souboru
- `edit ...` změní událost, aplikace se dotáže na další parametry
- `help` zobrazí nápovědu
- `quit` ukončí program
 */
int CInterface::doSmthWithCommand(){
    if(words.empty()){
        m_Out << "Nothing was written. Try again or write \"help\" to show all commands.. " << endl;
        words.clear();
        return -1; // nothing was written
    }

    if(!strcasecmp(words[0].c_str(), "new")){
        CView cView;
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


        m_Out << "Write id of this event:" << endl;
        m_In >> id;
        if(cCalendar.returnMapById().count(id) != 0){
            m_Out << "Event with same id exists, try again.." << endl;
            return -4; // something went wrong
        }
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');


        m_Out << "Write name of this event and press 'Enter':" << endl;
        getline(m_In, name);


        /*m_Out << "Write date 'from' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
        getline(m_In, dateFromIn);
        if(dateFromIn.size() != 16){
            m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
            return -4; // something went wrong
        }
        dateFrom = CDate(dateFromIn);*/

        int flagSecondGreaterThanFirst = 0;
        while(flagSecondGreaterThanFirst == 0) {
            int flagDateFrom = 0;
            while (flagDateFrom == 0) {
                m_Out << "Write year of date 'from' and press 'Enter':" << endl;
                m_In >> yearFrom;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (yearFrom < 1600) {
                    m_Out << "Year is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write month of date 'from' and press 'Enter':" << endl;
                m_In >> monthFrom;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (monthFrom < 1 || monthFrom > 12) {
                    m_Out << "Month is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write day of date 'from' and press 'Enter':" << endl;
                m_In >> dayFrom;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (dayFrom > cView.numberOfDays(monthFrom - 1, yearFrom) || dayFrom < 1) {
                    m_Out << "Day is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
                m_In >> hourFrom;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (hourFrom > 23 || hourFrom < 0) {
                    m_Out << "Hour is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
                m_In >> minuteFrom;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (minuteFrom > 59 || minuteFrom < 0) {
                    m_Out << "Minutes are not correct, try again.." << endl;
                    continue;
                }

                dateFrom = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);
                flagDateFrom = 1;
            }


            /*m_Out << "Write date 'to' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
            getline(m_In, dateToIn);
            if(dateToIn.size() != 16){
                m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
                return -4; // something went wrong
            }
            dateTo = CDate(dateToIn);
            */

            //TODO problem if second date min then first
            int flagDateTo = 0;
            while (flagDateTo == 0) {
                m_Out << "Write year of date 'to' and press 'Enter':" << endl;
                m_In >> yearTo;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (yearTo < 1600) {
                    m_Out << "Year is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write month of date 'to' and press 'Enter':" << endl;
                m_In >> monthTo;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (monthTo < 1 || monthTo > 12) {
                    m_Out << "Month is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write day of date 'to' and press 'Enter':" << endl;
                m_In >> dayTo;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (dayTo > cView.numberOfDays(monthTo - 1, yearTo) || dayTo < 1) {
                    m_Out << "Day is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
                m_In >> hourTo;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (hourTo > 23 || hourTo < 0) {
                    m_Out << "Hour is not correct, try again.." << endl;
                    continue;
                }

                m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
                m_In >> minuteTo;
                m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                if (minuteTo > 59 || minuteTo < 0) {
                    m_Out << "Minutes are not correct, try again.." << endl;
                    continue;
                }

                dateTo = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);
                flagDateTo = 1;
            }
            if (dateFrom.dateToString() > dateTo.dateToString()) {
                m_Out << "First date is greater, than second, try again.." << endl;
                continue;
            }
            flagSecondGreaterThanFirst = 1;
        }

        m_Out << "Write place of this event and press 'Enter':" << endl;
        std::getline(m_In, place);

        while(1) {
            char sign;
            m_Out << "If you want to add member, write \"+\" and press 'Enter':" << endl;
            m_Out << "If you DO NOT want to add member, write \"-\" and press 'Enter':" << endl;
            m_In >> sign;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            if(sign == '+'){
                m_Out << "Write person, who you want to add to this event and press 'Enter':" << endl;
                string memberIn;
                getline(m_In, memberIn);
                members.emplace_back(memberIn);
                m_Out << "Person " << memberIn << " has been successfully added." << endl;
                continue;
            }
            else{
                break;
            }
        }


        m_Out << "Write description of this event and press 'Enter':" << endl;
        getline(m_In, description);


        m_Out << "Choose obligation of this event, write \"required\" or \"optional\" and press 'Enter':" << endl;
        m_In >> obligation;
        m_In.ignore(numeric_limits<streamsize>::max(), '\n');
        if(strcasecmp(obligation.c_str(), "required") < 0){
            if(strcasecmp(obligation.c_str(), "optional") < 0){
                m_Out << "You should write obligation in correct format \"required\" or \"optional\", try again.." << endl;
                return -4; // something went wrong
            }
        }


        cCalendar.createEvent(id, name, dateFrom, dateTo, place, members, description, obligation);

        cout << endl;
        (cCalendar.returnMapById()).at(id)->printFunc(cout);
        cout << endl;

        words.clear();
        return 0; //OK
    }

    else if(!strcasecmp(words[0].c_str(), "showDaily")){
        //TODO emplement calling "showDaily"
        words.clear();
    }
    else if(!strcasecmp(words[0].c_str(), "showWeekly")){
        //TODO emplement calling "showWeekly"
        words.clear();
    }
    else if(!strcasecmp(words[0].c_str(), "showMonthly")){
        //TODO emplement calling "showMonthly"
        words.clear();
    }
    else if(!strcasecmp(words[0].c_str(), "load")){
        //TODO emplement calling "load"
        words.clear();
    }
    else if(!strcasecmp(words[0].c_str(), "save")){
        //TODO emplement calling "save"
        words.clear();
    }
    else if(!strcasecmp(words[0].c_str(), "edit")){
        //TODO problem if second date min then first
        int flagIfIdIsCorrect = 0;
        int id;
        while(flagIfIdIsCorrect == 0) {
            CView cView;
            int dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom;
            int dayTo, monthTo, yearTo, hourTo, minuteTo;
            int number;
            m_Out << "Write ID of event you want to change and press 'Enter':" << endl;
            m_In >> id;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            if(cCalendar.returnMapById().count(id) == 0){
                m_Out << "ID does not exist, try again.." << endl;
                continue;
            }
            m_Out << "Choose number, which you want to change and press 'Enter':" << endl;
            m_Out << "1) Date from" << endl;
            m_Out << "2) Date to" << endl;
            m_In >> number;
            m_In.ignore(numeric_limits<streamsize>::max(), '\n');
            if (number == 1) {

                CDate newDate;
                int flagDateFrom = 0;
                while(flagDateFrom == 0) {
                    m_Out << "Write year of date 'from' and press 'Enter':" << endl;
                    m_In >> yearFrom;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(yearFrom < 1600){
                        m_Out << "Year is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write month of date 'from' and press 'Enter':" << endl;
                    m_In >> monthFrom;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(monthFrom < 1 || monthFrom > 12){
                        m_Out << "Month is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write day of date 'from' and press 'Enter':" << endl;
                    m_In >> dayFrom;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(dayFrom > cView.numberOfDays(monthFrom-1, yearFrom) || dayFrom < 1){
                        m_Out << "Day is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write hour of date 'from' and press 'Enter':" << endl;
                    m_In >> hourFrom;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(hourFrom > 23 || hourFrom < 0){
                        m_Out << "Hour is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write minute of date 'from' and press 'Enter':" << endl;
                    m_In >> minuteFrom;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(minuteFrom > 59 || minuteFrom < 0){
                        m_Out << "Minutes are not correct, try again.." << endl;
                        continue;
                    }

                    newDate = CDate(dayFrom, monthFrom, yearFrom, hourFrom, minuteFrom);

                    if(newDate.dateToString() > cCalendar.returnMapById().at(id)->returnDateTo().dateToString()){
                        m_Out << "First date is greater, than second, try again to edit date \"from\".." << endl;
                        continue;
                    }

                    flagDateFrom = 1;
                }
                cCalendar.returnMapById().at(id)->returnDateFrom().editDate(newDate);
                m_Out << "Date was successfully changed." << endl;
                break;
            } else if (number == 2) {
                CDate newDate;
                int flagDateTo = 0;
                while(flagDateTo == 0) {
                    m_Out << "Write year of date 'to' and press 'Enter':" << endl;
                    m_In >> yearTo;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(yearTo < 1600){
                        m_Out << "Year is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write month of date 'to' and press 'Enter':" << endl;
                    m_In >> monthTo;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(monthTo < 1 || monthTo > 12){
                        m_Out << "Month is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write day of date 'to' and press 'Enter':" << endl;
                    m_In >> dayTo;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(dayTo > cView.numberOfDays(monthTo-1, yearTo) || dayTo < 1){
                        m_Out << "Day is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write hour of date 'to' and press 'Enter':" << endl;
                    m_In >> hourTo;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(hourTo > 23 || hourTo < 0){
                        m_Out << "Hour is not correct, try again.." << endl;
                        continue;
                    }

                    m_Out << "Write minute of date 'to' and press 'Enter':" << endl;
                    m_In >> minuteTo;
                    m_In.ignore(numeric_limits<streamsize>::max(), '\n');

                    if(minuteTo > 59 || minuteTo < 0){
                        m_Out << "Minutes are not correct, try again.." << endl;
                        continue;
                    }

                    newDate = CDate(dayTo, monthTo, yearTo, hourTo, minuteTo);

                    if(cCalendar.returnMapById().at(id)->returnDateFrom().dateToString() > newDate.dateToString() ){
                        m_Out << "First date is greater, than second, try again to edit date \"to\".." << endl;
                        continue;
                    }

                    flagDateTo = 1;
                }
                cCalendar.returnMapById().at(id)->returnDateTo().editDate(newDate);
                m_Out << "Date was successfully changed." << endl;
                break;
            }
            else{
                m_Out << "Please choose correct number, try again.." << endl;
                continue;
            }
            flagIfIdIsCorrect = 1;
        }

        cout << endl;
        (cCalendar.returnMapById()).at(id)->printFunc(cout);
        cout << endl;
        words.clear();
        return 0;
    }
    else if(!strcasecmp(words[0].c_str(), "help")){
        m_Out << "------HELP------" << endl;
        m_Out << "\"new\" ...  - create new event." << endl;
        m_Out << "\"showDaily\" - show calendar and all events by day." << endl;
        m_Out << "\"showWeekly\" - show calendar and all events by week." << endl;
        m_Out << "\"showMonthly\" - show calendar and all events by month." << endl;
        m_Out << "\"load [filename]\" - upload all events from the file called \"filename\"." << endl;
        m_Out << "\"save [filename]\" - save all events to the file called \"filename\"." << endl;
        m_Out << "\"edit\" ... - edit event." << endl;
        m_Out << "\"help\" - show all commands." << endl;
        m_Out << "\"quit\" - end the program." << endl;
        m_Out << "------HELP------" << endl;
        words.clear();
        return 0;
    }
    else if(!strcasecmp(words[0].c_str(), "quit")){
        m_Out << "Thank you for using this calendar, we hope we will see you soon!" << endl;
        words.clear();
        return -3; //quit
    }
    else{
        m_Out << "This command does not exist. Try again or write \"help\" to show all commands.." << endl;
        words.clear();
        return -2; //does not exist
    }
    return 0;
}




