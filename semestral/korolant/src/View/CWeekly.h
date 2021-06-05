#pragma once
#include "CView.h"

class CWeekly : public CView {
public:

    ~CWeekly() override = default;

    /**
     * This method is overwritten by same method in CView. It represents calendar.
     * @param os
     * @param cCalendar
     */
    void show(std::ostream &os, CCalendar & cCalendar) const override;

    /**
     * This method is overwritten by same method in CView. It setups parameters before showing them using method show.
     * @param in
     * @param os
     * @return
     */
    int setup( std::istream & in, std::ostream & os) override;

    /**
    * This method is overwritten by same method in CView. It navigate user in calendar.
    * @param in
    * @param os
    * @return
    */
    int navigation ( std::istream & in, std::ostream & os) override;
};


