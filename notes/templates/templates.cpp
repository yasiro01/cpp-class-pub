#include "bits/stdc++.h"

using namespace std;

template <typename T>
T greater2(T n1, T n2) {
    if (n1 > n2) return n1;
    return n2;
}

template <class T, class U>
T mystery(T n1, U n2) {
    cout << "n2 is " << n2 << endl;
    return n1;
}


template <class T>
class Bubble {
    private:
        T value;
    public:
        Bubble() {}
        Bubble(T newValue): value(newValue) {}
        T getValue() {return value;}
        void setValue(T newValue) {this->value = newValue;}

        friend ostream& operator<<(ostream& os, const Bubble& b) {
            os << b.value;
            return os;
        }
};

template <class T>
void printVector(ostream& os, vector<T> v) {
    for (int i = 0; i < v.size(); i++) {
        os << v.at(i) << ' ';
    }
    os << endl;
}

template <class T>
int countN(T someValue) {
    return 1;
}

template <class T, class ... Targs>
int countN(T first, Targs ... others) {
    return 1 + countN(others ...);
}

int main() {
    char a = 'a', b = 'b';
    cout << greater2(a, b) << endl;
    double c = 3.4, d = 3.3;
    cout << greater2(c, d) << endl;

    cout << mystery(a, d) << endl;
    cout << setw(60) << left << "Data type" << setw(10) << "Value" << endl;
    Bubble<bool> bBln = Bubble<bool>(true);
    cout << setw(60) << left << typeid(bBln.getValue()).name() << setw(10) << boolalpha << bBln << endl;
    Bubble<short> bShrt = Bubble<short>(253);
    cout << setw(60) << left << typeid(bShrt.getValue()).name() << setw(10) << bShrt << endl;
    Bubble<int> bInt = Bubble<int>(253);
    cout << setw(60) << left << typeid(bInt.getValue()).name() << setw(10) << bInt << endl;
    Bubble<long> bLng = Bubble<long>(253);
    cout << setw(60) << left << typeid(bLng.getValue()).name() << setw(10) << bLng << endl;
    Bubble<float> bFlt = Bubble<float>(2.53);
    cout << setw(60) << left << typeid(bFlt.getValue()).name() << setw(10) << bFlt << endl;
    Bubble<double> bDbl = Bubble<double>(2.53);
    cout << setw(60) << left << typeid(bDbl.getValue()).name() << setw(10) << bDbl << endl;
    Bubble<char> bChr = Bubble<char>('C');
    cout << setw(60) << left << typeid(bChr.getValue()).name() << setw(10) << bChr << endl;
    Bubble<string> bStr = Bubble<string>("CS253");
    cout << setw(60) << left << typeid(bStr.getValue()).name() << setw(10) << bStr << endl;
    cout << "---" << endl;
    cout << "Vectors and templates" << endl;
    cout << "Vector of integers" << endl;
    vector<int> vInt(5);
    printVector(cout, vInt);
    cout << "Vector of doubles" << endl;
    vector<double> vDbl(5);
    printVector(cout, vDbl);
    cout << "Vector of chars" << endl;
    vector<char> vChr(5);
    printVector(cout, vChr);
    cout << "Vector of Bubbles with char values" << endl;
    vector< Bubble<char> > vBblChr(5);
    printVector(cout, vBblChr);
    cout << "Vector of Bubbles with bool values" << endl;
    vector< Bubble<bool> > vBblInt(5);
    printVector(cout, vBblInt);
    cout << "---" << endl;
    cout << "Variadic functions" << endl;
    cout << countN(1) << endl;  // expect 1
    cout << countN(1, 2) << endl;  //expect 2
    cout << countN('a', 'b', 'c') << endl;  //expect 3
    cout << countN(1.1, 2.2, 3.3) << endl;  //expect 3

    return 0;
}
