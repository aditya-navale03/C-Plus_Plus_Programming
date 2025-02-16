#include <iostream>
using namespace std;
int main() {
  //simple interest
  // rate principle time /100

float principle,rate,time;

cout<<"enter principle";
cin>>principle;

cout<<"enter rate";
cin>>rate;

cout<<"enter time";
cin>>time;

float simple_interest = (principle * rate * time) /100;
cout<<simple_interest;


  return 0;
}