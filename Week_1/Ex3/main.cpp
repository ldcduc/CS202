#include "function.h"


int main() {
    point a, b;
    a.Input();
    b.Input();
    cout << "Distance between ";
    a.Output();
    cout << " and ";
    b.Output();
    cout << " is " << a.Distance(b) << '\n';
    return 0;
}
