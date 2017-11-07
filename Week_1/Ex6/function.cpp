#include "function.h"


void Date::Input(istream &fi) {
    if (&fi == &cin)
        cout << "Day? ";
    fi >> day;
    if (&fi == &cin)
        cout << "Month? ";
    fi >> month;
    if (&fi == &cin)
        cout << "Year? ";
    fi >> year;
}

void Date::Output(int flag) {
    cout << day << "/" << month << "/" << year;
    if (flag == 1) cout << "\n";
    if (flag == 2) cout << ' ';
}

void Date::Current() {
    system("date \"+\%d \%m \%Y\" > tmp.inp");
    ifstream fi("tmp.inp");
    Input(fi);
    fi.close();
    system("rm tmp.inp");
}

int Date::Distance(Date b) {
    int dom[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
    int res = 0;
    Date a = *this;
    if (a.year > b.year) swap(a,b);
    else if (a.year == b.year && a.month > b.month) swap(a,b);
    else if (a.year == b.year && a.month == b.month && a.day > b.day) swap(a,b);

    if (a.year < b.year) {
        res += dom[a.month] + (a.month == 2 && ((year % 100 == 0 && year % 400 == 0) || (year % 100 && year % 4 == 0))) - a.day;
        for (int mo=a.month+1;mo <= 12;++mo)
            res += dom[mo] + (mo == 2 && ((a.year % 100 == 0 && a.year % 400 == 0) || (a.year % 100 && a.year % 4 == 0)));
        for (int mo=1;mo < b.month;++mo) 
            res += dom[mo] + (mo == 2 && ((b.year % 100 == 0 && b.year % 400 == 0) || (b.year % 100 && b.year % 4 == 0)));
        res += b.day;
        for (int ye=a.year+1;ye<b.year;++ye) 
            res += 365 + ((ye % 100 == 0 && ye % 400 == 0) || (ye % 100 && ye % 4 == 0));
    }
    else if (a.month < b.month) {
        res += dom[a.month] + (a.month == 2 && ((year % 100 == 0 && year % 400 == 0) || (year % 100 && year % 4 == 0))) - a.day;
        for (int mo=a.month+1;mo < b.month;++mo)
            res += dom[mo] + (mo == 2 && ((a.year % 100 == 0 && a.year % 400 == 0) || (a.year % 100 && a.year % 4 == 0)));
        res += b.day;
    }
    else {
        res = b.day - a.day; 
    }
    return res;
}
