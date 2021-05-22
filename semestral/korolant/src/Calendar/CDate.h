#pragma once
#include <memory>

class CDate {
public:
    CDate() = default;
    CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn );

    void editDate(const CDate & dateFrom, const CDate & dateTo);

    int returnDay() const;
    int returnMonth() const;
    int returnYear() const;

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
};


