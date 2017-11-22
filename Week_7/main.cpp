#include <iostream>

using namespace std;

class A {
private:
    A() {
        cout << "Private constructor" << endl;
    }
    friend class B;
};

/* class C { */

/* }; */

class B :  virtual public A{
public:
    B() {
        cout << "B constructor" << endl;
    }
};

class D : public B {

};

int main() {

    return 0;
}
