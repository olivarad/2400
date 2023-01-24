#include <iostream>
using namespace std;

void default_args(int num = 0);

int main()
{
    default_args();
    return 0;
}

void default_args(int num)
{
    cout << "num = " << num << endl;
}