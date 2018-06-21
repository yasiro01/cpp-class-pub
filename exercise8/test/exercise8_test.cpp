/* 
 * This is an actual test file
 */
#include "catch.hpp"
#include "../src/Book.cpp"
#include "../src/Room.cpp"
#include "../src/Employee.cpp"
#include "../src/Customer.cpp"
#include "../src/Game.cpp"
#include "../src/Song.cpp"
#include "../src/Company.cpp"
#include "../src/College.cpp"
#include "../src/Laptop.cpp"
#include "../src/Student.cpp"
#include "../src/Roster.cpp"
#include "../src/exercise8.cpp"


TEST_CASE( "Book", "task1" ) {
    stringstream ss;
    Book b11 = Book("Introduction to C++", "John Doe", 89.99);
    ss << b11;
    CHECK ( ss.str() == "Introduction to C++ by John Doe costs $89.99" );
    ss.str(string());
    Book *b12 = new Book("OOP with C++", "Jane Doe", 59.99);
    ss << *b12;
    CHECK ( ss.str() == "OOP with C++ by Jane Doe costs $59.99" );
    delete b12;
}

TEST_CASE( "Room", "task2" ) {
    stringstream ss;
    Room r21 = Room("Olin", 202);
    ss << r21;
    CHECK ( ss.str() == "Olin 202" );
    ss.str(string());
    Room *r22 = new Room("Main", 123);
    ss << *r22;
    CHECK ( ss.str() == "Main 123" );
    delete r22;
}

TEST_CASE( "Employee", "task3" ) {
    stringstream ss;
    Employee e31 = Employee("Alice", "Anderson", 50000, true);
    ss << e31;
    CHECK ( ss.str() == "Alice Anderson earns $50000.00 and works full-time" );
    ss.str(string());
    Employee *e32 = new Employee("Bob", "Black", 30000, false);
    ss << *e32;
    CHECK ( ss.str() == "Bob Black earns $30000.00 and works part-time" );
    delete e32;
}

TEST_CASE( "Customer", "task4" ) {
    stringstream ss;
    Customer c41 = Customer(50000, 36);
    ss << c41;
    CHECK ( ss.str() == "Loan: $50000.00; Term: 36 months" );
    CHECK ( c41.getLoan() == 50000.00 );
    CHECK ( c41.getTerm() == 36 );
    ss.str(string());
    Customer *c42 = new Customer(20000, 12);
    ss << *c42;
    CHECK ( ss.str() == "Loan: $20000.00; Term: 12 months" );
    CHECK ( c42->getLoan() == 20000.00 );
    CHECK ( c42->getTerm() == 12 );
    delete c42;
}

TEST_CASE( "Game", "task5" ) {
    stringstream ss;
    Game g51 = Game("FIFA 2017", 8);
    ss << g51;
    CHECK ( ss.str() == "The rating of FIFA 2017 is 8" );
    CHECK ( g51.getTitle() == "FIFA 2017" );
    CHECK ( g51.getRating() == 8 );
    ss.str(string());
    Game *g52 = new Game("Thief", 10);
    ss << *g52;
    CHECK ( ss.str() == "The rating of Thief is 10" );
    CHECK ( g52->getTitle() == "Thief" );
    CHECK ( g52->getRating() == 10 );
    delete g52;
}

TEST_CASE( "Song", "task6" ) {
    stringstream ss;
    vector<Song> chart;
    ifstream fileIn;
    string filename = "../data/exercise8_top3.txt";
    fileIn.open(filename.c_str());
    if (fileIn.fail()) {
        cerr << "ERROR: Could not open " << filename << endl;
        exit(1);
    }
    while (!fileIn.eof()) {
        string artist, title;
        getline(fileIn, artist, '|');
        getline(fileIn, title, '\n');
        chart.push_back(Song(title, artist));
    }
    fileIn.close();
    for (uint i = 0; i < chart.size(); i++) {
        ss << chart.at(i) << endl;
    }
    CHECK (ss.str() == "Perfect by Ed Sheeran\n\
Finesse by Bruno Mars & Cardi B\n\
Pray For Me by The Weeknd & Kendrick Lamar\n");
    CHECK ( chart.at(0).getTitle() + " by " + chart.at(0).getArtist() == "Perfect by Ed Sheeran" );
    CHECK ( chart.at(1).getTitle() + " by " + chart.at(1).getArtist() == "Finesse by Bruno Mars & Cardi B" );
    CHECK ( chart.at(2).getTitle() + " by " + chart.at(2).getArtist() == "Pray For Me by The Weeknd & Kendrick Lamar" );
}

TEST_CASE( "Company", "task7" ) {
    stringstream ss;
    Company c71 = Company("Apple", 141.03);
    ss << c71;
    CHECK ( ss.str() == "Apple's stock price is $141.03" );
    CHECK ( c71.getStockPrice() == 141.03 );
    c71.setStockPrice(c71.getStockPrice() + 0.15);
    ss.str(string());
    ss << c71;
    CHECK ( ss.str() == "Apple's stock price is $141.18" );
    ss.str(string());
    Company *c72 = new Company("Google", 840);
    ss << *c72;
    CHECK ( ss.str() == "Google's stock price is $840.00" );
    CHECK ( c72->getStockPrice() == 840.00 );
    ss.str(string());
    c72->setStockPrice(c72->getStockPrice() + 10.48);
    ss << *c72;
    CHECK ( ss.str() == "Google's stock price is $850.48" );
    delete c72;
}

TEST_CASE( "College", "task8" ) {
    stringstream ss;
    College c81 = College("Luther College", 2);
    ss << c81;
    CHECK ( ss.str() == "Luther College is ranked #2" );
    ss.str(string());
    changeCollegeRank(c81, 1);
    ss << c81;
    CHECK ( ss.str() == "Luther College is ranked #1" );
    ss.str(string());
    College *c82 = new College("Iowa State", 50);
    ss << *c82;
    CHECK ( ss.str() == "Iowa State is ranked #50" );
    ss.str(string());
    changeCollegeRank(*c82, 10);
    ss << *c82;
    CHECK ( ss.str() == "Iowa State is ranked #10" );
    delete c82;
}

TEST_CASE( "Laptop", "task9" ) {
    stringstream ss;
    Laptop c91 = Laptop("IBM", 800, "Black");
    ss << c91;
    CHECK ( ss.str() == "Black laptop by IBM costs $800.00" );
    CHECK ( c91.getManufacturer() == "IBM" );
    CHECK ( c91.getPrice() == 800 );
    CHECK ( c91.getColor() == "Black" );
    ss.str(string());
    c91.setManufacturer("Lenovo");
    c91.setPrice(600);
    c91.setColor("Gray");
    ss << c91;
    CHECK ( ss.str() == "Gray laptop by Lenovo costs $600.00" );
    ss.str(string());
    Laptop *c92 = new Laptop("Dell", 1200, "Red");
    ss << *c92;
    CHECK ( ss.str() == "Red laptop by Dell costs $1200.00" );
    delete c92;
}

TEST_CASE( "Roster", "task10" ) {
    stringstream ss;
    string filename = "../data/exercise8_roster.txt";
    Roster *r10 = new Roster(filename.c_str());
    ss << r10->getStudentList().at(0);
    CHECK ( ss.str() == "Alice (3.00) majors in Anthropology" );
    ss.str(string());
    ss << *r10;
    CHECK ( ss.str() == "Alice (3.00) majors in Anthropology\n\
Bob (3.20) majors in Biology\n\
Chuck (3.50) majors in Computers\n\
Dave (2.50) majors in Dance\n\
Eve (2.50) majors in Environment\n\
Fred (3.20) majors in French\n\
George (2.00) majors in German\n\
Hillary (2.80) majors in History\n\
Arnold (3.30) majors in Accounting\n\
Celia (3.50) majors in Chemistry\n\
Meredith (3.10) majors in Math\n\
Ethel (3.80) majors in English\n");
    delete r10;
}
