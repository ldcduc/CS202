#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class Point{
private:
    double x, y;
public:
    friend istream& operator>> (istream& is, Point& a);
    friend ostream& operator<< (ostream& os, Point& a);
    double Distance(Point);
};

istream& operator>> (istream& is, Point& a);
ostream& operator<< (ostream& os, Point& a);

class Triangle{
private:
    Point p[3];
    double d[3];
    int type, iso, equi;
    // -1  acute
    // 0  right
    // 1  obtuse
    // 2  isosceles
    // 3  equilateral
    // 4  isosceles right 
public:
    friend istream& operator>> (istream& is, Triangle& a);
    friend ostream& operator<< (ostream& os, Triangle& a);
    void Input();
    void Output(ostream& fo);
    int Get_type();
};

istream& operator>> (istream& is, Triangle& a);
ostream& operator<< (ostream& os, Triangle& a);


