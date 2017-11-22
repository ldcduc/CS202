#include <iostream>

using namespace std;

class A{
public:
    A() {
        a = 0;
        cout << "A: Default constructor." << endl;
    }
    A(int k) {
        a = k;
        cout << "A: Constructor: " << k << endl;
    }
    void setA(int t) {
        a = t;
    }
    void display() {
        cout << "a = " << a << endl;
    }
private:
    int a;
};

class B: public virtual A{
public:
    B() {
        cout << "B::Default constructor." << endl;
    }
};

class C: public virtual A{
public:
    C(): A(7) {
        cout << "C::Default constructor." << endl;
    }
};

class D: public B, public C{
public:
    D() {
        cout << "D::Default constructor." << endl;
    }
};

int main() {
    D x;
    x.B::display();
    x.C::display();
    return 0;
}
