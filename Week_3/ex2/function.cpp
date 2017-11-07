#include "function.h"

void Point_list::load_istream(istream &is) {
    if (&is == &cin) 
        cout << "Enter n ";
    is >> lsize;
    for (int x,y,i=0;i<lsize;++i) {
        if (&is == &cin) 
            cout << "Enter a point ";
        is >> x >> y;
        push_back(Point(x,y));
    }
}

void Point_list::push_back(Point p) {
    l.push_back(p);
}

Point Point_list::longest_distance(Point p) {
    int distance = -1;
    Point res;
    for (vector<Point>::iterator i=l.begin();i!=l.end();++i) {
        int t = p.distance(*i);
        if (t > distance) {
            distance = t;
            res = *i;
        }
    }
    return res;
}

