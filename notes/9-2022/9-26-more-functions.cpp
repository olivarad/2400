#include <iostream>
using namespace std;

bool isletter(char &c);// & pass by reference, passes address instead of variable value
int sum_and_average(int num, int num2, double &avg);

int main()
{
    char user_input;
    cout << "Pleae enter a character: ";
    cin >> user_input;

    if (isletter(user_input))
    {
        cout << "You entered a letter!\n";
    }
    else
    {
        cout << "You did not enter a letter!\n";
    }

    int n, n2;
    int sum;
    double average = 0.0;
    cout << "Please enter two numbers: ";
    cin >> n >> n2;

    sum = sum_and_average(n, n2, average);
    cout << "The sum is: " << sum << endl;
    cout << "The average is: " << average << endl;

    return (0);
}

int sum_and_average(int num, int num2, double &avg)
{
    int s = num + num2;
    avg = (static_cast<double> (num) + static_cast<double> (num2)) / 2;

    return (s);
}

bool isletter(char &c)
{
    return ((c >= 'A'&& c <= 'Z') || (c >= 'a' && c <= 'z'));
}