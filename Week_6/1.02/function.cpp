#include "function.h"

Audience:: Audience(const Audience& src) : ID(src.ID), name(src.name), sex(src.sex), valid_date(src.valid_date), fee(src.fee) {}

void Audience:: input(istream& is) {
    cout << "Enter ID: ";
    is >> ID;
    cout << "Full name: ";
    is.ignore();
    getline(is, name);
    cout << "Valid date: ";
    is >> valid_date;
    cout << "Sex (male/female): ";
    is >> sex;
}

void Audience:: print(ostream& os) {
    os << "Audience ID: " << ID << endl;
    os << "Full name: " << name << " -" << sex << endl;
    os << "Valid date: " << valid_date << endl;
}

Normal:: Normal(const Normal& src) : Audience(src) {
    book = src.book;
}

int Normal:: base = 5000;

void Normal:: input(istream& is) {
    Audience:: input(is);
    cout << "Books borrowed: ";
    is >> book;
}

void Normal:: print(ostream& os) {
    Audience:: print(os);
    os << "Ordinary audience" << endl << "Books borrowed: " << book << endl;
    os << "Fee: " << fee << "$" << endl;
}

void Normal:: calc() {
    fee = book * base;
}

VIP:: VIP(const VIP& src) : Audience(src) {}

int VIP:: base = 50000;

void VIP:: input(istream& is) {
    Audience:: input(is);
}

void VIP:: print(ostream& os) {
    Audience:: print(os);
    os << "Fee: " << fee << "$" << endl;
}

void VIP:: calc() {
    fee = base;
}
