/**
 * @file prog3.cc
 * @author Olivia Radekci (gr982220@ohio.edu)
 * @brief lab3
 * @version 0.1
 * @date 2022-09-14
 * 
 * @copyright Copyright (c) 2022
 * 
 */

// This program is suppose to read in two integer
// numbers num1 and num2, and prints out the two
// numbers and the  product of  num1 and num2.
// There are two compilation errors.
// Find and fix them.

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
  int num1;
  int num2;  
  
  cout <<" Enter two integers   ";
  cin >> num1 >> num2;
  
  cout<<" The product of "<< num1 << " and " << num2 << " is " << num1 * num2 << endl;

  return (EXIT_SUCCESS);
}
