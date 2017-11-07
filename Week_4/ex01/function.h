#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstring>

using namespace std;

class Fraction{
private:
    int nu, de;
    int gcd(int, int);
public:
    Fraction() : nu(0), de(1) {};
    Fraction(int v) : nu(v), de(1) {};
    Fraction(int num, int den) : nu(num), de(den) {};
    Fraction(const Fraction& src) : nu(src.nu), de(src.de) {};
    int get_nu();
    int get_de();
    void simplify();
    friend istream& operator>> (istream&, Fraction&);
    friend ostream& operator<< (ostream&, const Fraction&);
    Fraction& operator= (const Fraction&);
    Fraction& operator+= (const Fraction&);
    Fraction& operator-= (const Fraction&);
    Fraction& operator*= (const Fraction&);
    Fraction& operator/= (const Fraction&);
    bool      operator== (const Fraction&);
    bool      operator!= (const Fraction&);
    bool      operator>= (const Fraction&);
    bool      operator>  (const Fraction&);
    bool      operator<= (const Fraction&);
    bool      operator<  (const Fraction&);
    Fraction& operator++ ();
    Fraction  operator++ (int);
    Fraction& operator-- ();
    Fraction  operator-- (int);
    operator float();
};

istream& operator>> (istream& is, Fraction &F);
ostream& operator<< (ostream& os, const Fraction &F);


Fraction operator+ (const Fraction&, const Fraction&);
Fraction operator+ (int, const Fraction&);
Fraction operator+ (const Fraction&, int);
Fraction operator- (const Fraction&, const Fraction&);
Fraction operator- (int, const Fraction&);
Fraction operator- (const Fraction&, int);
Fraction operator* (const Fraction&, const Fraction&);
Fraction operator* (int, const Fraction&);
Fraction operator* (const Fraction&, int);
Fraction operator/ (const Fraction&, const Fraction&);
Fraction operator/ (int, const Fraction&);
Fraction operator/ (const Fraction&, int);
