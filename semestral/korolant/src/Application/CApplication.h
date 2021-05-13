#pragma once


class CApplication {
public:
    CApplication () = default;
    CApplication ( const CApplication & ) = delete;
    CApplication & operator= ( const CApplication & ) = delete;
    ~CApplication () = default;

    void run();
};


