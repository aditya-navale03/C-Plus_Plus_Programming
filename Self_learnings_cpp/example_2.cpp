#include <iostream>

using namespace std;

int main() {

    double sales  = 9500;

    cout << "total sales $ : " << sales <<endl;
    const double StateTaxRate = .04;

    cout << "state tax:" << sales * StateTaxRate <<endl;

    const double CountryTaxRate = .02;
    cout << "country tax: "<< sales * CountryTaxRate <<endl;

    double TotalTax = StateTaxRate + CountryTaxRate;
    cout << "Total Tax: $" <<TotalTax;

}