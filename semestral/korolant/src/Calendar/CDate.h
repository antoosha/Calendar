#pragma once
#include <memory>
#include <string>

class CDate {
public:

    CDate() = default;

    /**
     * Constructor, witch sets parameters of object CDate.
     *
     * @param dayIn
     * @param monthIn
     * @param yearIn
     * @param hourIn
     * @param minuteIn
     */
    CDate(const int & dayIn, const int & monthIn, const int & yearIn, const int & hourIn, const int & minuteIn );

    /**
     * This method edit attributes of current object to attributes of input date type const reference to CDate
     *
     * @param date
     */
    void editDate(const CDate & date);

    /**
     * This method converts the date to string in format YYYYMMDDHHMM.
     *
     * @return converted date to string
     */
    std::string dateToString() const;

    /**
     * This method is used to know a number of day from input parameters
     * 0 = Sunday
     * 1 = Monday
     * 2 = Tuesday
     * 3 = Wednesday
     * 4 = Thursday
     * 5 = Friday
     * 6 = Saturday
     *
     * @param day
     * @param month
     * @param year
     * @return number of day in week
     */
    int dayNumber(int day, int month, int year) const;

    /**
     * This method moves minutes forward for minutes from input parameter
     * @param minutes for how many minutes to move
     */
    void moveMinutes(int minutes);

    /**
     * This method moves hours forward for hours from input parameter
     * @param hours for how many hours to move
     */
    void moveHours(int hours);

    /**
     * This method moves days forward for days from input parameter
     * @param days for how many days to move
     */
    void moveDays(int days);

    /**
     * This method moves months forward for months from input parameter
     * @param days for how many months to move
     */
    void moveMonths(int months);

    /**
     * This method moves years forward for years from input parameter
     * @param days for how many years to move
     */
    void moveYears(int years);

    /**
    * This method moves minutes back for minutes from input parameter
    * @param minutes for how many minutes to move
    */
    void moveMinutesBack(int minutes);

    /**
    * This method moves hours back for hours from input parameter
    * @param hours for how many hours to move
    */
    void moveHoursBack(int hours);

    /**
    * This method moves days back for days from input parameter
    * @param days for how many days to move
    */
    void moveDaysBack(int days);

    /**
    * This method moves months back for months from input parameter
    * @param months for how many months to move
    */
    void moveMonthsBack(int months);

    /**
    * This method moves years back for years from input parameter
    * @param years for how many years to move
    */
    void moveYearsBack(int years);

    /**
     * This method will return name of month using month number, which is an input parameter
     *
     * @param monthNumber
     * @return name of month
     * @throw out_of_range if the month > 11, {0,1...11}
     */
    std::string getMonthName(int monthNumber) const;

    /**
     * This method find how many number of days in month of year, which will get from input
     *
     *
     * @param monthNumber
     * @param year
     * @return number of days in input month for input year
     * @return -1 if input is not correct
     */
    int numberOfDays (int monthNumber, int year) const;

    /**
     * This method converts date from input to string in format YYYYMMDD
     *
     * @param yearIn
     * @param monthIn
     * @param dayIn
     * @return date converted to string
     */
    std::string dateToShortString(int yearIn, int monthIn, int dayIn) const;

    int returnDay() const;

    int returnMonth() const;

    int returnYear() const;

    int returnHour() const;

    int returnMinute() const;

private:
    int day;
    int month;
    int year;
    int hour;
    int minute;
};


