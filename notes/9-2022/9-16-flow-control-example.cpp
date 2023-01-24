#include <iostream>

using namespace std;

// && and || or
int main()
{
    int choice;
    int choice2;
    cout << "Enter a number and a letter" << endl;
    cin >> choice >> choice2;

    if (choice % 2 == 0)
    {
        cout << "You entered an even number" << endl;
    }
    else
    {
        cout << "You did not enter an even number" << endl;
    }

    /*switch(control expression){ //Must evaluate to boolean, character, or integer
        case<val1>:
            //code
            break;
        default:
            //code
            break;
        
    }*/
    switch(choice){
        case 0:
            cout << "You entered 0!" << endl;
            break;
        case 2:
            cout << "You entered 2!" << endl;
            break;
        default:
            cout << "you entered " << choice << endl;
    }

    switch(choice2){
        case 'a':
        case 'A':
            cout << "you entered A" << endl;
            break;
        default:
            cout << "You did not enter A" << endl;
    }

    return 0;
}