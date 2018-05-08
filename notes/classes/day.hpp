#include "bits/stdc++.h"

using namespace std;

#ifndef DAY_H
#define DAY_H

class Date1 {
    private:
        int day;
        int month;
        int year;
    public:
        Date1(int d, int m, int y): day(d), month(m), year(y) {}
        inline void setYear(int year) { this->year = year; }
        friend ostream& operator<<(ostream& os, const Date1& day) {
            os << day.year << '-' << day.month << '-' << day.day;
            return os;
        }
};

class Date2 {
    private:
        int day;
        int month;
        int *year;
    public:
        Date2(int d, int m, int& y): day(d), month(m) { this->year = &y; }
        inline void setYear(int& year) { this->year = &year; }
        friend ostream& operator<<(ostream& os, const Date2& day) {
            os << *(day.year) << '-' << day.month << '-' << day.day;
            return os;
        }
};

#endif