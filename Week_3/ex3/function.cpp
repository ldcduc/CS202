#include "function.h"


istream& operator>> (istream& is, Point& a) {
    is >> a.x >> a.y;
    return is;
}
ostream& operator<< (ostream& os, Point& a) {
    os << '(' << a.x << ',' << a.y << ')';
    return os;
}

double Point::Distance(Point p) {
    return sqrt((p.x-x)*(p.x-x) + (p.y-y)*(p.y-y));
}




istream& operator>> (istream& is,Triangle& a) {
    is >> a.p[0] >> a.p[1] >> a.p[2];
    return is;
}
ostream& operator<< (ostream& os, Triangle& a) {
    os << a.p[0] << ", " << a.p[1] << ", " << a.p[2];
    return os;
}

void Triangle::Input() {
    d[0] = p[0].Distance(p[1]);
    d[1] = p[1].Distance(p[2]);
    d[2] = p[2].Distance(p[0]);
    double eps = 1e-8;
    if (d[0] <= 0 || d[1] <= 0 || d[2] <= 0) {type = -9; return;}
    if (!(d[0]+d[1]>d[2] && d[1]+d[2]>d[0] && d[2]+d[0]>d[1])) {
        type = -9; 
        return;
    }
    if (fabs(d[0]*d[0]-d[1]*d[1]+d[2]*d[2]) < eps || fabs(d[1]*d[1] - d[2]*d[2] + d[0]*d[0]) < eps || fabs(d[2]*d[2] - d[0]*d[0] + d[1]*d[1]) < eps)
        type = 0;
    else {
        type = -1;
    }
    equi = d[0] == d[1] && d[1] == d[2] && d[2] == d[0];
    iso = (d[0] == d[1] || d[1] == d[2] || d[2] == d[0]) && !equi;
}

void Triangle::Output(ostream &fo) {
    fo << "3 vertices ";
    fo << p[0] << ' ' << p[1] << ' ' << p[2];
    if (type == -9) 
        fo << "These 3 points can't be a triangle";
    else {
        if (equi)
            type = 4;
        else
        if (type == 0) {
            if (iso) type = 4;
        }
        else if (iso) 
            type = 2;
        else if (type == 1) 
            type = 1;
        else type = -1;
    }
}

int Triangle::Get_type() {
    return type; 
}
