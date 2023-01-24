#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string zipcode_in;
    vector<char> vec_zipcode_in; // Tracker for the input zipcode_in
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("codes_in.txt"); // Opens codes_in.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        while(!inputFile.eof()) // Runs until every input line is used
        {
            inputFile >> zipcode_in; // writes the current input line into zipcode_in
            for(unsigned int i = 0; i < zipcode_in.length(); i++)
            {
                vec_zipcode_in[i] = zipcode_in[i];
            }
            cout << "Capacity: " << zipcode_in.capacity() << endl;
            cout << "Size: " << zipcode_in.size() << endl;

        }

        inputFile.close(); // Closes codes_in.txt

        return 0;
}
}