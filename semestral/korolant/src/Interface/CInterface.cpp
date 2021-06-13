#include "CInterface.h"

using namespace std;

CInterface::CInterface(istream &in, ostream &out, const CCalendar & cCalendarIn) : m_In(in), m_Out(out), cCalendar(cCalendarIn){
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
            while(j < line.size() && !isspace(line[j])) j++;
            word = line.substr(i, j-i);
            words.emplace_back(word);
            i = j;
        }
    }

}

int CInterface::doSmthWithCommand(std::map<std::string, CView*> & views){
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
        cCalendar.listEvents(m_Out, cCalendar);
        return 0;
    }
    else if(!strcasecmp(words[0].c_str(), "move")){
        CPostpone cPostpone;
        words.clear();
        return cPostpone.moveEvent(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "findFirstPossible")){
        words.clear();
        return cCalendar.findFirstPossible(m_In, m_Out, cCalendar);
    }
    else if(!strcasecmp(words[0].c_str(), "showDaily")){
        auto i = views.find("showDaily");
        if(i->second->setup(m_In, m_Out) != 0){
            words.clear();
            return -4;
        }

        i->second->show(m_Out, cCalendar);

        words.clear();
        while(true){
            int whatDoNext = i->second->navigation(m_In, m_Out);
            if(whatDoNext == 1){
                i->second->show(m_Out, cCalendar);
                continue;
            }
            else if(whatDoNext == -4){
                return -4;
            }
            else{
                return 0;
            }
        }
    }
    else if(!strcasecmp(words[0].c_str(), "showWeekly")){
        auto i = views.find("showWeekly");
        if(i->second->setup(m_In, m_Out) != 0){
            words.clear();
            return -4;
        }
        i->second->show(m_Out, cCalendar);

        words.clear();
        while(true){
            int whatDoNext = i->second->navigation(m_In, m_Out);
            if(whatDoNext == 1){
                i->second->show(m_Out, cCalendar);
                continue;
            }
            else if(whatDoNext == -4){
                return -4;
            }
            else{
                return 0;
            }
        }
    }
    else if(!strcasecmp(words[0].c_str(), "showMonthly")){
        auto i = views.find("showMonthly");
        if(i->second->setup(m_In, m_Out) != 0){
            words.clear();
            return -4;
        }
        i->second->show(m_Out, cCalendar);

        words.clear();
        while(true){
            int whatDoNext = i->second->navigation(m_In, m_Out);
            if(whatDoNext == 1){
                i->second->show(m_Out, cCalendar);
                continue;
            }
            else if(whatDoNext == -4){
                return -4;
            }
            else{
                return 0;
            }
        }
    }
    else if(!strcasecmp(words[0].c_str(), "showYearly")){
        auto i = views.find("showYearly");
        if(i->second->setup(m_In, m_Out) != 0){
            words.clear();
            return -4;
        }
        i->second->show(m_Out, cCalendar);

        words.clear();
        while(true){
            int whatDoNext = i->second->navigation(m_In, m_Out);
            if(whatDoNext == 1){
                i->second->show(m_Out, cCalendar);
                continue;
            }
            else if(whatDoNext == -4){
                return -4;
            }
            else{
                return 0;
            }
        }
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
        m_Out << "+-----------------------------------HELP------------------------------------+" << endl;
        m_Out << "| \"help\" - show all commands.                                               |" << endl;
        m_Out << "| \"new\" ...  - create new event.                                            |" << endl;
        m_Out << "| \"move\" ... - postopne event, which user will choose.                      |" << endl;
        m_Out << "| \"find\" ... - find event.                                                  |" << endl;
        m_Out << "| \"load\" ... - upload all events from the file called \"filename\".           |" << endl;
        m_Out << "| \"save\" ... - save all events to the file called \"filename\".               |" << endl;
        m_Out << "| \"edit\" ... - edit event.                                                  |" << endl;
        m_Out << "| \"delete\" ... delete event.                                                |" << endl;
        m_Out << "| \"repeat\" ... - set repeat for event with user's time interval.            |" << endl;
        m_Out << "| \"showDaily\" ... - show calendar and all events for day.                   |" << endl;
        m_Out << "| \"showWeekly\" ... - show calendar and all events for week.                 |" << endl;
        m_Out << "| \"showMonthly\" ... - show calendar and all events for month.               |" << endl;
        m_Out << "| \"showYearly\" ... - show calendar and all events for year.                 |" << endl;
        m_Out << "| \"listEvents\" ... - lists all events from calendar.                        |" << endl;
        m_Out << "| \"findFirstPossible\" ... - find first possible date to postpone event.      |" << endl;
        m_Out << "| \"quit\" - end the program.                                                 |" << endl;
        m_Out << "+-----------------------------------HELP------------------------------------+" << endl;
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
}




