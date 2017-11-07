#include "function.h"
#include <cmath>

void point::Input() {
    cout << "Enter x ";
    cin >> x;
    cout << "Enter y ";
    cin >> y;
}

void point::Output(int flag) {
    cout << "(" << x << "," << y << ")";
    if (flag == 1) cout << "\n";
    else if (flag == 2) cout << " ";
}

double point::Distance(point b) {
    return sqrt((b.x-x)*(b.x-x) + (b.y-y)*(b.y-y));
}
