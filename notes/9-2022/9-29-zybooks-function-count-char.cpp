#include <string>
#include <iostream>
using namespace std;

/**
   Gets the number of times the character c appears in the string.
   @param str any string
   @param c the single-character string to search for
   @return the number of times c appears in str
*/

int count_char(string str, string c)
{
   int count = 0;
   for (int i = 0; i < str.length(); i++)
   {
      if (str.substr(i, 1) == c) { count++; }
   }
   return count;
}

int main()
{
   string str;
   string c;
   getline(cin, str);
   cin >> c;
   cout << count_char(str, c) << endl;
   return 0;
}