#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Fraction{
private:
    int nu, de;
public:
    void Input(istream &);
    void Output(ostream &,int flag = 0);
    int Compare(Fraction);
};
