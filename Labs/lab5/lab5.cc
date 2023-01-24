/**
 * @file lab5.cc
 * @author Olivia Radekci (gr982220@ohio.edu)
 * @date 2022-09-26
 * @brief Write a program which will use a while loop to prompt and read the high and low temperatures
for each day from the user. As you read in the high and low temp for a given day, save the
highest high you have seen so far, and likewise the lowest low. Allow the user to end the loop
by entering the sentinel value -100.
When the user ends the loop, print out the highest and lowest temperature seen so far for the
month of September.
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout.setf(ios::fixed);//set precisions to after decimal
    cout.precision(2);//set precision for the program to 2 decimals
    double input_temperature, highest_temperature, lowest_temperature;//establish variables to work with
    cout << "Please enter the temperature: ";
    cin >> input_temperature;
    highest_temperature = input_temperature;//initializes the temperature record
    lowest_temperature = input_temperature;
    while (input_temperature != -100)//will run 1 time past -100 because input_temperature is set inside the function
    {
        cout << "Please enter the temperature: ";
        cin >> input_temperature;
        if (input_temperature == -100)//accounts for the extra run of the loop
        {
            cout << "Low: " << lowest_temperature << "\nHigh: " << highest_temperature << endl;//last thing in the loop ran, outputs stored and tracked values
        }
        if (input_temperature > highest_temperature)// sets the new highest temp
        {
            highest_temperature = input_temperature;
        }
        if ( (input_temperature < lowest_temperature))//sets the new lowest temp
        {
            lowest_temperature = input_temperature;
        }
    }
return (0);
}
