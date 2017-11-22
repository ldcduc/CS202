#include "date.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Staff{
protected:
    string id, name, address;
    Date dob;
    int salary;
public:
    Staff() : id(""), name(""), address(""), dob(), salary(0) {};
    Staff(const Staff& a) = default;
    Staff(string, string, Date, string);
    virtual void input(istream&);
    virtual void calc() {}; 
    virtual void print() {};
};

class Staff1: public Staff{
private:
    static int base;
    int pro_num;
public:
    Staff1() : Staff() {};
    Staff1(const Staff1& a);
    void input(istream&);
    void calc();
    void print();
};

class Staff2: public Staff{
private:
    static int base;
    int day_num;
public:
    Staff2() : Staff() {};
    Staff2(const Staff2& a);
    void input(istream&);
    void calc();
    void print();
};
