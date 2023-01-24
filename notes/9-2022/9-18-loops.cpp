#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main ()
{
    int x = 10;
    int y = 0;

    while(x >= 1)
    {
        cout << "x= " << x << endl;
        x--;
    }

    do{
        cout << "y= " << y << endl;
        y--;
    }while(y >= 1);

    for(int i = 1; i < 11; i++)//(initialization; condition; update)
    {
        cout << "i =" << i << endl;
    }

return(0);
}