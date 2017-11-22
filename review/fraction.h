#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class Fraction{
private:
    int num, den;
    int gcd(int x, int y);
    void simplify();
public:
    Fraction(): num(0), den(1) {};
    Fraction(int i): num(i), den(1) {};
    Fraction(int nu, int de): num(nu), den(de) {};
    Fraction(const Fraction& rhs): num(rhs.num), den(rhs.den) {};
    Fraction& operator=(const Fraction& rhs) = default;
    Fraction& operator+=(const Fraction& rhs);
    Fraction& operator-=(const Fraction& rhs);
    Fraction& operator*=(const Fraction& rhs);
    Fraction& operator/=(const Fraction& rhs);
    Fraction& operator++();
    Fraction& operator--();
    Fraction  operator++(int);
    Fraction  operator--(int);
    bool operator==(const Fraction& rhs);
    bool operator!=(const Fraction& rhs);
    bool operator>=(const Fraction& rhs);
    bool operator> (const Fraction& rhs);
    bool operator< (const Fraction& rhs);
    bool operator<=(const Fraction& rhs);
    operator float();
    friend istream& operator>>(istream& is, Fraction& fr);
    friend ostream& operator<<(ostream& os, const Fraction& fr);
};

Fraction operator+(const Fraction lhs, const Fraction rhs);
Fraction operator+(const Fraction lhs, int rhs);
Fraction operator+(int lhs, const Fraction rhs);
Fraction operator-(const Fraction lhs, const Fraction rhs);
Fraction operator-(const Fraction lhs, int rhs);
Fraction operator-(int lhs, const Fraction rhs);
Fraction operator*(const Fraction lhs, const Fraction rhs);
Fraction operator*(const Fraction lhs, int rhs);
Fraction operator*(int lhs, const Fraction rhs);
Fraction operator/(const Fraction lhs, const Fraction rhs);
Fraction operator/(const Fraction lhs, int rhs);
Fraction operator/(int lhs, const Fraction);
