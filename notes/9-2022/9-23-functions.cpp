#include <iostream>
#include <iomanip>

using namespace std;

double sum(double num, double total)
{
    if(num == -1)
    {
        num = 0;
        double sum = num + total;
        return sum;
    }
    else
    {
    double sum = num + total;
    return sum;
    }
}

int main()
{
    double total = 0;
    double sum_input;

    while (sum_input != -1)
    {
        cout << "Please input a number to add to the total sum (starts at 0), enter -1 to quit." << endl;
        cin >> sum_input;
        total = sum(sum_input, total);
        cout << "Total = " << total << endl;
    }A
    cout << "Thankyou for using me" << endl;
    return (0);
}