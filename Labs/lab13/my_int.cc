#include <iostream>
#include <cstdlib>
#include <cmath>
#include "my_int.h"

//*********************************************************
// Function: my_int
// Purpose:  Constructor initializes the val to x
// Params:   x - the value for the val
// Calls:    none
// Uses:     none
//*********************************************************
my_int::my_int(int x)
{
   val = x;
}

  //*********************************************************
  // Function: my_int       
  // Purpose:  Constructor initializes the val to 0      
  // Params:   none      
  // Calls:    none                                    
  // Uses:     none           
  //*********************************************************
my_int::my_int()
{
  val = 0;
}


  //*********************************************************
  // Function: set
  // Purpose:  Sets the val to x
  // Params:   x - the new value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
void my_int::set(int a)
{
   val = a;
}


  //*********************************************************************
  // Function: output
  // Purpose:  display the val on fout. if fout is a  output stream
  //           then fout is already  connected to a file
  // Params:   fout -- the output stream
  // Calls:    none
  // Uses:     ostream
  //*********************************************************************
void my_int::output(ostream& fout) const
{
  fout<<" The value is equal to "<<val<<endl;
}


  //*********************************************************
  // Function: get_int
  // Purpose:  returns the val
  // Params:   none
  // Calls:    none
  // Uses:     none
  //*********************************************************
int my_int:: get_int()
{
  return val;
}


  //*********************************************************************
  // Function: input
  // Purpose:  reads and stores a value from inp. if inp is a input 
  //           stream, then inp is already connected to a file.User enters 
  //           a value and ask the user to re-enter the data if the
  //           user enters an incorrect value.
  // Params:   inp -- the input stream
  // Calls:    none
  // Uses:     istream
  //*********************************************************************
void my_int:: input(istream& inp)
{
   cout<<"Enter a positive value greater than 1  ";
   inp >> val;
   while (val <= 1)
   {
    cout<<"Entered an Invalid value \n";
    cout<<"Enter a positive value greater than 1 \n";
    inp>> val;
   }  
}

          
//*********************************************************
// Function: is_prime
// Purpose:  object num contains a valid positive value
//           returns true if num is prime; otherwise
//           returns false
// Params:   num  - the value to be checked for prime
// Calls:    sqrt
// Uses:     cmath 
//*********************************************************
my_int:: operator>(my_int i1, my_int i2)//Function Definition
{
  bool is_greater_than = (i1.val > i2.val); //Accesses the values of i1 and i2 to compare and output appropriately
  if (is_greater_than == 1)
  cout << i1.val << " is greater than " << i2.val << endl;
  else
  cout << i1.val << " is not greater than " << i2.val << endl;
  return(0);
}

bool my_int:: is_prime(my_int& num)
{
  double limit;
  int n;      //divisor
  bool prime= true; 

  limit = sqrt(static_cast<double>(num.get_int()));
  
  n = 2;

  while (n <= limit && prime)
  {
    if (num.get_int() % n == 0)
     prime = false;
    else
     n++;
   }
   return prime;
}