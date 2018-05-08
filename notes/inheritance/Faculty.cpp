#include "Faculty.hpp"

Faculty::Faculty(string fname, string lname, string dept) : 
        Human(fname, lname), 
        department(dept) {}

string Faculty::getDepartment() const { return department; }

void Faculty::print() {
    cout << "Works in " << department << endl;
}

ostream& operator<<(ostream& os, const Faculty& s) {
    os << (const Human&) s << " is a faculty";
    return os;
}