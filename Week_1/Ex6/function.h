#include <iostream>
#include <fstream>

using namespace std;

class Date{
private:
    int year, month, day;
public:
    void Input(istream &fi);
    void Output(int flag=0);
    void Current();
    int Distance(Date);
};
