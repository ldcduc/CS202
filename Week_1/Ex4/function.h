#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class point{
private:
    double x, y; 
public:
    void Input(istream &fi);
    void Output(ostream &fo,int flag=0);
    double Distance(point);
};

class Triangle{
private:
    double a, b, c, A, P;
    int type, iso, equi; // -9 -1 0 1
    point p1, p2, p3;
public:
    void Input(istream &fi);
    void Output(ostream &fo);
};
