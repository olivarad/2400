#include <iostream>
using namespace std;

void swap(int &n1, int &n2);//the names of the variables in these two functions can be identitcal because they are different types.
void swap(double &d, double &d2);

int main()
{
    int num1, num2;
    double d1, d2;

    cout << "Enter two integers: ";
    cin >> num1 >> num2;

    cout << "Enter two doubles: ";
    cin >> d1 >> d2;

    cout << "Original num: " << num1 << endl;
    cout << "Original num2: " << num2 << endl;
    cout << "Original d: " << d1 << endl;
    cout << "Original d2: " << d2 << endl;

    swap(num1, num2);
    swap(d1, d2);

    cout << "Swapped num: " << num1 << endl;
    cout << "Swapped num2: " << num2 << endl;
    cout << "Swapped d1: " << d1 << endl;
    cout << "Swapped d2: " << d2 << endl;
}

void swap(int &n1, int &n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}

void swap(double &d, double &d2)
{
    double temp;
    temp = d;
    d = d2;
    d2 = temp;
}