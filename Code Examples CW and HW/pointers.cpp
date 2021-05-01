/******************************************************************************
Jonathon Stillson CSC201 CW 25MAR21
Pointers
*******************************************************************************/
#include <iostream>
using namespace std;

int main(){

    int x = 124;
    int y = 356;

    int* intPtr1; //declaring a int pointer
    intPtr1 = &x; // assign address of x to intPtr1:  now the pointer is referenced

    cout << "x: " << x << " intPtr1: " << intPtr1 << endl;

    int z = *intPtr1; //de-referencing pointers

    cout << "z: " << z << " *intPtr1:" << *intPtr1 << endl;

    intPtr1 = intPtr1 + 2; // operations with refereced pointer
                 // adding 1 to an int pointer means it now points to the next integer in memory

    cout << "y: " << y << " *intPtr1: " << *intPtr1 << endl;

    z = *intPtr1 / 2; // operations with de-referenced pointers
    cout << "z: " << z << " *intPtr1: " << intPtr1 << endl;

    int myArray[6] = {21, 34, 43, 65, 87, 99};

    int* arrPtr = myArray;

    cout << "arrPtr: " << arrPtr << "  *myArray: " << *myArray << endl; //shows first element in array

    arrPtr = arrPtr + 2;
    cout << "arrPtr: " << arrPtr << "  *arrPtr: " << *arrPtr << endl;  //shows second element in array
    // difference of location 2 sets of 4

    return 0;
}