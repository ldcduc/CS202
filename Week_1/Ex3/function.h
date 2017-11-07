#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class point{
private:
    double x, y; 
public:
    void Input();
    void Output(int flag=0);
    double Distance(point);
};
