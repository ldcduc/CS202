#include "function.h"

using namespace std;

int main() {
    student a, b;
    a.Input(cin);
    b.Input(cin);
    ofstream fo("output.xml");
    if (a.mark < b.mark)
        b.Output(fo);
    else a.Output(fo);
    fo.close();
    return 0;
}
