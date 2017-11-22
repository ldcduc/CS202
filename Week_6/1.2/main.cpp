#include "function.h"

using namespace std;

int main() {
    int n;
    cout << "Enter number of lecturer: ";
    cin >> n;
    System abc(n);
    abc.input(cin);
    abc.output(cout); 
    return 0;
}
