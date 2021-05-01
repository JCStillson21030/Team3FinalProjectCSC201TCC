/******************************************************************************
Jonathon Stillson CSC201 CW 30MAR
1. Passing by reference example
*******************************************************************************/
#include <iostream>
using namespace std;

void my_fnc(int x){ // the argument is the starting address of an integer
    x = 20;
}

int main(){
    int x = 10;
    my_fnc(x);
    cout << "New value of x is " << x; 
    
    return 0;
}

