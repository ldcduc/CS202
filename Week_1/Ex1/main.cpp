#include "function.h"


int main() {
    Fraction a,b,c;
    cout << "Enter a fraction\n";
    a.Input();
    cout << "Enter a fraction\n";
    b.Input();
    cout << "good";
    c = a.Sum(b);
    cout << "Sum = ";
    c.Output();
    return 0;
}
