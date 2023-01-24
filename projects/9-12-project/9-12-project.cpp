/**
 * @file Untitled-1
 * @author Olivia Radecki (gr982220@ohio.edu)
 * @brief 
 * @version 0.1
 * @date 2022-09-12
 * @copyright Copyright (c) 2022
 */
# include <iostream>
# include <iomanip>

using namespace std;

int main()
{
    double double1; //Establishing Variables
    double double2;
    int int1;
    int int2;
    char char1;
    char char2;

    cout << "please enter two floating point values, two integer values, and two characters. Seperate these variables by whitespace and finish by hitting the enter/return key." << endl << endl;
    cin >> double1 >> double2 >> int1 >> int2 >> char1 >> char2; //Recieve character input

    cout << "double1 = " << setprecision(3) << double1 << endl; //Outputs the variables with labels
    cout << "double2 = " << setprecision(2) << double2 << endl;
    cout << "int1 = " << setw(7) << int1 << endl;
    cout << "int2 = " << setw(25) << int2 << endl;

    cout << "double1 - int1 = " << double1 - int1 << endl; //Arithmetic
    cout << "int2 - double2 = " << int2 - double2 << endl; //Arithmetic
    cout << "double2 * int1 = " << double2 * int1 << endl; //Arithmetic
    cout << "double1 / int2 = " << double1 / int2 << endl; //Arithmetic
    cout << "int1 / double1 = " << int1 / double1 << endl; //Arithmetic
    cout << "int1 / int2 = " << int1 / int2 << endl; //Arithmetic
    cout << "int1 \% int2 = " << int1 % int2 << endl; //Arithmetic

    int1 = static_cast<int>(double1); //casts double1 to int3
    double1 = static_cast<double>(int2);
    char1 = static_cast<char>(int2);
    int2 = static_cast<int>(char2);

    cout << "double1 to integer = " << int1 << endl;//outputs the cast values with labels
    cout << "int1 to double = " << double1 << endl;
    cout << "int1 to character = " << char1 << endl;
    cout << "char1 to integer = " << int2 << endl;

    return 0;
}