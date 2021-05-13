#pragma once
#include <memory>

class CDate {
public:
    CDate() = default;
    CDate(const int & day, const int & month, const int & year);

    void editDate(const std::shared_ptr<CDate> & dateFrom, const std::shared_ptr<CDate> & dateTo);

    int returnDay() const;
    int returnMonth() const;
    int returnYear() const;

private:
    int day;
    int month;
    int year;
};


