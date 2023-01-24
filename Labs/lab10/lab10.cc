/**
 * @file lab10.cc
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @date 2022-11-04
 */

#include <fstream>
#include <string>
#include <iostream>
using namespace std;

double average_student_count(int num_students_enrolled[]); // Decleartion for average_student_count function

int highest_student_count(int num_students_enrolled[]); // Decleration for highest_student_count function

int lowest_student_count(int num_students_enrolled[]); // Decleration for lowest_student_count function

int main()
{
    const int SIZE = 40; // Sets a constant integer for the size of the arrays
    string course_id[SIZE]; // Creates an empty array to store course id values
    string professor[SIZE]; // Creates an empty array to store professor values
    int num_students_enrolled[SIZE]; // Creates an empty array to store student enrollment values
    ifstream inputFile; // Sets the variable name for the input file
    inputFile.open("courses.txt"); // Opens lows.txt as an input file
    if (!inputFile.fail()) // Check for failure after opening
    {
        for(int i = 0; i < SIZE; i++) // Loops through each course
        {
            string student_count; // Creates an empty string to temporarily store the student count before type conversion
            getline(inputFile, course_id[i]); //Populates the array index with the appropriate data
            getline(inputFile, professor[i]); //Populates the array index with the appropriate data
            getline(inputFile, student_count); //Sets the class size to student count
            num_students_enrolled[i] = stoi(student_count); // Populates the array index with the appropriate data after converting string to integer
        }
    }
    inputFile.close(); // Closes courses.txt

    ofstream outFile; // Sets the variable for the name of the output file
    outFile.open("output.txt"); // Opens output.txt as an output file
    if (!outFile.fail()) // Check for failure after opening
    {
        outFile << "The average number of students for all classes is: " << average_student_count(num_students_enrolled) << endl << endl; // Outputs the average student count for all classes
        outFile << "Courses with " << num_students_enrolled[highest_student_count(num_students_enrolled)] << " student(s):" << endl << "         " << course_id[highest_student_count(num_students_enrolled)] << " taught by " << professor[highest_student_count(num_students_enrolled)] << endl << endl; // Outputs data for class with most students
        int smallest_class_size = lowest_student_count(num_students_enrolled); // Sets the smallest class size
        outFile << "Courses with " << smallest_class_size << " Student(s):" << endl; // Outputs the lowest student count and sets up output format
        for (int i = 0; i < SIZE; i++) // Loops through classes
        {
            if (smallest_class_size == num_students_enrolled[i])
            {
            outFile << "         " << course_id[i] << " Taught by " << professor[i] << endl; // Outputs course info
            }
        }
        outFile << endl; // For formatting
    }

    outFile.close(); // Closes output.txt
    
    return 0;
}

double average_student_count(int num_students_enrolled[])
{
    const int SIZE = 40; // Sets a constant integer for the size of the arrays
    double sum = 0; // Creates and initializes variable for sum
    double average = 0; // Creates and initializes variable for average
    for(int i = 0; i < SIZE; i++) // Loops through each course
    {
        sum += num_students_enrolled[i]; // Adds the class size for current class
    }
    average = sum/SIZE; // Comptes average
    return average; // Returns average
}

int highest_student_count(int num_students_enrolled[])
{
    int highest_student_count_index = 0; // Sets an integer value for tracking the index for the class with the most students
    for (int i = 1; i < 40; i++) // Loops through every class
    {
        if (num_students_enrolled[i] > num_students_enrolled[highest_student_count_index]) // Compares class sizes
        {
            highest_student_count_index = i; // Overwrites the tracked index
        }
    }
    return highest_student_count_index; // Returns the index of the class with the most students
}

int lowest_student_count(int num_students_enrolled[])
{
    const int SIZE = 40; // Sets a constant integer for the class size
    int lowest_student_count = num_students_enrolled[0];
    for (int i = 1; i < SIZE; i++) // Iterates through all classes
    {
        if (num_students_enrolled[i] < lowest_student_count) // Compares for lowest number of students
        {
            lowest_student_count = num_students_enrolled[i]; // Overwrites data for least amount of students
        }
    }
    return lowest_student_count; // Returns lowest_student_count
}