#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
int main()
{

    const int minValue = 1;
    const short maxValue = 6;

    cout << "roll a dice: ";
    srand(time(0));
    short first = (rand() % (maxValue - minValue + 1)) + minValue;
    short second = (rand() % (maxValue - minValue + 1)) + minValue;
    cout << first << ", " << second;
    return 0;
}