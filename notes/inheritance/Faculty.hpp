#include "Human.hpp"

#ifndef FACULTY_H
#define FACULTY_H

class Faculty : public Human {
    private:
        string department;
    public:
        Faculty(string, string, string);
        string getDepartment() const;
        virtual void print();
        friend ostream& operator<<(ostream&, const Faculty&);
};

#endif