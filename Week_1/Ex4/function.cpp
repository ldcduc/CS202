#include "function.h"


void point::Input(istream &fi) {
    if (&fi == &cin) 
        cout << "Enter x ";
    fi >> x;
    if (&fi == &cin) 
        cout << "Enter y ";
    fi >> y;
}

void point::Output(ostream &fo, int flag) {
    fo << "(" << x << "," << y << ")";
    if (flag == 1) fo << "\n";
    else if (flag == 2) fo << " ";
    else if (flag == 3) fo << ',';
}

double point::Distance(point b) {
    return sqrt((b.x-x)*(b.x-x) + (b.y-y)*(b.y-y));
}

void Triangle::Input(istream &fi) {
    p1.Input(fi);
    p2.Input(fi);
    p3.Input(fi);
    a = p1.Distance(p2); b = p2.Distance(p3); c = p3.Distance(p1);
    double eps = 1e-7;
    if (a <= 0 || b <= 0 || c <= 0) {type = -9; return;}
    if (!(a+b>c && b+c>a && c+a>b)) {type = -9; return;}
    if (fabs(a*a-b*b+c*c) < eps || fabs(b*b - c*c + a*a) < eps || fabs(c*c - a*a + b*b) < eps) type = 0;
    else {
        type = -1;
    }
    equi = a == b && b == c && c == a;
    iso = (a == b || b == c || c == a) && !equi;
    P = a+b+c; 
    A = sqrt(P/2 * (P/2 - a) * (P/2 - b) * (P/2 - c));
    
}

void Triangle::Output(ostream &fo) {
    fo << "3 vertices ";
    p1.Output(fo,3); p2.Output(fo,3); p3.Output(fo,3);
    if (type == -9) 
        fo << "These 3 points can't be a triangle";
    else {
        if (equi)
            fo << "Equilateral triangle,";
        else
        if (type == 0) {
            if (iso) fo << "Isosceles right triangle,";
            else fo << "Right triangle,";
        }
        else if (iso) 
            fo << "Isosceles triangle,";
        else if (type == 1) 
            fo << "Obtuse triangle,";
        else fo << "Acute triangle,";
        fo << "Parameter = " << P << ',';
        fo << "Area = " << A;
    }
}
