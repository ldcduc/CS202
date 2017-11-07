#include "function.h"
#include <fstream>
#include <iostream>

using namespace std;

int main() {
    string file_name;
    cout << "Enter text file \n ";
    cin >> file_name;
    ifstream f_in(file_name);
    Point_list plist;
    plist.load_istream(f_in);
    cout << "Enter a point ";
    int x, y; 
    cin >> x >> y;
    if (plist.is_empty()) 
        cout << "Out point array is empty\n";
    else  {
        cout << "Furthest point of ";
        Point(x,y).display();
        cout << " is ";
        plist.longest_distance(Point(x,y)).display();
    }
    f_in.close();
    return 0;
}
