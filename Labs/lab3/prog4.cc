/**
 * @file prog4.cc
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

using namespace std;

int main() 
{
  
  int i;

  while (cin >> i) {
    cout << i << " times 2 = " << (i * 2) << endl;
  }
  return (EXIT_SUCCESS);
}
