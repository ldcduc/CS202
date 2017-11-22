#include "function.h"

int Staff:: base_salary = 10;
int Staff:: paper_support = 40;
int Staff:: project_salary = 100;

void Staff:: set_static(int salary, int paper, int project) {
    base_salary = salary;
    paper_support = paper;
    project_salary = project;
}

double Staff:: get_salary() {
    return salary;
}

istream& operator>> (istream& is, TA& src) {
    cout << "Name: ";
    is >> src.name;
    cout << "Number of work hours: ";
    is >> src.work_hour;
    return is;
}

istream& operator>> (istream& is, Lecturer& src) {
    cout << "Name: ";
    is >> src.name;
    cout << "Number of lecturing hours: ";
    is >> src.lecturing_hour;
    cout << "Number of papers: ";
    is >> src.paper_num;
    return is;
}

istream& operator>> (istream& is, Researcher& src) {
    cout << "Name: ";
    is >> src.name;
    cout << "Number of research projects: ";
    is >> src.research_project;
    cout << "Number of papers: ";
    is >> src.paper_num;
    return is;
}

void TA:: print() {
    cout << name << " - Teaching Assistant\n";
    cout << "Salary: " << salary << '$' << endl;
}

void TA:: calc_salary() {
    salary = 0.8 * work_hour * base_salary;
}

void TA:: input(istream& is) {
    is >> *this;
    calc_salary();
}

void Lecturer:: print() {
    cout << name << " - Lecturer\n";
    cout << "Salary: " << salary << '$' << endl;
}

void Lecturer:: calc_salary() {
    salary = 1.2 * lecturing_hour * base_salary + paper_support * paper_num;
}

void Lecturer:: input(istream& is) {
    is >> *this;
    calc_salary();
}

void Researcher:: print() {
    cout << name << " - Researcher\n";
    cout << "Salary: " << salary << '$' << endl;
}

void Researcher:: calc_salary() {
    salary = 1.0 * research_project * project_salary * 1.1 * paper_support * paper_num;
}

void Researcher:: input(istream& is) {
    is >> *this;
    calc_salary();
}

