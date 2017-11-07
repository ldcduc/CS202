#include <iostream>
#include <cmath>

using namespace std;

class Fraction{
private:
    int nu, de;
    void Reduce();  
public:
    void Input();
    void Output();
    Fraction Sum(Fraction );
    int GCD(int , int);
    int LCM(int , int);
};
