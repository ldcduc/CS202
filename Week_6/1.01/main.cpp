#include "function.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of staff ";
    cin >> n;
    Staff **list = new Staff *[n];
    for (int i=0; i<n; ++i) {
        int type;
        cout << "Which type ";
        cin >> type;
        if (!type) 
            list[i] = new Staff1;
        else
            list[i] = new Staff2;
        list[i]->input(cin);
        list[i]->calc();
    }
    for (int i=0; i<n; ++i)
        list[i]->print();
    return 0;
}
