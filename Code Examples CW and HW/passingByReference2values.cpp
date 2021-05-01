/******************************************************************************
Jonathon Stillson CSC201 CW 30MAR
2. Passing by reference example for two values
*******************************************************************************/
#include <iostream>
using namespace std;

int add2int(int &x, int &y) //the argument is the starting address of an integer
{
    x = y + y;
    y = y + 10;
    return x; 
}

int main()
{
    int x, y, z; 
    
    x = 3; 
    y = 5; 
    
    cout << "x: " << x << "      y: " << y << endl;
    
    z = add2int(x, y);
    
    cout << "x: " << x << "     y: " << y << "    z: " << z << endl;

    return 0;
}

