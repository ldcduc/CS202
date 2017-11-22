#pragma once
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

class IntArray{
private:
    int asize, *arr;
public:
    IntArray(): asize(0), arr(NULL) {};
    IntArray(int n): asize(n), arr(new int [n]) {for (int i=1; i<=n; ++i) arr[i-1] = i;};
    IntArray(int *rhs, int n): asize(n), arr(new int [n]) {for (int i=0; i<n; ++i) arr[i] = rhs[i];}
    IntArray(const IntArray& rhs): asize(rhs.asize), arr(new int [rhs.asize]) {for (int i=0; i<rhs.asize; ++i) arr[i] = rhs.arr[i];}
    IntArray& operator=(const IntArray& rhs);
    int& operator[](int i);
    operator int();
    friend istream& operator>>(istream& is, IntArray& a);
    friend ostream& operator<<(ostream& os, const IntArray& a);
};
