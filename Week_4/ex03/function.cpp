#include "function.h"

IntArray:: IntArray() {
    psize = 0;
}

IntArray:: IntArray(int asize) {
    psize = asize;
    pArr = new int [asize];
    for (int i=0; i<psize; ++i)
        pArr[i] = i+1;
}

IntArray:: IntArray(int* Arr, int asize): psize(asize) {
    pArr = new int [asize];
    for (int i=0; i<asize; ++i)
        pArr[i] = Arr[i];
}

IntArray:: IntArray(const IntArray& src): psize(src.psize) {
    pArr = new int [psize];
    for (int i=0; i<psize; ++i)
        pArr[i] = src.pArr[i];
}

IntArray& IntArray:: operator= (const IntArray& src) {
    psize = src.psize;
    delete [] pArr;
    pArr = new int [psize];
    for (int i=0; i<psize; ++i)
        pArr[i] = src.pArr[i];
    return *this;
}

int& IntArray:: operator[] (const int index) {
    return pArr[index];
}

IntArray:: operator int() {
    int res = 0;
    for (int i=0; i<psize; ++i)
        res += pArr[i];
    return res;
}

istream& operator>> (istream& is, IntArray& src) {
    cout << "Enter " << src.psize << " element";
    if (src.psize > 1) cout << "s\n"; else cout << "\n";
    for (int i=0; i<src.psize; ++i)
        is >> src.pArr[i];
    return is; 
}

ostream& operator<< (ostream& os, const IntArray& src) {
    for (int i=0; i<src.psize; ++i)
        os << src.pArr[i] << ' ';
    return os;
}
