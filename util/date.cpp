#include "date.h"


Date::Date() {}

Date::Date(const std::string& date) {
    std::tm tm = {};
    std::istringstream ss(date);

    ss >> std::get_time(&tm, "%Y-%m-%d");

    if (!ss.fail()) {
        time = std::mktime(&tm);
    } else {
        time = 0;
    }
}


Date::Date(int year, int month, int day) {
    std::tm tm = {};
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
//kobe

    time = std::mktime(&tm);
}

Date::Date(const char* date) : Date(std::string(date)) {}

long Date::operator-(const Date& other) const {
    return difftime(this->time, other.time);
}

long Date::daysBetween(const Date& other) const {
    return (*this - other) / (60 * 60 * 24);
}

long Date::weeksBetween(const Date& other) const {
    return this->daysBetween(other) / 7;
}
Date::operator std::string() const {
    std::tm* localTime = std::localtime(&time);

    std::ostringstream oss;
    oss << (localTime->tm_year + 1900) << "-"   // Jahr
        << std::setw(2) << std::setfill('0') << (localTime->tm_mon + 1) << "-"  // Monat
        << std::setw(2) << std::setfill('0') << localTime->tm_mday;             // Tag

    return oss.str();
}
