#include <iostream>

using namespace std;

class A{
private:
    int a;
public:
    /* A() { */
    /*     cout << "A::default constructor" << endl; */
    /* } */
    /* ~A() { */
    /*     cout << "A::default destructor" << endl; */
    /* } */
};

class B {
public:
    /* B() { */
    /*     cout << "B::default constructor" << endl; */
    /* } */
    /* ~B() { */
    /*     cout << "B::default destructor" << endl; */
    /* } */
};

class C: public A{
public:
    /* C() { */
    /*     cout << "C::default constructor" << endl; */
    /* } */
    /* ~C() { */
    /*     cout << "C::default destructor" << endl; */
    /* } */
};

int main() {
    C hoang;
    /* hoang.~C(); */
    return 0;
}
