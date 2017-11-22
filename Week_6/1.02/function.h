#include "date.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Audience{
protected:
    int ID, fee = 0;
    string name, sex;
    Date valid_date;
public:
    Audience() = default;
    Audience(const Audience&);
    virtual void input(istream&);
    virtual void print(ostream&);
    virtual void calc() = 0;
};

class Normal: public Audience{
private:
    static int base;
    int book = 0;
public:
    Normal() : Audience() {};
    Normal(const Normal&);
    static void set_base(int v) {base = v;}
    void input(istream&);
    void print(ostream&);
    void calc();
};

class VIP: public Audience{
private:
    static int base;
public:
    VIP() : Audience() {}
    VIP(const VIP&);
    static void set_base(int v) {base = v;}
    void input(istream&);
    void print(ostream&);
    void calc();
};
