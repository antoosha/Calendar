#include "CApplication.h"
#include "../Interface/CInterface.h"
using namespace std;
void run(){}

void CApplication::run() {
    //TODO věčný cyklus, pokud se na vstupu neobjeví quit
    //TODO could be problem if CIN COUT is wrong
    CInterface  a(cin, cout);
    while(1){
        a.getCommand();
        if(a.doSmthWithCommand() == -3){
            return;
        }

    }

}
