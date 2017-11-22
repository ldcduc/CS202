#include <iostream>

using namespace std;

template<class TYPE>
class MyArr{
public:
    MyArr() {
        size = 0;
        pArr = NULL;
    }
    MyArr(unsigned n) {
        size = n;
        pArr = new TYPE [n];
        for (int i=0; i<n; ++i)
            pArr[i] = i+1;
    }
    ~MyArr() {
        size = 0;
        delete []pArr;
    }
    TYPE& operator[](unsigned i) {
        return pArr[i];
    }
    const TYPE& operator[](unsigned i) const {
        return pArr[i];
    }
    MyArr<TYPE>& operator=(const MyArr<TYPE>& src) {
        if (this != &src)
        {
            if (src.size != size)
            {
                delete pArr;
                size = src.size;
                pArr = new int [size];
            }
            for (int i=0; i<size; ++i)
                pArr[i] = src.pArr[i];
            return *this;
        }
    }
    void print() {
        cout << size << endl;
        for (int i=0; i<size; ++i)
            cout << pArr[i] << ' ';
    }
private:
    TYPE* pArr;
    unsigned size;
};

int main() {
    MyArr<double> a(5);
    a.print();
    return 0;
}
