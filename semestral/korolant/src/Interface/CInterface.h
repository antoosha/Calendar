#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <limits>

class CInterface {

public:
    CInterface ( std::istream & in, std::ostream & out );

    int doSmthWithCommand();

    void getCommand();

protected:
    std::istream & m_In;
    std::ostream & m_Out;
    std::vector<std::string> words;
};


