#include <iostream>
using namespace std;
int main()
{

    // switch operation
    // calculater

    cout << "1.addition(+)" << endl
         << "2.subtraction(-)" << endl
         << "3.multliplication(*)" << endl
         << "4.dividation(/)" << endl;
     char operation;
    cout << "enter what operation to do:";
    cin>>operation;
   

    cout << "enter two numbers:";
    int number1, number2;
    cin >> number1 >> number2;

    switch (operation)
    {
    case '+':
        cout << "addition is:" << number1 + number2;
        break;

    case '-':
        cout << "subtraction is :" << number1 - number2;
        break;

    case '*':
        cout << "multliplication is:" << number1 * number2;
        break;

    case '/':
        cout << "dividation is:" << number1 / number2;
        break;

    default:
        "enter valid input";
    }

    return 0;
}