/******************************************************************************
Jonathon Stillson CSC201 HW9 28MAR
Write a program that creates a character array
char * foo = "hello";
and reports the value of foo, *(foo+2), foo[4]
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    char myArray[5] = {'H', 'E', 'L', 'L', 'O'};


    char* foo = myArray;

    cout << foo << endl;

    cout << *(foo + 2) << endl;

    cout << foo[4] << endl;

    return 0;
}

