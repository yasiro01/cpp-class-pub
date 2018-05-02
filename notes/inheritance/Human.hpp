#include "inheritanceNotes.hpp"

#ifndef HUMAN_H
#define HUMAN_H

class Human {
    private:
        string fName;
        string lName;
    public:
        Human(string, string);
        Human(const Human&);
        string getFName() const;
        void setFName(string);
        string getLName() const;
        // void setLName(string);
        friend ostream& operator<<(ostream&, const Human&);
};

#endif