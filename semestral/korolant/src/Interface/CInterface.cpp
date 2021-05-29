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
- `delete ...` smaže nějakou událost, aplikace se dotáže na další parametry
- `listEvents` výpíše vsechny události, které jsou v kalendáři
- `repeat ...` nastaví událost, kterou vybere uživatel, opakovaně, aplikace se dotáže na další parametry
- `move ...` přesune událost, kterou vybere uživatel, aplikace se dotáže na další parametry
- `showDaily` denní zobrazení kalendáře s udalostí, které má
- `showWeekly` tydenní zobrazení kalendáře s udalostí, které má
- `showMonthly` měsíční zobrazení kalendáře s udalostí, které má
- `find ...` vyhledá událost,  aplikace se dotáže na další parametry
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
        words.clear();
        return cCalendar.createEvent(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "delete")){
        words.clear();
        return cCalendar.deleteEvent(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "repeat")){
        CRepeat cRepeat;
        words.clear();
        return cRepeat.repeatEvent(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "listEvents")){
        words.clear();
        cCalendar.listEvents(m_In, m_Out, cCalendar);
        return 0;
    }
    else if(!strcasecmp(words[0].c_str(), "move")){
        CPostpone cPostpone;
        words.clear();
        return cPostpone.moveEvent(m_In, m_Out, cCalendar);
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
        CImportExport cImportExport;
        words.clear();
        return cImportExport.importData(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "save")){
        CImportExport cImportExport;
        words.clear();
        return cImportExport.exportData(m_In, m_Out, cCalendar);

    }
    else if(!strcasecmp(words[0].c_str(), "edit")){
        words.clear();
        return cCalendar.editEvent(m_In,m_Out,cCalendar);;
    }
    else if(!strcasecmp(words[0].c_str(), "find")){
        words.clear();
        return cCalendar.findEvent(m_In,m_Out,cCalendar);;
    }
    else if(!strcasecmp(words[0].c_str(), "help")){
        m_Out << "------HELP------" << endl;
        m_Out << "\"new\" ...  - create new event." << endl;
        m_Out << "\"delete ...\" smaže událost, aplikace se dotáže na další parametry." << endl;
        m_Out << "\"listEvents\" - výpíše vsechny události, které jsou v kalendáři." << endl;
        m_Out << "\"repeat ...\" - nastaví událost, kterou vybere uživatel, opakovaně, aplikace se dotáže na další parametry." << endl;
        m_Out << "\"move ...\" - přesune událost, kterou vybere uživatel, aplikace se dotáže na další parametry." << endl;
        m_Out << "\"showDaily\" - show calendar and all events by day." << endl;
        m_Out << "\"showWeekly\" - show calendar and all events by week." << endl;
        m_Out << "\"showMonthly\" - show calendar and all events by month." << endl;
        m_Out << "\"find ...\" - vyhledá událost,  aplikace se dotáže na další parametry." << endl;
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




