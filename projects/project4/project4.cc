/**
 * @file project4.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-11-17
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

struct Address{ // Names structure Address
    string name; // String value in the structure
    string street_number; // String value in the structure
    string street_name; // String value in the structure
    string city; // String value in the structure
    string state; // String value in the structure
    string zip_code; // String value in the structure
};

struct Letter{ // Named structure Letter
    string from; // Address value to store sender address
    string to; // Address value to store recipient address
    string barcode; // String value to store barcode
};

void load_address(vector<Address>& address); // Decleration of load_address function

void print_address(const vector<Address>& address, int i); // Function declearation of print_address

void load_letter(vector<Letter>& letter, const vector<Address>& address, int k); // Decleration of the load letter function

void print_letter(const vector<Letter>& letter); // Decleration of the print letter function

void create_barcode(vector<Letter>& letter, vector<Address>& address, int i); // Decleration for the create_cbarcode function

int main()
{
    vector<Address> address; // Creates an empty vecotr to store the addresses, addresses will be store in pairs of sender and recipient.
    vector<Letter> letter; // Creates an empty vector to store letter details
    load_address(address); // Calls the load_address function
    
    int i; // An integer to store the choice of address index
    cout << "Please enter the index storing the address to be printed: \n"; // Prompts for an address choice
    cin >> i; // Recieves user input
    print_address(address, i); // Calls the print_address function

    load_letter(letter, address, i); // Calls the load_letter function

    create_barcode(letter, address, i); // Calls the create_barcode function

    print_letter(letter); // Calls the print letter function

    return 0;
}

void load_address(vector<Address>& address)
{
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("letters.txt"); // Opens letters.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        int i = 0; // Tracker for vector index
        while(!inputFile.eof()) // Runs until the input file is completley read and reads the file
        {
            address.push_back(Address()); // Creates another index in the vector
            
            getline(inputFile, address[i].name); // Populates the current vector index tracking name with the appropriate data
            getline(inputFile, address[i].street_number); // Populates the current vector index tracking street_number with the appropriate data
            getline(inputFile, address[i].street_name); // Populates the current vector index tracking street_name with the appropriate data
            getline(inputFile, address[i].city); // Populates the current vector index tracking city with the appropriate data
            getline(inputFile, address[i].state); // Populates the current vector index tracking state with the appropriate data
            getline(inputFile, address[i].zip_code); // Populates the current vector index tracking zip_code with the appropriate data
            i++; // Itterates the vector index
        }
    }
    inputFile.close(); // Closes employee-records.txt
}

void print_address(const vector<Address>& address, int i)
{
    cout << address[i].name << endl << address[i].street_number << endl << address[i].street_name << endl << address[i].city << endl << address[i].state << endl << address[i].zip_code << endl; // Printing the chosen address
}

void load_letter(vector<Letter>& letter, const vector<Address>& address, int k)
{
    for(int i = 0; i < address.size(); i++)
    {
        letter.push_back(Letter()); // Creates another index in the vector

        letter[i].from = address[i].name + "\n" + address[i].street_number + "\n" + address[i].street_name + "\n" + address[i].city + "\n" + address[i].state + "\n" + address[i].zip_code + "\n";
    }
    cout << letter[k].from << endl;
}

void create_barcode(vector<Letter>& letter, vector<Address>& address, int i)
{
    string zipcode_in = address[i].zip_code;
    int barcode_digit;
    string barcode;
    for(int k = 0; k < (address[i].zip_code).length(); k++)
    {
        barcode_digit = (zipcode_in[k]);
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
    address[i].zip_code = barcode;
}

void print_letter(const vector<Letter>& letter)
{
    for(int i = 0; i < letter.size(); i++)
    {
        cout << letter[i].from << " " << letter[i].to << " " << letter[i].barcode << endl;
    }
}