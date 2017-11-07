#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <ctime>

using namespace std;

class Date{
private:
    int day, month, year;
    bool is_leap(int);
    bool is_leap(const Date&);
    int dom(int);
public:

    Date();
    Date(int);
    Date(int, int);
    Date(int, int, int);
    /* Date(const Date&); */
    bool is_leap();
    /* Date& operator= (const Date&); */
    Date Tomorrow();
    Date Yesterday();
    Date& operator+= (const Date&);
    Date& operator-= (const Date&);
    Date& operator+= (int);
    Date& operator-= (int);
    bool operator== (const Date&);
    bool operator!= (const Date&);
    bool operator<= (const Date&);
    bool operator< (const Date&);
    bool operator>= (const Date&);
    bool operator> (const Date&);
    Date& operator++();
    Date operator++(int);
    Date& operator--();
    Date operator--(int);
    operator int();
    operator long();
    Date long_to_date(int);

    friend istream& operator>> (istream&, Date&);
    friend ostream& operator<< (ostream&, const Date&);

};

istream& operator>> (istream&, Date&);
ostream& operator<< (ostream&, const Date&);

Date operator+ (const Date&, const Date&);
Date operator+ (const Date&, int);
Date operator+ (int, const Date&);
Date operator- (const Date&, const Date&);
Date operator- (const Date&, int);
Date operator- (int, const Date&);
