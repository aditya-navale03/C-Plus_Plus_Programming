#include <iostream>
using namespace std;
int main() {

    int a =20;
    int b =10;
    int temp;

    cout <<"the value before swapping:A="<<a<<endl;
    cout <<"the value before swapping:B="<<b<<endl;
    cout <<endl;
    
    temp = a;
    a = b;
    b = temp;

    cout <<"the value after swapping :A"<<a<<endl;
    cout <<"the value after swapping :B"<<b<<endl;
    
  return 0;
}