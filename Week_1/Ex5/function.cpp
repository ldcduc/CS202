#include "function.h"

void student::Input(istream &fi) {
    char c;
    if (&fi == &cin)
        cout << "Enter\n";
    if (&fi == &cin)
        cout << "Id: ";
    fi >> id;
    if (&fi == &cin)
        cout << "Full name: ";
    cin >> c;
    getline(fi,name);
    if (&fi == &cin)
        cout << "Gender: ";
    fi >> gender;
    if (&fi == &cin) 
        cout << "Class: ";
    fi >> _class;
    if (&fi == &cin)
        cout << "Address: ";
    cin >> c;
    getline(fi,address);
    if (&fi == &cin)
        cout << "Mark: ";
    fi >> mark;
    if (mark < 2.0) gpa = "F";
    else if (mark < 4.0) gpa = "E";
    else if (mark < 5.0) gpa = "D";
    else if (mark < 6.0) gpa = "C";
    else if (mark < 8.0) gpa = "B";
    else gpa = "A";
}

void student::Output(ostream &fo) {
    fo << "<student>\n";
    fo << "<id>" << id << "</id>\n";
    fo << "<name>" << name << "</name>\n";
    fo << "<_class>" << _class << "</_class>\n";
    fo << "<address>" << address << "</address>\n";
    fo << "<mark>" << mark << "</mark>\n";
    fo << "<gpa>" << gpa << "</gpa>\n";
    fo << "</student>\n";
}
