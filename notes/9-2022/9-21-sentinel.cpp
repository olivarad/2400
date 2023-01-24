#include <iostream>
#include <string>
using namespace std;

int main()
{
    int sum =0;
    int num;
    string s;

    cout << "Enter a positive number or Q to quit: ";
    cin >> num;

    while(!cin.fail())
    {
        sum += num;
        cout << "The sum equals " << sum << endl;

        cout << "Enter a positive number or Q to quit: ";
        cin >> num;
    }

    cin.clear();
    cin.ignore();

    cout << "Enter a string: ";
    cin >> s;
    if(!cin.fail())
    {
        cout << "You entered: " << s << endl;
    }
}