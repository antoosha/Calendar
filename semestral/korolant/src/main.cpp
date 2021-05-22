#include "Application/CApplication.h"
#include <iostream>
using namespace std;
int main(int argc, char * argv[]){

    CApplication application;
    application.run();

    return 0;
}

//jak by ideálně mělo fungovat to přesouvání, co když přesouváme CFirstPossible nebo prostě když přesouváme
//(должна ещё быть продолжительность)

////////////////////////////////////////////////////////////////////////////////////////////////////
/*
 * přidat minuty a hodiny v CDate + přidat to do vypisu + pridat как долго оно происходит, лучше что бы было только начало и как долго оно длится
 * CDate asi není nutné ukládat jako shared_ptr, stačí prostě CDate bych řekl
 */