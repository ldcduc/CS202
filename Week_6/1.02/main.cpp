#include "function.h"

using namespace std;

int main() {
    Audience **list;
    int n;
    cout << "Enter number of audience: ";
    cin >> n;
    list = new Audience* [n];
    for (int i=0; i<n; ++i) {
        cout << "Which type (ordinary - 0, VIP - 1): ";
        int type;
        cin >> type;
        if (!type)
            list[i] = new Normal;
        else 
            list[i] = new VIP;
        list[i]->input(cin);
        list[i]->calc();
    }
    for (int i=0; i<n; ++i) {
        list[i]->print(cout);
    }
    return 0;
}
