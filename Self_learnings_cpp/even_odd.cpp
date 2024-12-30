#include <iostream>
using namespace std;
int main()
{

    int number;
    cout << "enter a number to find even or odd:";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "number is even";
    }

    else
    {
        cout << "number is odd";
    }

    // ternary operator
    (number % 2 == 0) ? cout << "even" : cout << "odd";

    return 0;
}
