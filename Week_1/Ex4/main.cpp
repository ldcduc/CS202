#include "function.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    string nfi, nfo;
    cout << "Input filename\n";
    cin >> nfi;
    cout << "Output filename\n";
    cin >> nfo;
    ifstream fi(nfi);
    ofstream fo(nfo);
    Triangle T;
    T.Input(fi);
    T.Output(fo);
    fi.close();
    fo.close();
    return 0;
}
