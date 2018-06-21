#include "exercise9.hpp"
#include "Company.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"


int main() {
    cout << "-------------" << endl;
    cout << "Hourly employee example" << endl;
    HourlyEmployee hEmp1 = HourlyEmployee("Angry Aardvark", "Accounting", 11.25, 40);
    HourlyEmployee hEmp2 = hEmp1;
    hEmp2.setDepartment("Acquisitions");
    hEmp2.setHours(50);
    cout << hEmp1 << endl;
    cout << hEmp2 << endl;
    cout << "-------------" << endl;
    cout << "Salaried employee example" << endl;
    SalariedEmployee *sEmp1 = new SalariedEmployee("Brave Beaver", "Bakery", 52000);
    SalariedEmployee *sEmp2 = new SalariedEmployee(*sEmp1);
    sEmp2->setDepartment("Section B");
    sEmp2->setSalary(62000);
    cout << *sEmp1 << endl;
    cout << *sEmp2 << endl;

    cout << "-------------" << endl;
    cout << "Creating a Company" << endl;
    Company company = Company("Aardvark Technologies", "data/exercise9_in.txt");
    cout << company << endl;
    cout << "-------------" << endl;

    return 0;
}
