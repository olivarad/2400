#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
• A function to display a menu.

• A function that obtains a key value between 1 and 10

• A function to encrypt. It should ask the user for the input file name and 
output file name, read text from the input file, and output the encrypted text 
to the output file.

• A function to decrypt. It should ask the user for the input file name and 
output file name, read text from the input file, and output the decrypted text 
to the output file. 
Both encryption and decryption functions should take a key parameter. Print an 
error message if any of the files fail to open.
*/

void displayMenu();
int set_key(int key);
void encrypt(int key);
void decrypt(int key);

int main() {
 int choice, key;
 key = 3; //default
 do {
 displayMenu();
 cin >> choice; //Obtains the user choice
 if (choice == 1) {
 key = set_key(key); // call the set key function and assign to key
 }
 else if (choice == 2) {
 encrypt(key); //call the encryption function
 }
 else if (choice == 3) {
 decrypt(key); //call the decryption function
 }
 } while(choice != 4); //Ends the loop when quit is chosen
 return 0;
}

void displayMenu()
{
cout << "menu" << endl << "Select your choice with the numpad and enter when finished" << endl; // These lines are the menu
cout << "1: Set encryption key" << endl;
cout << "2: Call encryption function" << endl;
cout << "3: Call decryption function" << endl;
cout << "4: Quit" << endl;
}

int set_key(int key)
{
    do // Repeats until a valid key is set
    {
        cout << "Please enter a key between 1 and 10 including 1 and 10: "; //Prompts for a key
        cin >> key; // Obtains the key
    }while(key < 1 || key > 10);
    return key; // Returns the key
}

void encrypt(int key)
{
    string input; // Creates an empty string to store the input filename
    string output; // Creates an empty string to store the output filename
    cout << "Please specify the file to be encrypted: "; // Prompts the user for an input file
    cin >> input; // Sets the input file to the user specified file
    cout << "Please specify the output file: "; // Prompts the user for an output file
    cin >> output; // Sets the output file to the user specified file
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open(input); // Opens the file to be encrypted
    if (!inputFile.fail()) // Check for failure after opening
    {
        ofstream outFile; // Sets the variable for the name of the output file
        outFile.open(output); // Opens codes_out.txt as an output file
        if (!outFile.fail()) // Check for failure after opening
        {
            char input_data; // sets a character for the file input
            while(inputFile.get(input_data)) // Runs until the input file is completley read and reads the file
            {
                outFile << char(input_data + key); // Outputs the encrypted character
            }
            outFile.close(); // Closes the output file
        }
        else
        {
            cout << "The file failed to open" << endl; // Prints a failure message to the terminal
        }
        inputFile.close(); // Closes the file that was encrypted
    }
    else
    {
        cout << "The file failed to open" << endl; // Prints a failure message to the terminal
    }
}

void decrypt(int key)
{
    string input; // Creates an empty string to store the input filename
    string output; // Creates an empty string to store the output filename
    cout << "Please specify the file to be decrypted: "; // Prompts the user for an input file
    cin >> input; // Sets the input file to the user specified file
    cout << "Please specify the output file: "; // Prompts the user for an output file
    cin >> output; // Sets the output file to the user specified file
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open(input); // Opens the file to be encrypted
    if (!inputFile.fail()) // Check for failure after opening
    {
        ofstream outFile; // Sets the variable for the name of the output file
        outFile.open(output); // Opens codes_out.txt as an output file
        if (!outFile.fail()) // Check for failure after opening
        {
            char input_data; // sets a character for the file input
            while(inputFile.get(input_data)) // Runs until the input file is completley read and reads the file
            {
                outFile << char(input_data - key); // Outputs the encrypted character
            }
            outFile.close(); // Closes the output file
        }
        else
        {
            cout << "The file failed to open" << endl; // Prints a failure message to the terminal
        }
        inputFile.close(); // Closes the file that was encrypted
    }
    else
    {
        cout << "The file failed to open" << endl; // Prints a failure message to the terminal
    }
}