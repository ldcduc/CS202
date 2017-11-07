#include <iostream>

using namespace std;

class MyArray{
public:
    MyArray() {
        n = 0;
    }
    MyArray(int sizee) {
        n = sizee;
        pArr = new int [sizee];
        for (int i=1;i<=sizee;++i)
            pArr[i-1] = i;
    }
    MyArray(const MyArray& src):n(src.n) {
        pArr = new int [n];
        for (int i=0;i<n;++i)
            *(pArr+i) = *(src.pArr+i);
    }

    // copy assignment operator
    MyArray operator=(const MyArray& src) {
        n = src.n;
        delete[] pArr;
        pArr = new int [n];
        for (int i=0;i<n;++i)
            *(pArr+i) = *(src.pArr+i);
        return *this;
    }
    void Display() {
        cout << "Size = " << n << endl;
        for (int i=0;i<n;++i)
            cout << pArr[i] << ' ';
        cout << endl;
    }
    void AssignmentOp(const MyArray& src) {
        n = src.n;
        delete[] pArr;
        pArr = new int [n];
        for (int i=0;i<n;++i)
            *(pArr+i) = *(src.pArr+i);
    }
    ~MyArray() {
        n = 0;
        delete [] pArr;
    }
private:
    int n; // size of array
    int* pArr; // allocated arry with n elements
};

class Fraction{
public:
    Fraction() {nu = 0; de = 1;}
    Fraction(int t) {nu = t; de = 1;}
    Fraction(int a,int b) {
        if (b == 0) throw;
        nu = a; de = b;
    }
    
    // free copy constructor
    // => member-wise copy (bitwise copy)
    // => shallow copy
    // sName = src.sName;
    
    // copy constructor
    /*
    Fraction(const Fraction& src) {
        cout << "My copy constructor is running\n";
        nu = src.nu; 
        de = src.de;
    }
    */
    void Display() {cout << nu << '/' << de << ' ';}
private:
    int nu, de;
    char* sName;
};
// If there are allocated memories, you need to write the copy constructor yourself

void doSomething(Fraction a) {
    // do something here
}

int main() {
    /*
    Fraction a, b(7), c(2,3);
    Fraction x(c);  // copy constructor
    Fraction d = c; // copy constructor
    Fraction y;
    y = c; // copy assignment operator
    y.Display();
    doSomething(x); // copy constructor
    */
    MyArray A(10), B(5), C(5);
    A.Display();
    (C = B) = A;
    B.Display();
    C.Display();
    C = B = A;
    B.Display();
    C.Display();
    return 0;
}
