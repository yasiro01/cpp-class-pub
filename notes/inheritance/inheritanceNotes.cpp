#include "inheritanceNotes.hpp"
#include "Human.hpp"
#include "Student.hpp"

int main() {
    cout << "Hello" << endl;
    Human h = Human("Alice", "Aardvark");
    cout << h << endl;

    Student s = Student("Bob", "Beaver", 3);
    cout << s << endl;

    // Student s2 = Student("Charlie", "Cheetah", 3);
    Student s2 = s;
    cout << s2 << endl;
    s2.setFName("Chuck");
    cout << s2 << endl;
    cout << s << endl;

   
    return 0;
}