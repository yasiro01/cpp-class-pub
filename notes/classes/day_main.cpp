#include "day.hpp"


int main() {
    int d = 1, m = 5, y = 2018, yy = 2019;
    cout << "Copy constructor demo" << endl;
    cout << "\nImplicit copy constructor is sufficient" << endl;
    Date1 today1 = Date1(d, m, y);
    cout << "Today is " << today1 << endl;
    Date1 tomorrow1 = today1;
    cout << "Tomorrow is " << tomorrow1 << endl;
    tomorrow1.setYear(yy);
    cout << "Tomorrow is " << tomorrow1 << endl;
    cout << "Today is " << today1 << endl;

    cout << "\nImplicit copy constructor is insufficient" << endl;
    Date2 today2 = Date2(d, m, y);
    cout << "Today is " << today2 << endl;
    Date2 tomorrow2 = today2;
    cout << "Tomorrow is " << tomorrow2 << endl;
    tomorrow2.setYear(yy);
    cout << "Tomorrow is " << tomorrow2 << endl;
    cout << "Today is " << today2 << endl;

    return 0;
}
