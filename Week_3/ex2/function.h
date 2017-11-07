#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Point{
private:
    int x, y;
public:
    Point() {x = y = 0;}
    Point(int a,int b) {x = a; y = b;}
    int distance(Point p) {return (x-p.x)*(x-p.x)+(y-p.y)*(y-p.y);}
    void display() {cout << '(' << x << ',' << y << ')';}
};


class Point_list{
private:
    int lsize = 0;
    vector<Point> l;
public:
    void load_istream(istream &);
    void push_back(Point);
    Point longest_distance(Point);
    bool is_empty() {return !lsize;}
};


