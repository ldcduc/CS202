#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Lecturer{
protected:
    int ID;
    string name, phone, address;
    double salary;
public:
    Lecturer() = default;
    Lecturer(const Lecturer&);
    virtual void input(istream&);
    virtual void print(ostream&);
    virtual void calc() = 0;
    double get_salary() {return salary;}
};

class TA : public Lecturer{
protected:
    static double payment;
public:
    TA() : Lecturer() {};
    TA(const TA&);
    static void set_payment(int v) {payment = v;}
    void input(istream&);
    void print(ostream&);
    void calc();
};

class CB : public Lecturer{
protected:
    double rate;
    int classes;
public:
    CB() : Lecturer() {};
    CB(const CB&);
    void input(istream&);
    void print(ostream&);
    void calc();
};

class Fulltime : public Lecturer{
protected:
    static double payment;
    double rate;
    int classes;
public:
    Fulltime() : Lecturer() {};
    Fulltime(const Fulltime&);
    static void set_payment(int v) {payment = v;}
    void input(istream&);
    void print(ostream&);
    void calc();
};

class System{
private:
    Lecturer** list;
    int size;
public:
    System() {size = 0; list = NULL;}
    System(int size) {this->size = size; list = new Lecturer* [size];}
    void input(istream&);
    void output(ostream&);
    Lecturer*& operator[](int index) {
        return list[index];
    }
};
