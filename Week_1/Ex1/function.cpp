#include "function.h"

void Fraction::Reduce() {
    while (GCD(nu,de) != 1) {
        int t = GCD(nu, de);
        nu /= t;
        de /= t;
    }
}

void Fraction::Input() {
    cout << "Numerator: "; 
    cin >> nu;
    cout << "Denominator: ";
    cin >> de;
}

void Fraction::Output() {
    cout << nu << '/' << de << endl;    
}

Fraction Fraction::Sum(Fraction p) {
    int t = LCM(de, p.de);
    nu *= t / de;
    p.nu *= t / p.de;
    Fraction res;
    res.nu = nu + p.nu;
    res.de = t;
    res.Reduce();
    return res;
}

int Fraction::GCD(int a,int b) {
    if (b == 0) return a;
    return GCD(b,a%b);
}

int Fraction::LCM(int a,int b) {
    return a/GCD(a,b) * b;
}
