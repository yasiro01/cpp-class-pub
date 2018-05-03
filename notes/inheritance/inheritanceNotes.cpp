#include "inheritanceNotes.hpp"
#include "Human.hpp"
#include "Student.hpp"
#include "Faculty.hpp"

int main() {
    Human h = Human("Alice", "Aardvark");
    cout << h << endl;

    Student s = Student("Bob", "Beaver", 3);
    cout << s << endl;

    Faculty f = Faculty("Diana", "Dingo", "History");
    cout << f << endl;
   
    return 0;
}