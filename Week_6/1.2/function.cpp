#include "function.h"

Lecturer:: Lecturer(const Lecturer& src) : ID(src.ID), name(src.name), phone(src.phone), address(src.address), salary(src.salary) {}

void Lecturer:: input(istream& is) {
    cout << "Enter ID: ";
    is >> ID;
    cout << "Enter full name: ";
    is.ignore();
    getline(is, name);
    cout << "Enter phone number: ";
    is >> phone;
    cout << "Enter address: ";
    is.ignore();
    getline(is, address);
}

void Lecturer:: print(ostream& os) {
    os << "Fullname: " << name << endl;
    os << "Phone number: " << phone << endl;
    os << "Address: " << address << endl;
    os << "Salary: " << salary << endl;
}

double TA:: payment = 0;


void TA:: input(istream& is) {
    Lecturer:: input(is);
}

void TA:: print(ostream& os) {
    os << "ID: " << ID << " - Teaching assistant" << endl;
    Lecturer:: print(os);
}

void TA:: calc() {
    salary = payment;
}


void CB:: input(istream& is) {
    Lecturer:: input(is);
    cout << "Rate: ";
    is >> rate;
    cout << "Number of classes: ";
    is >> classes;
}

void CB:: print(ostream& os) {
    os << "ID: " << ID << " - Contract-based lecturer" << endl;
    Lecturer:: print(os);
}

void CB:: calc() {
    salary = rate * classes;
}

double Fulltime:: payment = 0;

void Fulltime:: input(istream& is) {
    Lecturer:: input(is);
    cout << "Rate: ";
    is >> rate;
    cout << "Number of classes: ";
    is >> classes;
}

void Fulltime:: print(ostream& os) {
    os << "ID: " << ID << " - Full-time lecturer" << endl; 
    Lecturer:: print(os);
}

void Fulltime:: calc() {
    salary = payment + rate * classes;
}

void System:: input(istream& is) {
    double payment;
    cout << "Enter TA payment per month: ";
    is >> payment;
    TA:: set_payment(payment);
    cout << "Enter Full-time payment per month: ";
    is >> payment;
    Fulltime:: set_payment(payment);
    for (int i=0; i<size; ++i) {
        cout << "Which type (TA - 0, Contract-based - 1, Full-time - 2): ";
        int type;
        is >> type;
        if (!type) 
            list[i] = new TA;
        else if (type == 1)
            list[i] = new CB;
        else 
            list[i] = new Fulltime;
        list[i]->input(cin);
        list[i]->calc();
    }
}

void System:: output(ostream& os) {
    double total = 0;
    for (int i=0; i<size; ++i) {
        list[i]->print(os);
        os << endl;
        total += list[i]->get_salary();
    }
    cout << "Total money to pay: " << total << endl;
}
