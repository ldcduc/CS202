#include <algorithm>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class IntArray{
private:
    int *pArr, psize;
public:
    IntArray();
    IntArray(int);
    IntArray(int*, int);
    IntArray(const IntArray&);

    IntArray& operator= (const IntArray&);
    int& operator[] (const int);
    operator int(); 
    friend istream& operator>> (istream&, IntArray&);
    friend ostream& operator<< (ostream&, const IntArray&);
};

istream& operator>> (istream&, IntArray&);
ostream& operator<< (ostream&, const IntArray&);

