#include <iostream>
using namespace std;

class Counter
{
 public:
 Counter (); //initializes the counter value to 0.
 int counter;
 Counter(int new_val); // value is set according to the
 // incoming argument.
 void increment(); //increment counter value by 1.
 int get_value(); //returns the value of member
 //variable
 private:
 int value;
};


int main()
{
    Counter::counter object; // Creates an object of the class
    //object.counter = 7;
    //cout << object.counter;
    return 0;
}
