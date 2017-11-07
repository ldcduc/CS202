#include "function.h"


int main() {
    cout << "Enter text file name\n";
    string s;
    cin >> s;
    ifstream fi;
    fi.open(s);
    Fraction a,b,c;
    a.Input(fi);
    b.Input(fi);
    a.Output(cout,2);
    switch (a.Compare(b)) {
        case 0:
            cout << "= ";
            break;
        case 1:
            cout << "> ";
            break;
        case -1:
            cout << "< ";
            break;
    }
    b.Output(cout,1);
    fi.close();
    return 0;
}
