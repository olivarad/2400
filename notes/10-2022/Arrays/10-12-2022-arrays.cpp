#include <iostream>
using namespace std;

int main(){
// type name[number of objects];
int numbers[50];//creates an array with name numbers for 50 integers
// type name[amount] = {comma seperate values};
// double matrix[10][10];//assigns two arrays with memory locations adjacent to each other
cout << "Enter a value for the 0th index: " << endl;
cin >> numbers[0];//initialize numbers index 0
//cout << numbers[0] << endl << numbers[1];//output index 0 and index 1
for (int i = 0; i< 50; i++){
    cout << numbers[i] << endl;
}
}