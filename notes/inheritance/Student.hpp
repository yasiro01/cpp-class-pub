#include "Human.hpp"

#ifndef STUDENT_H
#define STUDENT_H

class Student : public Human {
    private:
        int yearInSchool;
    public:
        Student(string, string, int);
        int getYear() const;
        friend ostream& operator<<(ostream&, const Student&);
};

#endif