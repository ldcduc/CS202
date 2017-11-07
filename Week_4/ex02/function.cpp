#include "function.h"

bool Date:: is_leap() {
    return is_leap(year);
}

bool Date:: is_leap(int y) {
    return (y%100 == 0 && y%400 == 0) || (y%4 == 0);
}

bool Date:: is_leap(const Date& src) {
    return is_leap(src.year);
}

Date:: Date() {
    time_t t = time(0);   // get time now
    struct tm * now = localtime( & t );
    this->day = now->tm_mday;
    this->month = now->tm_mon + 1;
    this->year = now->tm_year + 1900;
}

Date:: Date(int year) {
    this->day = this->month = 1;
    this->year = year;
}

Date:: Date(int year, int month) {
    this->day = 1;
    this->month = month;
    this->year = year;
}

Date:: Date(int year, int month, int day) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date:: dom(int m) {
    if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        return 31;
    else if (m == 4 || m == 6 || m == 9 || m == 11) 
        return 30;
    else if (m == 2) 
        return 28;
    else return 0;
}

Date Date:: Tomorrow() {
    int tmp = (long)*this; 
    return long_to_date(tmp+1);
}

Date Date:: Yesterday() {
    int tmp = (long)*this; 
    return long_to_date(tmp-1);
}

Date& Date:: operator+= (const Date& src) {
    int tmp = (long)*this;
    Date tmp_date = src;
    tmp += (long)tmp_date;
    *this = long_to_date(tmp);
    return *this;
}

Date& Date:: operator-= (const Date& src) {
    int tmp = (long)*this;
    Date tmp_date = src;
    tmp -= (long)tmp_date;
    *this = long_to_date(tmp);
    return *this;
}

Date& Date:: operator+= (int v) {
    int tmp = (long)*this;
    tmp += v;
    *this = long_to_date(tmp);
    return *this;
}

Date& Date:: operator-= (int v) {
    int tmp = (long)*this;
    tmp -= v;
    *this = long_to_date(tmp);
    return *this;
}

bool Date:: operator== (const Date& src) {
    return (day == src.day && month == src.month && year == src.year);
}

bool Date:: operator!= (const Date& src) {
    return !(day == src.day && month == src.month && year == src.year);
}

bool Date:: operator<= (const Date& src) {
    if (year == src.year) {
        if (month == src.month) 
            return day <= src.day;
        else return month <= src.month;
    }
    else return year <= src.year;
}

bool Date:: operator< (const Date& src) {
    if (year == src.year) {
        if (month == src.month) 
            return day < src.day;
        else return month < src.month;
    }
    else return year < src.year;
}

bool Date:: operator>= (const Date& src) {
    if (year == src.year) {
        if (month == src.month) 
            return day >= src.day;
        else return month >= src.month;
    }
    else return year >= src.year;
}

bool Date:: operator> (const Date& src) {
    if (year == src.year) {
        if (month == src.month) 
            return day > src.day;
        else return month > src.month;
    }
    else return year > src.year;
}

Date& Date:: operator++ () {
    *this += Date(1);
    return *this;
}

Date Date:: operator++ (int) {
    Date tmp = *this;
    *this += Date(1);
    return *this;
}

Date& Date:: operator-- () {
    *this -= Date(1);
    return *this;
}

Date Date:: operator-- (int) {
    Date tmp = *this;
    *this -= Date(1);
    return *this;

}

Date:: operator int() {
    return long(*this) - long(Date(year, 1, 1));
}

Date:: operator long() {
    int res = 0;
    for (int i=1; i<year; ++i) 
        res += 365 + is_leap(i);
    for (int i=1; i<month; ++i)
        res += dom(i) + (i == 2 && is_leap(year));
    return res += day;
}

Date Date:: long_to_date(int num) {
    Date res;
    res.year = 1;
    while (num > 365+is_leap(res.year))
        num -= 365+is_leap(res.year), res.year++;
    res.month = 1;
    while (num > dom(res.month)+(is_leap(res.year) && res.month == 2))
        num -= dom(res.month)+(is_leap(res.year) && res.month == 2), res.month++;
    res.day = num;
    return res;
}

istream& operator>> (istream& is, Date& src) {
    printf("dd/mm/yy ");
    char c;
    is >>  src.day >> c >> src.month >> c >> src.year;
    return is;
}

ostream& operator<< (ostream& os, const Date& src) {
    os << setfill('0') << setw(2) << src.day << '/' << setw(2) << src.month << '/' << setw(4) << src.year;
    return os;
}

Date operator+ (const Date& a, const Date& b) {
    Date tmp = a;
    tmp += b;
    return tmp;
}

Date operator+ (const Date& a, int v) {
    Date tmp = a;
    tmp += v;
    return tmp;
}
Date operator+ (int v, const Date& a) {
    Date tmp = a;
    tmp += v;
    return tmp;
}
Date operator- (const Date& a, const Date& b) {
    Date tmp = a;
    tmp -= b;
    return tmp;
}
Date operator- (const Date& a, int v) {
    Date tmp = a;
    tmp -= v;
    return tmp;
}
Date operator- (int v, const Date& a) {
    Date tmp = a;
    tmp -= v;
    return tmp;
}
