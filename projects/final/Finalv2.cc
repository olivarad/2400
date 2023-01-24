/**
 * @file Final.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-12-02
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
using namespace std;

void turn_to_barcode(int barcode_digit, string &barcode);

struct Address
{
    string house_number;
    string street_name;
    string city;
    string state;
    string zipcode;
};

struct Letter
{
    string recipient;
    string sender_name;
    Address sender;
    string letter_information;
};

class Home
{
    public:
        Address address_information;
        vector<Letter> letters; // Vector of letters sent to this house.

        void add_letter()
        {
            letters.push_back(Letter()); // Creates another index in the vector.

            cout << "Plese provide the recipient name\n"; // Prompts for the recipient name.
            getline(cin, letters[number_of_letters].recipient); // Write the recipient name.

            cout << "Please provide the sender name\n"; // Prompts for the sender's name.
            getline(cin, letters[number_of_letters].sender_name); // Writes the senders name.
            cout << "Please provide the sender house number\n"; // Prompts for the sender's house number.
            getline(cin, letters[number_of_letters].sender.house_number); // Writes the senders house number.
            cout << "Please provide the sender street name\n"; // Prompts for the sender's street name.
            getline(cin, letters[number_of_letters].sender.street_name); // Writes the senders street name.
            cout << "Please provide the sender city\n"; // Prompts for the sender's city.
            getline(cin, letters[number_of_letters].sender.city); // Writes the senders city.
            cout << "Please provide the sender state\n"; // Prompts for the sender's state.
            getline(cin, letters[number_of_letters].sender.state); // Writes the senders state.
            cout << "Please provide the sender zipcode\n"; // Prompts for the sender's zipcode.
            getline(cin, letters[number_of_letters].sender.zipcode); // Writes the senders zipcode.

            cout << "Please provide the letter information\n"; // Prompts for the letter information.
            getline(cin, letters[number_of_letters].letter_information); // Writes the letter information.
        }
    private:
        int number_of_letters = 0;

};

class Neighborhood
{
    public:
        string name; // The name of the neighborhood.
        vector<Home> homes_in_neighborhood; // Creates a vector to store the homes in a neighborhood.

        void create_neighborhood()
        {
            cout << "Please provide a name for the neigborhood\n";
            cin.ignore(); // Ignores the newline character that would otherwise prevent getline from working.
            getline(cin, name); // Obtains the neighborhood name.
        }

        void add_home()
        {
            homes_in_neighborhood.push_back(Home()); // Creates another index in the vector.
            cout << "Please provide the house number \n"; // Prompts for the house number.
            getline(cin, homes_in_neighborhood[number_of_homes].address_information.house_number); // Obtains and writes the house number.
            cout << "Please provide the street name \n"; // Prompts for the street name.
            getline(cin, homes_in_neighborhood[number_of_homes].address_information.street_name); // Obtains and writes the street name.
            cout << "Please provide the city \n"; // Prompts for the city.
            getline(cin, homes_in_neighborhood[number_of_homes].address_information.city); // Obtains and writes the city.
            cout << "Please provide the state \n"; // Prompts for the state.
            getline(cin, homes_in_neighborhood[number_of_homes].address_information.state); // Obtains and writes the state.
            cout << "Please provide the 5 digit zipcode \n"; // Prompts for the zip code.
            getline(cin, homes_in_neighborhood[number_of_homes].address_information.zipcode); // Obtains and writes the zipcode.
        }

        int find_home()
        {
            int index = 0;
            string house_number;
            cout << "Please specify the house number of the address you are looking for\n";
            for(unsigned int i = 0; i < homes_in_neighborhood.size(); i++)
            {
                cout << homes_in_neighborhood[i].address_information.house_number << endl; // Print every house number in the neighborhood.
            }
            getline(cin, house_number); // Obtain the desired house_number.
            unsigned int i = 0;
            for(i = 0; i < homes_in_neighborhood.size(); i++)
            {
                if(house_number == homes_in_neighborhood[i].address_information.house_number) // Index match.
                {
                    break;
                }
            }
            return index;

        }

    private:
        int number_of_homes = 0;
};

class PostOffice
{
    public:
        Neighborhood neighborhoods_in_domain[5];
        void add_neighborhood(Neighborhood& neighborhood_number)
        {
            neighborhoods_in_domain[set] = neighborhood_number; // Adds the neighborhood to the array of neighborhoods
            set++; // Itterates set.
        }

        void output()
        {
            int checksum_digit = 0; // Initializes the checksum digit to 0
            int sum = 0; // Initializes a tracker for sum, it is reset to 0 every itteration of the loop
            int barcode_digit = 0; // Initializes the barcocde digit to 0
            string barcode = "|";
            ofstream outFile; // Sets the variable for the name of the output file
            outFile.open("output.txt"); // Opens output.txt as an output file
            outFile << "      Post Office General Information Report\n";
            outFile << "--------------------------------------------------\n";
            for(int i = 0; i < 5; i++) // Itterates through each neighborhood.
            {
                outFile << "Neighborhood " << i << ":\n";
                outFile << "        ------------------------------------------\n";
                for(unsigned int j = 0; j < neighborhoods_in_domain[i].homes_in_neighborhood.size(); j++) // Itterates through each house in the neighborhood
                {
                    outFile << "Home " << j << "'s Address:\n";
                    outFile << "            " << neighborhoods_in_domain[0].homes_in_neighborhood[0].address_information.house_number << " " << neighborhoods_in_domain[0].homes_in_neighborhood[0].address_information.street_name << endl;
                    outFile << "            " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.city << " " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.state << " " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.zipcode << endl;
                    outFile << "        Letters:\n";
                    outFile << "            **************************************";
                    for(unsigned int k = 0; k < neighborhoods_in_domain[i].homes_in_neighborhood[j].letters.size(); k++) // Itterates through the letters for a home
                    {
                        outFile << "            Information for letter " << k << "\n\n";
                        outFile << "            From:\n";
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender_name << endl;
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender.house_number << " " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender.street_name << endl;
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender.city << ", " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender.state << " " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].sender.zipcode << "\n\n";
                    
                        outFile << "            To:\n";
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].letters[k].recipient << endl;
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.house_number << " " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.street_name << endl;
                        outFile << "                " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.city << ", " << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.state << neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.zipcode << "\n\n";
                        
                        for(int index = 0; index < 5; index ++)
                        {
                            barcode_digit = stoi(neighborhoods_in_domain[i].homes_in_neighborhood[j].address_information.zipcode.substr(index, 1)); // Finds the current digit for the index
                            sum += barcode_digit; // Adds the value of the current index in integer form to sum
                            turn_to_barcode(barcode_digit, barcode); // Turns the digit into barcode form
                        }

                        while (sum % 10 != 0) // While the sum is not a multiple of 10
                        {
                            checksum_digit+= 1; // Increment the checksum digit
                            sum+= 1; // Increment the sum
                        }
                        turn_to_barcode(checksum_digit, barcode); // turn the checksum digit into barcode form
                        barcode += "|"; // Add the ending seperator for the barcode
                        
                        outFile << "            Barcode:\n";
                        outFile << "                " << barcode << endl;
                        outFile << "            **************************************\n";
                    }

                }
            }
            outFile.close();
        }
    private:
        int set = 0; // Tracker for how many neighborhoods have been added to the post office roster.
};

void menu(bool &quit, int named_neighborhoods, Neighborhood &neighborhood_number, PostOffice &postoffice, Neighborhood &n0, Neighborhood &n1, Neighborhood &n2, Neighborhood &n3, Neighborhood &n4);

int main()
{
    PostOffice postoffice; // Creates the post office.

    Neighborhood neighborhood_0; // Creates the 0th neighborhood.
    Neighborhood neighborhood_1; // Creates the 1th neighborhood.
    Neighborhood neighborhood_2; // Creates the 2th neighborhood.
    Neighborhood neighborhood_3; // Creates the 3th neighborhood.
    Neighborhood neighborhood_4; // Creates the 4th neighborhood.

    int named_neighborhoods = 0; // Tracker for the number of named neighborhoods.

    bool quit = 0;
    while (quit == 0)
    {
        switch (named_neighborhoods) // Makes sure the right neighborhood gets named.
        {
            case 0:
                menu(quit, named_neighborhoods, neighborhood_0, postoffice, neighborhood_0, neighborhood_1, neighborhood_2, neighborhood_3, neighborhood_4);
                break;
            case 1:
                menu(quit, named_neighborhoods, neighborhood_1, postoffice, neighborhood_0, neighborhood_1, neighborhood_2, neighborhood_3, neighborhood_4);
                break;
            case 2:
                menu(quit, named_neighborhoods, neighborhood_2, postoffice, neighborhood_0, neighborhood_1, neighborhood_2, neighborhood_3, neighborhood_4);
                break;
            case 3:
                menu(quit, named_neighborhoods, neighborhood_3, postoffice, neighborhood_0, neighborhood_1, neighborhood_2, neighborhood_3, neighborhood_4);
                break;
            case 4:
                menu(quit, named_neighborhoods, neighborhood_4, postoffice, neighborhood_0, neighborhood_1, neighborhood_2, neighborhood_3, neighborhood_4);
                break;
        }
        named_neighborhoods++; //Itterates named_neighborhoods.


    }

    /*
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.name << endl;
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.house_number << endl;
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.street_name << endl;
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.city << endl;
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.state << endl;
    cout << neighborhood_0.homes_in_neighborhood[0].address_information.zipcode << endl;

    cout << neighborhood_0.homes_in_neighborhood[0].letters[0].letter_information << endl;
    */

    return 0;
}

void menu(bool &quit, int named_neighborhoods, Neighborhood &neighborhood_number, PostOffice &postoffice, Neighborhood &n0, Neighborhood &n1, Neighborhood &n2, Neighborhood &n3, Neighborhood &n4)
{
    int option = 0;
    int house_index;
    //bool exsists = 0;
    string neighborhood_name; // Name of neighborhood to be selected in option 2.
    cout << "Please select an option: \n";
    cout << "1. Create a new neighborhood" << endl << 
    "2. Create a new home and move into a neighborhood" << endl << 
    "3. Send a letter" << endl << 
    "4. Output all post office information to a file" << endl << 
    "5. Quit" << endl;
    do
    {
        cin >> option;
    }
    while(1 > option || option > 5);

    switch(option)
    {
        case 1: // Create a neighborhood and add it to the post office. Only provide information for the neighborhoods name at this time.
            neighborhood_number.create_neighborhood(); // Runs the create_neighborhood function.
            postoffice.add_neighborhood(neighborhood_number); // Runs the add_neighborhood function.
            break;
        case 2:
            cout << "Please specify which neighborhood you would like to add a home to\n";
            for (int i = 0; i < 5; i++)
            {
                cout << postoffice.neighborhoods_in_domain[i].name << endl; // Prints the current neighborhoods available.
            }
            cin.ignore(); // Ignores the newline character that would otherwise prevent getline from working.
            getline(cin, neighborhood_name); // writes the name of the neighborhood to be found.
            for (int i = 0; i < 5; i++)
            {
                if (neighborhood_name == postoffice.neighborhoods_in_domain[i].name) // If the names of the neighborhoods match.
                {
                    switch(i)
                    {
                        case 0:
                            n0.add_home(); // Runs the add_home function
                            break;
                        case 1:
                            n1.add_home(); // Runs the add_home function
                            break;
                        case 2:
                            n2.add_home(); // Runs the add_home function
                            break;
                        case 3:
                            n3.add_home(); // Runs the add_home function
                            break;
                        case 4:
                            n4.add_home(); // Runs the add_home function
                            break;
                    }
                    break; // Ends the loop after the correct index is located.
                }
            }
            break;
        case 3: // Add letter
            cout << "Please specify which neighborhood you would like to send a letter to\n";
            for (int i = 0; i < 5; i++)
            {
                cout << postoffice.neighborhoods_in_domain[i].name << endl; // Prints the current neighborhoods available.
            }
            cin.ignore(); // Ignores the newline character that would otherwise prevent getline from working.
            getline(cin, neighborhood_name); // writes the name of the neighborhood to be found.

            for (int i = 0; i < 5; i++)
            {
                if (neighborhood_name == postoffice.neighborhoods_in_domain[i].name) // If the names of the neighborhoods match.
                {
                    switch(i)
                    {
                        case 0:
                            house_index = n0.find_home(); // Runs the find_home function
                            n0.homes_in_neighborhood[house_index].add_letter(); // Adds a letter to the chosen house
                            break;
                        case 1:
                            house_index = n1.find_home(); // Runs the find_home function
                            n1.homes_in_neighborhood[house_index].add_letter(); // Adds a letter to the chosen house
                            break;
                        case 2:
                            house_index = n2.find_home(); // Runs the find_home function
                            n2.homes_in_neighborhood[house_index].add_letter(); // Adds a letter to the chosen house
                            break;
                        case 3:
                            house_index = n3.find_home(); // Runs the find_home function
                            n3.homes_in_neighborhood[house_index].add_letter(); // Adds a letter to the chosen house
                            break;
                        case 4:
                            house_index = n4.find_home(); // Runs the find_home function
                            n4.homes_in_neighborhood[house_index].add_letter(); // Adds a letter to the chosen house
                            break;
                    }
                    break; // Ends the loop after the correct index is located.
                }
            }
        
        case 4:
            postoffice.output(); // Runs the output function.
            break;
        case 5:
            quit = 1; // Quits program.
            break;    
    }
}

void turn_to_barcode(int barcode_digit, string &barcode)
{
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