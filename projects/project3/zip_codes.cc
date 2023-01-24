#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
using namespace std;

void turn_to_barcode(int barcode_digit, string &barcode); //Funtion for turning a digit into its barcode form

int main()
{
    char char_array[5]; // Creates an array to store the values of the zipcode as characters as isdigit only works with characters.
    string zipcode_in; // Tracker for the input zipcode_in
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("codes_in.txt"); // Opens codes_in.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        ofstream outFile; // Sets the variable for the name of the output file
        outFile.open("codes_out.txt"); // Opens codes_out.txt as an output file

        while(!inputFile.eof()) // Runs until every input line is used
        {
            string barcode = "|"; // Adds the first character seperator the the barcode
            int checksum_digit = 0; // Initializes the checksum digit to 0
            int sum = 0; // Initializes a tracker for sum, it is reset to 0 every itteration of the loop
            inputFile >> zipcode_in; // writes the current input line into zipcode_in
            if (zipcode_in.length() == 5) // Checks to see if the zipcode is of valid length
            {
                for(int index = 0; index < 5; index++) // loops for 5 iterations to check if each index in the string "zipcode_in" is a character
                {
                    int barcode_digit = 0; // Initializes the barcocde digit to 0
                    strcpy(char_array, zipcode_in.c_str()); // copies the input zipcode into an array of characters instead of a string
                    if (isdigit(char_array[index]) == 0) // Checks to see if the current index is not a character
                    {
                        outFile << "Illegal characters in zip code: " << zipcode_in << endl; // Outputs the fail message for invalid code to the output file
                        break; // Breaks and jumps to the top of the while loop to check the next line of the input file
                    }
                    else // The index is a digit
                    {
                        barcode_digit = stoi(zipcode_in.substr(index, 1)); // Finds the current digit for the index
                        sum += barcode_digit; // Adds the value of the current index in integer form to sum
                        turn_to_barcode(barcode_digit, barcode); // Turns the digit into barcode form
                    }

                    if (index == 4) // will only output the sum if all characters are digits
                    {
                        while (sum % 10 != 0) // While the sum is not a multiple of 10
                        {
                            checksum_digit+= 1; // Increment the checksum digit
                            sum+= 1; // Increment the sum
                        }
                        turn_to_barcode(checksum_digit, barcode); // turn the checksum digit into barcode form
                        barcode += "|"; // Add the ending seperator for the barcode
                        outFile << barcode << endl; // Output the barcode
                    }
                }
            }

            else
            {
                outFile << "Zip code " << zipcode_in << " is not 5 digits" << endl; // Output the error message for invalid length
            }
        }

        inputFile.close(); // Closes codes_in.txt
        outFile.close(); // Closes codes_out.txt

        return 0;
}
}

void turn_to_barcode(int barcode_digit, string &barcode){
    switch (barcode_digit) // Checks the digit and adds its barcode form to the barcode
    {
        case 0:
            barcode+= "||:::";
            break;
        case 1:
            barcode+= ":::||";
            break;
        case 2:
            barcode+= "::|:|";
            break;
        case 3:
            barcode+= "::||:";
            break;
        case 4:
            barcode+= ":|::|";
            break;
        case 5:
            barcode += ":|:|:";
            break;
        case 6:
            barcode += ":||::";
            break;
        case 7:
            barcode += "|:::|";
            break;
        case 8:
            barcode += "|::|:";
            break;
        case 9:
            barcode += "|:|::";
            break;
    }
}