/**
 * @file Final.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-12-02
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstreeam>
using namespace std;

class Home
{
public:
    string address_line1; // String object to store the home address
    string address_line2; // String object to store the home address
    string address_line3; // String object to store the home address

    vector<string> letter; // Vector object to store the letters

    void add_letter(string letter_in)
    {
        letter.push_back(string()); // Creates another index in the vector
        letter[letter_count] = letter_in; // Populates the current vector index tracking employee_id with the appropriate data
        letter_count++;
    }

    void add_address() // Obtains an address and writes the data to a variable of type Home
    {
        cout << "Please enter the first line of the address: ";
        getline(cin, address_line1);
        cout << "Please enter the second line of the address: ";
        getline(cin, address_line2);
        cout << "Please enter the third line of the address: ";
        getline(cin, address_line3);

    }

    void print_address() // Function added in to print addresses
    {
        cout << address_line1 << endl << address_line2 << endl << address_line3 << endl; // Prints the address
    }

    string operator==(const Home& home) const // Operator overload for the == operator to test if addresses are the same
    {
        string is_equal;

        if ((address_line1) == (home.address_line1) && (address_line2) == (home.address_line2) && (address_line3) == (home.address_line3))
        {
            is_equal = "The addresses are the same";
        }
        else
        {
            is_equal = "The addresses are different";
        }

        return is_equal;
    }

private:
    int letter_count = 0;

};

class Neighborhood
{
public:
    string name;
    vector<Home> homes; // A vector to store the homes in a neighbourhood

    void populate_neighborhood(Home home)
    { 
        string destination_neighborhood;
        destination_neighborhood = (home.address_line2).erase(0, (home.address_line2).find_first_of(" ")); // Finds the destination neighborhood by removing up until the first space (the street number)
        
        homes.push_back(Home()); // Creates another index in the vector
        homes[homes_in_neighborhood].address_line1 = home.address_line1; // Populates address information
        homes[homes_in_neighborhood].address_line2 = home.address_line2; // Populates address information
        homes[homes_in_neighborhood].address_line3 = home.address_line3; // Populates address information
    }

private:
    int homes_in_neighborhood = 0;
    
};

struct neighborhood_info
{
    string neiborhood_name; // String value in the structure
};

class PostOffice
{
public:
    neighborhood_info served[5]; // Creates an empty array for storing the neighborhood indecies as neighborhood#

    string add_neighborhood()
    {
        string user_provided_name;
        cout << "Please provide a name for the neighborhood: \n";
        cin >> user_provided_name;
        served[set].neiborhood_name = user_provided_name;
        return user_provided_name;
    }

private:
    int set = 0;
};

int main()
{

    PostOffice postoffice; // Creates a post office
    Neighborhood neighborhood_0;
    Neighborhood neighborhood_1;
    Neighborhood neighborhood_2;
    Neighborhood neighborhood_3;
    Neighborhood neighborhood_4;
    Home home_0;
    Home home_1;
    Home home_2;
    Home home_3;
    Home home_4;

    //Menu
    int option = 0;
    string neighborhood_name;
    cout << "Please select an option: \n";
    cout << "1. Create a new neighborhood" << endl << 
    "2. Create a new home and move into a neighborhood" << endl << 
    "3. Send a letter" << endl << \
    "4. Output all post office information to a file" << endl << 
    "5. Quit" << endl;
    do
    {
        cin >> option;
    }
    while(option > 5 || 1 > option);

    string neiborhood_name;
    int number_of_named_neighborhoods = 0;

    switch(option)
    {
        case 1: // Create a new neighborhood 
            neiborhood_name = postoffice.add_neighborhood(); // Runs the add_neighborhood function in PostOffice class
            switch(number_of_named_neighborhoods)
            {
                case 0:
                    neighborhood_0.name = neiborhood_name;
                break;
                case 1:
                    neighborhood_1.name = neiborhood_name;
                break;
                case 2:
                    neighborhood_2.name = neiborhood_name;
                break;
                case 3:
                    neighborhood_3.name = neiborhood_name;
                break;
                case 4:
                    neighborhood_4.name = neiborhood_name;
                break;
            }
            break;
        case 2: // Create a new home and add it to a neighborhood
            
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;    
    }
    // End menu

    return 0;
}




/*Address is_equal;
                    cout << "Please provide the name of the resident \n"; // Prompts for the resident's name.
                    getline(cin, is_equal.name); // Obtains and writes the name of the resident.
                    cout << "Please provide the house number \n"; // Prompts for the house number.
                    getline(cin, is_equal.house_number); // Obtains and writes the house number.
                    cout << "Please provide the street name \n"; // Prompts for the street name.
                    getline(cin, is_equal.street_name); // Obtains and writes the street name.
                    cout << "Please provide the city \n"; // Prompts for the city.
                    getline(cin, is_equal.city); // Obtains and writes the city.
                    cout << "Please provide the state \n"; // Prompts for the state.
                    getline(cin, is_equal.state); // Obtains and writes the state.
                    cout << "Please provide the 5 digit zipcode \n"; // Prompts for the zip code.
                    getline(cin, is_equal.zipcode); // Obtains and writes the zipcode.*/
                    /*switch (i)
                    {
                        case 0:
                            for (unsigned int j = 0; j < n0.homes_in_neighborhood.size(); j++)
                            {
                                exsists = (is_equal == n0.homes_in_neighborhood[0].address_information); // the addresses are equal
                            }
                            break;
                        case 1:
                            
                            break;
                        case 2:
                            
                            break;
                        case 3:
                            
                            break;
                        case 4:
                            
                            break;
                    }*/