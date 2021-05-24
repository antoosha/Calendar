#include "CApplication.h"
#include "../Interface/CInterface.h"
#include <fstream>
using namespace std;
void run(){}


/*
 * return 0 = all is OK
 * return -1 = nothing was written
 * return -2 = command does not exist
 * return -3 = command "quit"
 * return -4 = something went wrong
*/
void CApplication::run() {
    //TODO could be problem if CIN COUT is wrong
    //ofstream MyFile("C:\\Users\\Anton\\Desktop\\file.txt");
    CInterface  a(cin, cout);
    while(1){
        cout << "Write you command, if you want to see the list of commands, write \"help\"" << endl;
        a.getCommand();
        if(a.doSmthWithCommand() == -3){

          //  MyFile.close();

            return;
        }

    }

}
