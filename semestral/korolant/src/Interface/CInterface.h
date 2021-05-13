#pragma once
#include <iostream>

class CInterface {

protected:
    std::istream & m_In;
    std::ostream & m_Out;

public:
    CInterface ( std::istream & in, std::ostream & out );


    //string getCommand()

    //получит комманлу а потом с ней просто что то сделает
};


