#ifndef DATE_H
#define DATE_H
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>


class Date
{
public:
    Date();
    Date(const std::string& date);//ok
    Date(int year, int month, int day);//ok
    Date(const char* date);//ok
    long operator-(const Date& other) const;//okS
    long daysBetween(const Date& other) const;//ok
    long weeksBetween(const Date& other) const;//ok
    operator std::string () const;//ok
    std::string toSqlString() const;// vorerst nicht implementiert
private:
    time_t time;
};

#endif // DATE_H
