/**
 * @file prog5.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @brief lab 3
 * @version 0.1
 * @date 2022-09-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
   double ctof;  // equivalent Celsius temperature
   double ftoc;  // equivalent Fahrenheit temperature.
 
   int fah = 56;  //declare and initialize at the same time - page 48
   int cel = 20;

   ctof = 9.0/5.0  * cel + 32;
   ftoc = 5.0/9.0 * (fah -32);

   cout << cel << " degrees Celsius in Fahrenheit is " << fixed << setprecision(1) << ctof << endl;
   cout << fah << " degrees Fahrenheit in Celsius is " << fixed << setprecision(1) << ftoc << endl;

   return (EXIT_SUCCESS);
}
