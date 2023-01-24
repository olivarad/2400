// This program finds the minimum and sum of all the
// numbers entered by the user

#include <iostream>
#include <cstdlib>
using namespace std;

void get_num (int& num);

void find_min (int& cur_min, int cur_num);

void sum_all (int &cur_sum, int cur_num);

int main()
{
  int number;
  int minimum;
  int sum = 0;
  
  cout << " Address of number in the main: " << &number << endl;

  get_num(number);
   
  minimum = number;

  while (number > 0 ) {
    find_min(minimum,number);
    sum = sum_all(sum, number);
    get_num(number);
  }
    
  cout << " Minimum number =  " << minimum << endl;
  cout << " The sum = " << sum << endl;

  return (EXIT_SUCCESS);
}

void get_num(int&  num)
{
  cout << "Enter a number and enter -1 to quit  ";
  cin >> num;
}

void find_min( int& cur_min , int cur_num)
{
  if (cur_min > cur_num) {
    cur_min = cur_num;
  }
}

void sum_all (int &cur_sum, int cur_num)
{
  return (cur_sum + cur_num);
}
   

