#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class Staff{
private:
    int type;
protected: 
    string name;
    static int base_salary, paper_support, project_salary;
    double salary = 0;
public:
    virtual void print() = 0;
    virtual void calc_salary() = 0;
    virtual void input(istream&) = 0;
    static void set_static(int salary, int paper, int project);
    double get_salary();
};

class TA: public Staff{
private:
    int work_hour = 0;
public:
    friend istream& operator>> (istream& is, TA& src);
    virtual void print();
    virtual void calc_salary();
    virtual void input(istream&);
};

class Lecturer: public Staff{
private:
    int lecturing_hour = 0, paper_num = 0;
public:
    friend istream& operator>> (istream& is, Lecturer& src);
    virtual void print();
    virtual void calc_salary();
    virtual void input(istream&);
};

class Researcher: public Staff{
private:
    int research_project = 0, paper_num = 0;
public:
    friend istream& operator>> (istream& is, Researcher& src);
    virtual void print();
    virtual void calc_salary();
    virtual void input(istream&);
};
