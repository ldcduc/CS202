#include "function.h"
#include <string>

void Fraction::Input(istream &fi) {
    if (&fi == &cin) cout << "Enter a fraction\n";
    if (&fi == &cin) cout << "Numerator: "; 
    fi >> nu;
    if (&fi == &cin) cout << "Denominator: ";
    fi >> de;
}

void Fraction::Output(ostream &fo, int flag) {
    fo << nu << '/' << de;    
    if (flag == 1) cout << endl;
    if (flag == 2) cout << ' ';
}

int Fraction::Compare(Fraction b) {
    if (1ll*nu*b.de > 1ll*de*b.nu) return 1;
    else if (1ll*nu*b.de < 1ll*de*b.nu) return -1;
    return 0;
}
