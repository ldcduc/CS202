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
};

istream& operator>> (istream& is, Fraction &F);
ostream& operator<< (ostream& os, const Fraction &F);


Fraction operator+ (const Fraction&, const Fraction&);
Fraction operator- (const Fraction&, const Fraction&);
Fraction operator* (const Fraction&, const Fraction&);
Fraction operator/ (const Fraction&, const Fraction&);


int main()
{
	Fraction f1, f2;					// 0/1
	Fraction f3(1,-7);				// -1/7
	Fraction f4(f3);				// Copy constructor
	Fraction f5=f2;					// Copy constructor
	Fraction f6, f7, f8;					// Default constructor
	f6=f3;							// Operator =

	f7=f1+f5;
	f8=f2-f4;
	f3=f1*f7;
	f5=f6/f2;

	cout<<(f2==f3);
	cout<<(f3!=f1);
	cout<<(f2>=f5);
	cout<<(f2>f5);
	cout<<(f5<=f3);
	cout<<(f5<f3);


	f1=f2+3;
	f3=-7+f1;
	f5=7*f3;
	f6=f4-6;
	
	cout<<f3;
	cout<<f6;

	f1+=f5;
	f6-=f7;
	f8*=f1;
	f8/=f2;
        
        f8++;
        cout << f8;
        /* cout << f8 + f7; */
        /* cout.operator<< (f8++); */
	/* operator << (cout, (f8++)); */

        cout << f8++;
	/* cout<< ++f7; */
	
	/* cout<<f8--; */
	/* cout<<--f7; */
	
	/* float f=(float)f3;				// 3/2 => 1.5 */
        return 0;
}

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

