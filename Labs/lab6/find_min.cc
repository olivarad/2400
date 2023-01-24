#include <iostream>
#include <cstdlib>
using namespace std;

void get_num (int& num);

void find_min (int& cur_min, int cur_num);

int main()
{
	int number,  //number read from the keyboard
		minimum; // minimum number out of all the numbers

	get_num(number);

	minimum = number;

	while (number >= 0 ){  
		cout << " Number is  " << number << endl;
		find_min(minimum, number);
		get_num(number);
	}

	cout << "\n Minimum number =  " << minimum << endl;

	return (EXIT_SUCCESS);
}

void get_num(int&  num)
{
	cout << "Enter a number and enter -1 to quit  ";
	cin >> num;
}

void find_min(int& cur_min, int cur_num)
{  
	if(cur_min > cur_num){
		cur_min = cur_num;
	}
}
