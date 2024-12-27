//farenheit to degree formula
//°C = (°F - 32) × 5/9.

#include <iostream>

using namespace std;

int main() {

    cout << "enter temperature in fahrenheit:";
    double fahrenheit;
    cin >> fahrenheit;

    double celcius = (fahrenheit - 32) / 1.8;
    cout << "temperature in celcius:" << celcius;

}