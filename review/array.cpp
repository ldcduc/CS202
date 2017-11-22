#include "array.h"

IntArray& IntArray:: operator=(const IntArray& rhs) {
    if(this != &rhs) {
        asize = rhs.asize;
        delete [] arr;
        arr = new int [asize];
        for (int i=0; i<asize; ++i)
            arr[i] = rhs.arr[i];
    }
    return *this;
}

int& IntArray:: operator[](int i) {
    return arr[i];
}

IntArray:: operator int() {
    int res = 0;
    for (int i=0; i<asize; ++i)
        res += arr[i];
    return res;
}

istream& operator>>(istream& is, IntArray& a) {
    cout << "Enter array size: ";
    is >> a.asize;
    a.arr = new int [a.asize];
    cout << "Enter " << a.asize << " number";
    if (a.asize > 1) cout << "s ";
        else cout << " ";
    for (int i=0; i<a.asize; ++i)
        is >> a.arr[i];
    return is;
}

ostream& operator<<(ostream& os, const IntArray& a) {
    os << "Size: " << a.asize << endl;
    for (int i=0; i<a.asize; ++i)
        os << a.arr[i] << ' ';
    os << endl;
    return os;
}
