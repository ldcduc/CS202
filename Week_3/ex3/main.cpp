#include "function.h"

using namespace std;

int main() {
    int invalid, right_iso, right, acute, obtuse;
    vector<Triangle> a;
    invalid = right_iso = right = acute = obtuse = 0;
    string s;
    cout << "Enter file name ";
    cin >> s;
    fstream fi(s);
    Triangle t;
    int number;
    fi >> number;
    for (; number; number--) { 
        fi >> t;
        if (t.Get_type() == -9) invalid++;
        else {
            a.push_back(t);
            if (t.Get_type() == 0) right++;
            else if (t.Get_type() == 1) obtuse++;
            else if (t.Get_type() == 4) right_iso++;
            else acute++;
        }
    }
    for (vector<Triangle>::iterator i=a.begin(); i!=a.end(); ++i)
        cout << *i << endl;
    cout << "Removed " << invalid << " invalid triangle\n";
    cout << right_iso << " right isosceles triangle\n";
    cout << right << " right triangle\n";
    cout << acute << " acute triangle\n";
    cout << obtuse << " obtuse triangle\n";
    fi.close();
    return 0;
}
