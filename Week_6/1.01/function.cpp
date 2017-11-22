#include "function.h"

int Staff1:: base = 20000;
int Staff2:: base = 300000;

Staff:: Staff(string id, string name, Date dob, string address) {
    this->id = id;
    this->name = name;
    this->dob = dob;
    this->address = address;
}

void Staff:: input(istream& is) {
    cout << "Enter ID: ";
    is >> id;
    cout << "Full name: ";
    is.ignore();
    getline(is, name);
    cout << "Date of birth: ";
    is >> dob;
    cout << "Address: ";
    is >> address;
}


Staff1:: Staff1(const Staff1& a) : Staff(a)
{
    this->pro_num = a.pro_num;
}

void Staff1:: input(istream& is) {
    Staff:: input(is);
    cout << "Number of products: ";
    is >> pro_num;
}

void Staff1:: calc() {
    salary = pro_num * base; 
}

void Staff1:: print() {
    cout << name << " - producing staff" << endl;  
    cout << id << endl << address << endl << pro_num << endl;
    cout << "Salary: " << salary << "$" << endl;
}

Staff2:: Staff2(const Staff2& a) : Staff(a)
{
    this->day_num = a.day_num;
}

void Staff2:: input(istream& is) {
    Staff:: input(is);
    cout << "Number of working days: ";
    is >> day_num;
}

void Staff2:: calc() {
    salary = day_num * base;
}

void Staff2:: print() {
    cout << name << " - daily staff" << endl;  
    cout << id << endl << address << endl << day_num << endl;
    cout << "Salary: " << salary << "$" << endl;
}
