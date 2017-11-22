#include "fraction.h"

int Fraction:: gcd(int x, int y) {
    return (y == 0) ? x : gcd(y, x%y);
}

void Fraction:: simplify() {
    int t = gcd(num, den);
    num /= t;
    den /= t;
}

Fraction& Fraction:: operator+=(const Fraction& rhs) {
    num = num * rhs.den + den * rhs.num;
    den *= rhs.den;
    simplify();
    return *this;
}

Fraction& Fraction:: operator-=(const Fraction& rhs) {
    num = num * rhs.den - den * rhs.num;
    den *= rhs.den;
    simplify();
    return *this;
}

Fraction& Fraction:: operator*=(const Fraction& rhs) {
    num *= rhs.num;
    den *= rhs.den;
    simplify();
    return *this;
}

Fraction& Fraction:: operator/=(const Fraction& rhs) {
    num *= rhs.den;
    den *= rhs.num;
    simplify();
    return *this;
}

Fraction& Fraction:: operator++() {
    *this += 1;
    return *this;
}

Fraction& Fraction:: operator--() {
    *this -= 1;
    return *this;
}

Fraction Fraction:: operator++(int) {
    Fraction tmp = *this;
    *this += 1;
    return tmp;
}

Fraction Fraction:: operator--(int) {
    Fraction tmp = *this;
    *this -= 1;
    return tmp;
}

bool Fraction:: operator==(const Fraction& rhs) {
    return num * rhs.den == den * rhs.num;
}

bool Fraction:: operator!=(const Fraction& rhs) {
    return num * rhs.den != den * rhs.num;
}

bool Fraction:: operator>=(const Fraction& rhs) {
    return num * rhs.den >= den * rhs.num;
}

bool Fraction:: operator> (const Fraction& rhs) {
    return num * rhs.den > den * rhs.num;
}

bool Fraction:: operator<=(const Fraction& rhs) {
    return num * rhs.den <= den * rhs.num;
}

bool Fraction:: operator< (const Fraction& rhs) {
    return num * rhs.den < den * rhs.num;
}

Fraction:: operator float() {
    return (float) num / (float) den;
}

istream& operator>>(istream& is, Fraction& fr) {
    cout << "Enter numerator and denominator: ";
    is >> fr.num >> fr.den;
    return is;
}

ostream& operator<<(ostream& os, const Fraction& fr) {
    os << fr.num << '/' << fr.den;
    return os;
}

Fraction operator+(const Fraction lhs, const Fraction rhs) {
    Fraction t(lhs);
    t += rhs;
    return t;
}

Fraction operator+(const Fraction lhs, int rhs) {
    Fraction t(lhs), i(rhs);
    t += i;
    return t;
}

Fraction operator+(int lhs, const Fraction rhs) {
    Fraction t(rhs), i(lhs);
    t += i;
    return t;
}

Fraction operator-(const Fraction lhs, const Fraction rhs) {
    Fraction t(lhs);
    t -= rhs;
    return t;
}

Fraction operator-(const Fraction lhs, int rhs) {
    Fraction t(lhs), i(rhs);
    t -= i;
    return t;
}

Fraction operator-(int lhs, const Fraction rhs) {
    Fraction t(rhs), i(lhs);
    t -= i;
    return t;
}

Fraction operator*(const Fraction lhs, const Fraction rhs) {
    Fraction t(lhs);
    t *= rhs;
    return t;
}

Fraction operator*(const Fraction lhs, int rhs) {
    Fraction t(lhs), i(rhs);
    t *= i;
    return t;
}

Fraction operator*(int lhs, const Fraction rhs) {
    Fraction t(rhs), i(lhs);
    t *= i;
    return t;
}

Fraction operator/(const Fraction lhs, const Fraction rhs) {
    Fraction t(lhs);
    t /= rhs;
    return t;
}

Fraction operator/(const Fraction lhs, int rhs) {
    Fraction t(lhs), i(rhs);
    t /= i;
    return t;
}

Fraction operator/(int lhs, const Fraction rhs) {
    Fraction t(rhs), i(lhs);
    t /= i;
    return t;
}
