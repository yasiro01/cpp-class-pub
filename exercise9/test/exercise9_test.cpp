/* 
 * This is an actual test file
 */
#include "catch.hpp"
#include "../src/Company.cpp"
#include "../src/Employee.cpp"
#include "../src/HourlyEmployee.cpp"
#include "../src/SalariedEmployee.cpp"


TEST_CASE( "Hourly Employees", "[hourly]" ) {
    stringstream ss;
    HourlyEmployee hEmp1 = HourlyEmployee("Angry Aardvark", "Accounting", 11.25, 40);
    HourlyEmployee hEmp2 = hEmp1;
    hEmp2.setDepartment("Acquisitions");
    hEmp2.setRate(22.5);
    hEmp2.setHours(50);

    CHECK ( hEmp1.getName() == "Angry Aardvark" );
    CHECK ( hEmp1.getDepartment() == "Accounting" );
    CHECK ( hEmp1.getRate() == 11.25 );
    CHECK ( hEmp1.getHours() == 40 );
    CHECK ( hEmp1.getWeeklyPayment() == 450.0 );
    ss << hEmp1;
    CHECK ( ss.str() == "Angry Aardvark from Accounting earned $450.00 this week after working 40.00 hours");
    ss.str(string());

    CHECK ( hEmp2.getName() == "Angry Aardvark" );
    CHECK ( hEmp2.getDepartment() == "Acquisitions" );
    CHECK ( hEmp2.getRate() == 22.5 );
    CHECK ( hEmp2.getHours() == 50 );
    CHECK ( hEmp2.getWeeklyPayment() == 1125.0 );
    ss << hEmp2;
    CHECK ( ss.str() == "Angry Aardvark from Acquisitions earned $1125.00 this week after working 50.00 hours");
}

TEST_CASE( "Salaried Employees", "[salaried]" ) {
    stringstream ss;
    SalariedEmployee *sEmp1 = new SalariedEmployee("Brave Beaver", "Bakery", 52000);
    SalariedEmployee *sEmp2 = new SalariedEmployee(*sEmp1);
    sEmp2->setDepartment("Section B");
    sEmp2->setSalary(62000);

    CHECK ( sEmp1->getName() == "Brave Beaver" );
    CHECK ( sEmp1->getDepartment() == "Bakery" );
    CHECK ( sEmp1->getSalary() == 52000.0 );
    CHECK ( sEmp1->getWeeklyPayment() == 1000.0 );
    ss << *sEmp1;
    CHECK ( ss.str() == "Brave Beaver from Bakery earned $1000.00 this week with the annual contract of $52000.00");
    ss.str(string());

    CHECK ( sEmp2->getName() == "Brave Beaver" );
    CHECK ( sEmp2->getDepartment() == "Section B" );
    CHECK ( sEmp2->getSalary() == 62000.0 );
    CHECK ( sEmp2->getWeeklyPayment() == Approx(1192.31) );
    ss << *sEmp2;
    CHECK ( ss.str() == "Brave Beaver from Section B earned $1192.31 this week with the annual contract of $62000.00");
}

TEST_CASE( "Company", "[company]" ) {
    stringstream ss;
    Company company = Company("Aardvark Technologies", "../data/exercise9_in.txt");
    ss << company;
    CHECK (company.getName() == "Aardvark Technologies" );
    string expected = "\
There are 8 employees in Aardvark Technologies\n\
Salaried Employees\n\
Alice from Admissions earned $769.23 this week with the annual contract of $40000.00\n\
Diana from Bakery earned $1057.69 this week with the annual contract of $55000.00\n\
Eve from Counseling earned $961.54 this week with the annual contract of $50000.00\n\
Hillary from Dining earned $576.92 this week with the annual contract of $30000.00\n\
Hourly Employees\n\
Bob from Admissions earned $600.00 this week after working 40.00 hours\n\
Charlie from Bakery earned $820.00 this week after working 40.00 hours\n\
Fred from Counseling earned $2000.00 this week after working 40.00 hours\n\
George from Dining earned $562.50 this week after working 50.00 hours\n\
";
    CHECK ( ss.str() == expected );
    CHECK (company.getSize() == 8 );
    ss.str(string());
}
