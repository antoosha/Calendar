#pragma once
#include <memory>
#include <string>

class CDate {
public:
    CDate() = default;
    CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn );
    //explicit CDate(const std::string & dateIn );


    void editDate(const CDate & date);

    std::string dateToString() const;

    int dayNumber(int day, int month, int year) const;

    std::string getMonthName(int monthNumber) const;

    int numberOfDays (int monthNumber, int year) const;

    //std:: string returnDate() const;

    int returnDay() const;
    int returnMonth() const;
    int returnYear() const;

private:
    //std::string date;
    int day;
    int month;
    int year;
    int hour;
    int minute;
};


