#include "function.h"

int Fraction:: gcd(int x, int y) {
    if (y == 0) return x;
    return gcd(y, x%y);
}

void Fraction:: simplify() {
    int t = gcd(nu, de);
    nu /= t;
    de /= t;
}

int Fraction:: get_nu() {
    return nu;
}

int Fraction:: get_de() {
    return de;
}

Fraction& Fraction:: operator= (const Fraction& src) {
    this->nu = src.nu;
    this->de = src.de;
    return *this;
}

Fraction& Fraction:: operator+= (const Fraction& src) {
    this->nu = this->nu*src.de + this->de*src.nu;
    this->de *= src.de;
    simplify();
    return *this;
}

Fraction& Fraction:: operator-= (const Fraction& src) {
    this->nu = this->nu*src.de - this->de*src.nu;
    this->de *= src.de;
    simplify();
    return *this;
}

Fraction& Fraction:: operator*= (const Fraction& src) {
    this->nu *= src.nu;
    this->de *= src.de;
    simplify();
    return *this;
}

Fraction& Fraction:: operator/= (const Fraction& src) {
    if (Fraction(0) == src)
        return *this; 
    nu *= src.de;
    de *= src.nu;
    simplify();
    return *this;
}

bool Fraction:: operator== (const Fraction& src) {
    return this->nu*src.de == this->de*src.nu;
}

bool Fraction:: operator!= (const Fraction& src) {
    return this->nu*src.de != this->de*src.nu;
}

bool Fraction:: operator>= (const Fraction& src) {
    return this->nu*src.de >= this->de*src.nu;
}

bool Fraction:: operator> (const Fraction& src) {
    return this->nu*src.de > this->de*src.nu;
}

bool Fraction:: operator<= (const Fraction& src) {
    return this->nu*src.de <= this->de*src.nu;
}

bool Fraction:: operator< (const Fraction& src) {
    return this->nu*src.de < this->de*src.nu;
}

Fraction& Fraction:: operator++() {
    *this += 1;
    return *this;
}

Fraction Fraction:: operator++(int) {
    Fraction temp = *this;
    *this += 1;
    return temp;
}

Fraction& Fraction:: operator--() {
    *this -= 1;
    return *this;
}

Fraction Fraction:: operator--(int) {
    Fraction temp = *this;
    *this -= 1;
    return temp;
}

/* operator Fraction:: float() { */
/*     return (float) nu / den; */
/* } */

istream& operator>> (istream& is, Fraction &f) {
    is >> f.nu >> f.de;
    return is;
}

ostream& operator<< (ostream& os, const Fraction& f) {
    os << f.nu << '/' << f.de;
    return os;
}

Fraction operator+ (const Fraction& a, const Fraction& b) {
    Fraction c;
    c = a;
    c += b;
    return c;
}

Fraction operator- (const Fraction& a, const Fraction& b) {
    Fraction c;
    c = a;
    c -= b;
    return c;
}

Fraction operator* (const Fraction& a, const Fraction& b) {
    Fraction c;
    c = a;
    c *= b;
    return c;
}

Fraction operator/ (const Fraction& a, const Fraction& b) {
    Fraction c;
    c = a;
    c /= b;
    return c;
}

