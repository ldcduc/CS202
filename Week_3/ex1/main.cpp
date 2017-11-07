#include "function.h"

int main() {
    string file_name;
    cout << "Enter file name\n";
    cin >> file_name;
    freopen(file_name.c_str(),"r",stdin);
    int n;
    cout << "Enter number of fraction\n";
    cin >> n;
    vector<fraction> list;
    for (int i=0,x,y;i<n;++i) {
        cout << "Enter a fraction\n";
        cin >> x >> y;
        list.push_back(fraction(x,y)); 
    }
    fraction t(0,1);
    for (vector<fraction>::iterator i=list.begin();i!=list.end();++i)
        t.sum(*i);
    cout << "Sum "; 
    t.display();
    sort(list.begin(),list.end());
    cout << "\nMin ";
    list[0].display(); 
    cout << "\nMax ";
    list[list.size()-1].display();
    cout << "\nList: ";
    for (vector<fraction>::iterator i=list.begin();i!=list.end();++i)
        i->display();
    return 0;
}
