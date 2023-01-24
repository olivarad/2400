/**
 * @file lab9.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-10-28
 */

#include <fstream>
#include <iostream>
#include <iomanip>
using namespace std;

int lowest_low(int dailyLows[]); // Function decleration of lowest_low
int highest_low(int dailyLows[]); // Function declearation of highest_low
double average_low(int dailyLows[]); // Function declearation of average_low

int main()
{
    cout.setf(ios::fixed);
    int dailyLows[30]; // Create an empty array of type integer and size for 30 integers
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("lows.txt"); // Opens lows.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        for (int i = 0; i < 30; i++) // Runs through the data file
        {
            inputFile >> dailyLows[i]; //Populates the array index with the appropriate data
        }
    }
    inputFile.close(); // Closes lows.txt

    cout << lowest_low(dailyLows) << endl; // Outputs the lowest low from the lowest_low function
    cout << highest_low(dailyLows) << endl; // Outputs the highest low from the highest_low function
    cout << setprecision(2) << average_low(dailyLows) << endl; // Outputs the average low to 2 decimal places from the average_low dunction
    return 0;
}

int lowest_low(int dailyLows[])
{
    int lowest_low = (dailyLows[0]); // Sets the default lowest low to the first index
    for (int i = 1; i < 30; i++) // iterates through every index in dailyLows but skips index 0 because its already tracked in lowest_low
    {
        if ((dailyLows[i]) < lowest_low) // Checks to see if the next index is of lower value
        {
            lowest_low = (dailyLows[i]); // if the index contains a lower value, lowest_low is overwritten
        }
    }
    return lowest_low;
}

int highest_low(int dailyLows[])
{
    int highest_low = (dailyLows[0]); // Sets the default highest low to the first index
    for (int i = 1; i < 30; i++) // iterates through every index in dailyLows but skips index 0 because its already tracked in highest_low
    {
        if ((dailyLows[i]) > highest_low) // Checks to see if the next index is of higher value
        {
            highest_low = (dailyLows[i]); // if the index contains a higher value, highest_low is overwritten
        }
    }
    return highest_low;
}

double average_low(int dailyLows[])
{
    int sum = (dailyLows[0]); //Initialize the sum to the value stored in the first index of dailyLows
    double average = 0; // Initializes the tracker for the average low`
    for (int i = 1; i < 30; i++) // Iterates through the entire dailyLows while skipping the first index so it isnt counted twice
    {
        sum += dailyLows[i]; // Adds the current indexes value to the sum
    }
    average = sum / 30.0; // Division resulting in a double for more accurate information
    return average;
}