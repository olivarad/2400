/**
 * @file lab11.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-11-11
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Employee{ // Names strcture Employee
    string employee_id; // String value in the structure
    string first_name; // String value in the structure
    string last_name; // String value in the structure
    string salary; // String value in the structure
};

void data_population(vector<Employee>& employee_data);
void sort(vector<Employee>& employee_data);
void print_report(vector<Employee>& employee_data);
void total_payroll(vector<Employee>& employee_data);

int main()
{
    cout.setf(ios::fixed);
    vector<Employee> employee_data; // Creates an empty vector named employee_data of type Employee from the previous structure
    data_population(employee_data); // Call to the data_population function
    //int sorted_index_order[employee_data.size()]; // array for tracking the correct alphabetical employee order
    sort(employee_data); // Call to the sort function
    print_report(employee_data); // Call the print_report function
    total_payroll(employee_data); // Call to the total_payroll function

    return 0;
}

void data_population(vector<Employee>& employee_data)
{
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("employee-records.txt"); // Opens employee-records.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        int i = 0; // Tracker for vector index
        while(!inputFile.eof()) // Runs until the input file is completley read and reads the file
        {
            employee_data.push_back(Employee()); // Creates another index in the vector
            
            inputFile >> employee_data[i].employee_id; // Populates the current vector index tracking employee_id with the appropriate data
            inputFile >> employee_data[i].first_name; // Populates the current vector index tracking first_name with the appropriate data
            inputFile >> employee_data[i].last_name; // Populates the current vector index tracking last_name with the appropriate data
            inputFile >> employee_data[i].salary; // Populates the current vector index tracking salary with the appropriate data
            
            i++; // Itterates the vector index
        }
    }
    inputFile.close(); // Closes employee-records.txt
}

void sort(vector<Employee>& employee_data)
{
    string temp; // Temporary storage string
    for(int i = 0; i < employee_data.size(); i++) // Itterates through all of the vector
    {
        for(int j = 1; j < employee_data.size()-i;j ++) // Itteration that skips the first index
        {
            if((employee_data[j-1].last_name).substr(0, 1) > (employee_data[j].last_name).substr(0, 1)) // Compares for alphabetization based on the ascii table
            {
                
                temp = employee_data[j-1].employee_id;
                employee_data[j-1].employee_id = employee_data[j].employee_id;
                employee_data[j].employee_id = temp;

                temp = employee_data[j-1].first_name;
                employee_data[j-1].first_name = employee_data[j].first_name;
                employee_data[j].first_name = temp;

                temp = employee_data[j-1].last_name;
                employee_data[j-1].last_name = employee_data[j].last_name;
                employee_data[j].last_name = temp;

                temp = employee_data[j-1].salary;
                employee_data[j-1].salary = employee_data[j].salary;
                employee_data[j].salary = temp;
            }
        }
    }
}

void print_report(vector<Employee>& employee_data)
{
    cout << "Sorted by name\n" << "ID    Name    Salary\n"; // Setup
    for(int i = 1; i < employee_data.size(); i++) // Itterates through the vector
    {
        cout << employee_data[i].employee_id << " " << employee_data[i].first_name << " " << employee_data[i].last_name << " $" << employee_data[i].salary << endl; // Displays neccessary information
    }
}

void total_payroll(vector<Employee>& employee_data)
{
    double total_payroll = 0; // Sets a payroll variable initialized to value 0
    for(int i = 1; i < employee_data.size(); i++) // Itterates through the vector
    {
        total_payroll = total_payroll + stod(employee_data[i].salary); // Counts up the payroll
    }
    cout << "Total Payroll: $" << setprecision(2) << total_payroll << endl; // Outputs the payroll
}