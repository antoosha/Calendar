#include "Application/CApplication.h"
using namespace std;

//int argc, char * argv[]
int main(){

    CApplication application;
    application.run();

    return 0;
}

//тесты сделать, попытаться сломать программу

/*
если файл не открыть
если ввели вместо инта букву/буквы
если файл не существует
Nezapomeňte, že vstupem jsou i různé druhy souborů a tak je potřeba ošetřit i načítání (nebo i ukládání) z těchto souborů.
Typicky neexistující soubor, soubor bez práv k přístupu, atp.
*/




//main.o CApplication.o CCalendar.o CDate.o CEvent.o COptional.o CRequired.o CImportExport.o CInterface.o CPostpone.o CRepeat.o CDaily.o CMonthly.o CWeekly.o CYearly.o