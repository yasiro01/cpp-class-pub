#include "exercise9.hpp"
#include "HourlyEmployee.hpp"
#include "SalariedEmployee.hpp"

#ifndef COMPANY_H
#define COMPANY_H

class Company {
    private:
        string name;
        int size;
        vector<SalariedEmployee> se_vec;
        vector<HourlyEmployee> he_vec;
        void readCompanyFromFile(string filename);
    public:
        Company(string name, string filename);
        inline string getName() const { return name; };
        inline int getSize() const {return size; };
        friend ostream& operator<<(ostream&, const Company& c);
};

#endif
