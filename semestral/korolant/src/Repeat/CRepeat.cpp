#include "CRepeat.h"
using namespace std;

int CRepeat::repeatEvent(istream &m_In, ostream &m_Out, CCalendar &cCalendar) {
    int id;
    m_Out << "Write id of event what you want to repeat and press 'Enter':" << endl;
    m_In >> id;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(!cCalendar.returnMapById().count(id)){
        m_Out << "Event with id " << id << "does not exist, try again.."  << endl;
        return -4;
    }
    int howManyTimesToRepeat;
    m_Out << "Write how many times you want to repeat this event and press 'Enter':" << endl;
    m_In >> howManyTimesToRepeat;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(howManyTimesToRepeat < 1){
        m_Out << "Number of times should be greater than 0, try again.."  << endl;
        return -4;
    }
    int number;
    m_Out << "Choose at what interval you want to repeat this event and press 'Enter':" << endl;
    m_Out << "1) Every day" << endl;
    m_Out << "2) Every week" << endl;
    m_Out << "3) Every month" << endl;
    m_Out << "4) Every year" << endl;
    m_In >> number;
    m_In.ignore(numeric_limits<streamsize>::max(), '\n');
    if(number < 1 || number > 4){
        m_Out << "Number is not correct, try again.." << endl;
        return -4;
    }
    if(number == 1){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveDays(1);
            newDateTo.moveDays(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(cCalendar.generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)cCalendar.generateId(cCalendar)-1;
        }
    }
    else if(number == 2){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveDays(7);
            newDateTo.moveDays(7);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(cCalendar.generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)cCalendar.generateId(cCalendar)-1;
        }
    }
    else if(number == 3){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveMonths(1);
            newDateTo.moveMonths(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(cCalendar.generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)cCalendar.generateId(cCalendar)-1;
        }
    }
    else if(number == 4){
        int exampleId = id;
        for(size_t i = 0; i < howManyTimesToRepeat; i++){
            CDate newDateFrom = cCalendar.returnMapById().at(exampleId)->returnDateFrom();
            CDate newDateTo = cCalendar.returnMapById().at(exampleId)->returnDateTo();
            newDateFrom.moveYears(1);
            newDateTo.moveYears(1);
            string obligation;
            (!strcmp(typeid(cCalendar.returnMapById().at(exampleId)).name(), "Optional")) ? obligation = "optional" : obligation = "required";
            cCalendar.addEvent(cCalendar.generateId(cCalendar), cCalendar.returnMapById().at(exampleId)->returnName(),
                               newDateFrom, newDateTo,
                               cCalendar.returnMapById().at(exampleId)->returnPlace(),
                               cCalendar.returnMapById().at(exampleId)->returnMembers(),
                               cCalendar.returnMapById().at(exampleId)->returnDescription(),
                               obligation);
            exampleId = (int)cCalendar.generateId(cCalendar)-1;
        }
    }
    m_Out << "Event was repeated." << endl;
    return 0;
}
