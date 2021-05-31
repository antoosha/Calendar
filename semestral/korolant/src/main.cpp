#include "Application/CApplication.h"
using namespace std;
int main(int argc, char * argv[]){

    CApplication application;
    application.run();

    return 0;
}

//пройтись по семестралке Давида и посмотреть как у меня

///доработать конструкторы/деструкторы = delete, = default..., нужно проверить на оибки и на память

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

