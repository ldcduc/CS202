#include <iostream>
#include <cmath>

using namespace std;

void function(int a, int b = 0, int c) {
    cout << a << ' ' << c;
}

int main() {
    function(1, , 2);
    return 0;
}
