#include "function.h"


int fraction::gcd(int x,int y) {
    return (y == 0) ? x : gcd(y,x%y);
}

void fraction::reduce() {
    int t = gcd(num,den);
    num /= t; den /= t;
}

void fraction::sum(fraction a) {
    int new_num = num * a.den + a.num * den, new_den = den * a.den;
    num = new_num; den = new_den; 
    this->reduce();
}

void fraction::display() {
    cout << num << '/' << den << ' ';
}

bool operator<(fraction a,fraction b){
    return a.get_num()*b.get_den() < a.get_den() * b.get_num();
}
