#include <iostream>
#include <fstream>

using namespace std;

class B{
protected: 
    int b1, b2;
public:
    B() { 
        b1 = b2 = 0; 
    }
    B(int t) { 
        b1 = b2 = t; 
    }
    B(int t, int k) { 
        b1 = t; b2 = k; 
    }
    void call(int k) {
        cout << "B:int" << endl;
    }
};

class D : public B{
private:
    int d3, d4;
public:
    D() { 
        b1 = b2 = -2;
        d3 = d4 = -1; 
    }
    D(int t) : B(t) { 
        d3 = d4 = t; 
    }
    D(int t, int k) : B(t, t*2) { 
        d3 = t; d4 = k; 
    }
    D(const D& src) : B(src){
        d3 = src.d3;
        d4 = src.d4;
    }
    void display() {
        cout << b1 << ' ' << b2 << ' ' << d3 << ' ' << d4 << endl;
    }
    void call(double k) {
        cout << "D:double" << endl;
    }
    using B::call;
};

int main() {
    D ob;
    ob.call(2);
    ob.call(3.5);
    /* ob.B::call(2); */
    return 0;
}
