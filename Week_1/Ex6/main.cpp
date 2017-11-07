#include "function.h"
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    Date a, b;
    a.Current();
    b.Input(cin);
    cout << "Distance between ";
    a.Output(2);
    cout << "and ";
    b.Output(2);
    cout << "is " << a.Distance(b) << " days\n";
    return 0;
}
