#include "Student.hpp"

Student::Student(string fname, string lname, int year) : 
        Human(fname, lname), 
        yearInSchool(year) {}

int Student::getYear() const { return yearInSchool; }

ostream& operator<<(ostream& os, const Student& s) {
    os << (const Human&) s << " is a student";
    return os;
}