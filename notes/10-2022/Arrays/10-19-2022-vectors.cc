#include <vector>
using namespace std;
const int SIZE = 1000;
int data[SIZE];
vector<int> vec;// using vector<int> name(size) will give a vector that already has thas size allocated and will not grow until you exaust the size alloted
//in order to call the index of a vector that index must first exist
//to add uninitialized space to a vector you can use name.push_back(size)
//name.size(); how many indexes have been used
//name.pop_back(); removes last thing out of the vector
//name.capacity(); how many elements have been allocated
//name.at(index) similar to finding the value in the index but will return an error when no such index exsits
//vector<int> name(size, initialization); will create an integer type vector with name name of size size and each index will store the same initialization value
//name.reserve(size); this is total indexes not additional
//name.resize(size); shrinks vector
//name.front(); gives whats at position 0
//name.back(); gives whats at last position
//name.empty(); will return true if vector has size 0
//name.erase();
//name.begin(); this will remove an intem in that index and move everything after it up by one

//To pass a vector in a function you must pass by reference
//To return a vector, it must be the functions return type