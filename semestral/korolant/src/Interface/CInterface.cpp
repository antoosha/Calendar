#include "CInterface.h"
#include "../Calendar/CCalendar.h"

using namespace std;

CInterface::CInterface(istream &in, ostream &out) : m_In(in), m_Out(out) {
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
        CCalendar cCalendar;
        int id;
        string name;
        string dateFromIn;
        string dateToIn;
        string place;
        vector<string> members;
        string description;
        string obligation;

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


        m_Out << "Write date 'from' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
        getline(m_In, dateFromIn);
        if(dateFromIn.size() != 16){
            m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
            return -4; // something went wrong
        }
        dateFrom = CDate(dateFromIn);


        m_Out << "Write date 'to' in format \"dd/mm/year hour:minute\" and press 'Enter':" << endl;
        getline(m_In, dateToIn);
        if(dateToIn.size() != 16){
            m_Out << "You should write date in correct format \"dd/mm/year hour:minute\", try again.." << endl;
            return -4; // something went wrong
        }
        dateTo = CDate(dateToIn);


        m_Out << "Write place of this event and press 'Enter':" << endl;
        std::getline(m_In, place);

        //TODO do it another way, because if person hace name and surname, than will be problem
        m_Out << "Write all members(without commas, use spaces to split persons), which will at this event and press 'Enter':" << endl;
        string membersIn;
        string person;
        getline(m_In, membersIn);
        for (size_t i = 0; i < membersIn.size(); i++) {
            if (isspace(membersIn[i])) {
                continue;
            }
            size_t j = i;
            while (!isspace(membersIn[j])) j++;
            person = membersIn.substr(i, j - i);
            members.emplace_back(person);
            i = j;
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
        //cout << endl;
       // (cCalendar.returnMapById()).at(id)->printFunc(cout);
        //cout << endl;
        words.clear();
        return 0;
    }

    else if(!strcasecmp(words[0].c_str(), "showDaily")){
        //TODO emplement calling "showDaily"
    }
    else if(!strcasecmp(words[0].c_str(), "showWeekly")){
        //TODO emplement calling "showWeekly"
    }
    else if(!strcasecmp(words[0].c_str(), "showMonthly")){
        //TODO emplement calling "showMonthly"
    }
    else if(!strcasecmp(words[0].c_str(), "load")){
        //TODO emplement calling "load"
    }
    else if(!strcasecmp(words[0].c_str(), "save")){
        //TODO emplement calling "save"
    }
    else if(!strcasecmp(words[0].c_str(), "edit")){
        //TODO emplement calling "edit"
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

