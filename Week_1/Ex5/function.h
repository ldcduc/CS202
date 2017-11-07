#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

class student{
private:
    string id, name, gender, address, gpa, _class;
public:
    double mark;
    void Input(istream &fi);
    void Output(ostream &fo);
};
