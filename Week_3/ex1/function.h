#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class fraction{
private:
    int num, den;
    void reduce();
public:
    int gcd(int,int);
    fraction() {num = 0; den = 1;}
    fraction(int x,int y) {num = x; den = y;}
    void sum(fraction);
    void display();
    int get_den() {return den;}
    int get_num() {return num;}
};

bool operator<(fraction a,fraction b); 

