#include "Human.hpp"

Human::Human(string fname, string lname): fName(fname), lName(lname) {}

Human::Human(const Human& another) : fName(another.fName), lName(another.lName) {}

string Human::getFName() const { return fName; }

void Human::setFName(string name) { fName = name; } 

string Human::getLName() const { return lName; }

ostream& operator<<(ostream& os, const Human& h) {
    os << h.fName << ' ' << h.lName;
    return os;
}