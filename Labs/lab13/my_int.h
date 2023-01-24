#ifndef MY_INT_H
#define USER_H

class my_int
{
  friend my_int operator>(my_int i1, my_int i2); // Freind function decleration that takes two members of my_int

public:
  //*********************************************************
  // Function: my_int
  // Purpose:  Constructor initializes the val to x
  // Params:   x - the value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  my_int(int x);   

  //*********************************************************
  // Function: my_int       
  // Purpose:  Constructor initializes the val to 0      
  // Params:   none      
  // Calls:    none                                    
  // Uses:     none           
  //*********************************************************
  my_int();       

  //*********************************************************
  // Function: set
  // Purpose:  Sets the val to x
  // Params:   x - the new value for the val
  // Calls:    none
  // Uses:     none
  //*********************************************************
  void set(int x); 

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
  void input(istream& inp);  
 
  //*********************************************************************
  // Function: output
  // Purpose:  display the val on fout. if fout is a  output stream
  //           then fout is already  connected to a file
  // Params:   fout -- the output stream
  // Calls:    none
  // Uses:     ostream
  //*********************************************************************
  void output(ostream& fout) const;

  //*********************************************************
  // Function: get_int
  // Purpose:  returns the val
  // Params:   none
  // Calls:    none
  // Uses:     none
  //*********************************************************
  int get_int();

 /* my_int operator>(const my_int& b)
  {
    my_int is_greater_than;
    is_greater_than = (this->val > b.val);
    return is_greater_than;
  }*/
  //*********************************************************
// Function: is_prime
// Purpose:  object num contains a valid positive value
//           returns true if num is prime; otherwise
//           returns false
// Params:   num  - the value to be checked for prime
// Calls:    sqrt
// Uses:     cmath 
//*********************************************************
bool is_prime(my_int& num);
private:
  int val;  // Variable to hold value for class
};
#endif