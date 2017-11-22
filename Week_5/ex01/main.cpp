#include "function.h"

using namespace std;


int main() {
    int number_of_staff, base_salary, paper_suport, project_salary;
    cout << "Enter base salary: ";
    cin >> base_salary;
    cout << "Enter paper support: ";
    cin >> paper_suport;
    cout << "Enter project salary: ";
    cin >> project_salary;
    cout << "Number of staff: ";
    Staff:: set_static(base_salary, paper_suport, project_salary);
    cin >> number_of_staff;
    Staff **list = new Staff *[number_of_staff];
    for (int i=0; i<number_of_staff; ++i) {
        cout << "Which type of staff\n0 - TA\n1 - Lecturer\n2 - Researcher\n ";
        int type;
        cin >> type;
        if (type == 0)
            list[i] = new TA;
        else if (type == 1)
            list[i] = new Lecturer;
        else 
            list[i] = new Researcher;
        list[i]->input(cin);
    }
    double sum_salary = 0;
    for (int i=0; i<number_of_staff; ++i) {
        list[i]->print();
        sum_salary += list[i]->get_salary();
    }
    cout << "Total money to pay: " << sum_salary << "$" << endl;
    return 0;
}
