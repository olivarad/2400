// Simple class to illustrate separate compilation and const
// parameters
// 
// Written by Mal Gunasekera
// Modified by David M. Chelberg
// Modified by Olivia Radecki
// last-modified: Wed Nov 30 2022
// 
#include <iostream>
#include <cstdlib>
#include <cmath>
#include "my_int.h"
using namespace std;

int main()
{ 
  my_int value1;
  my_int value2;
     
  value1.input(cin);  
 
  value1.output(cout);

  if (is_prime(value1))
    cout<<"  is a prime number  \n";
  else
   cout<<" is not a prime number \n";

  value2.input(cin);  
 
  value2.output(cout);  

  value1 > value2; //call to the friend function

  return 0;
}

 

