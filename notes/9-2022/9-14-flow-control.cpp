#include <iostream>

using namespace std;

int main(){
    int num =0;
    cout << "Enter a number: " << endl;
    cin >> num;

    bool yes_or_no;

    // > < >= <= all evaluate to true or false
    // == test for equal
    // ! not

    //fixed representation of floating point numbers - # of digits after the .
    //Scientific representation - total number of digits
    //choose fixed by using cout << fixed << setprecision(#) << variable or number

    if (num == 5){
        cout << "num = 5" << endl;
    }

    else if (num == 4){
        cout << "num = 4" << endl;
    }
    
    else{
        cout << "Num does not equal 4 or 5" << endl;
    }


    return 0;
}