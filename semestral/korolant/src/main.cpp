#include "Application/CApplication.h"
using namespace std;
int main(int argc, char * argv[]){

    CApplication application;
    application.run();

    return 0;
}


///доработать конструкторы/деструкторы = delete, = default..., нужно проверить на оибки и на память
///сделать выписы календаря проверять попадает ли в данный интервал с помощью перевода даты в стринг и так проверять для дня
//для дня завдавать все три день, месяц, год
//для месяца задавать месяц и год и выписывать ТОЛЬКО этот месяц
//для недели задавать месяц и номер недели, всего их 4
//для года использовать ту которая работает сейчас и выписывает под каждым месяцем, задавать только год

///тесты сделать, попытаться сломать программу
///ошетршени вступу
/*
если файл не открыть
если ввели вместо инта букву/буквы
если файл не существует
Nezapomeňte, že vstupem jsou i různé druhy souborů a tak je potřeba ošetřit i načítání (nebo i ukládání) z těchto souborů.
 Typicky neexistující soubor, soubor bez práv k přístupu, atp.
 может попробовать подключить красивый выпис ncurses
 */

