/******************************************************************************
Jonathon Stillson CSC201 HW9 28MAR
Write a C++ program that populates an integer array of size 'n'. The program 
asks the user to input the value of 'n', and creates the array. Then the program
asks the user to enter the value of each element in the array and assigns the 
user input to the elements accordingly. Then the program displays all the values
in the array. The program should only use pointers to populate the values in the
array and display the values in the array.
*******************************************************************************/
#include <iostream>
using namespace std;

int main()
{
    cout << "Welcome to the array program using pointers!" <<endl <<endl;

    int n;
    
    int* intPtr1; //declaring a int pointer
    intPtr1 = &n; // assign address of x to intPtr1:  now the pointer is referenced
    
    cout << "Please enter the size of the array you want to create: ";
    cin >> n;

    int myArray[*intPtr1]; //declare the array specify the data type, the name, the size 
    int* foo = myArray;


    for (int i = 0; i < *intPtr1; i++){
        cout << "Please enter the value of the element " << i + 1 << ": ";
        cin >> foo[i];
    }

    cout <<"This is your array " << endl;
    for (int i = 0; i < *intPtr1; i++){
        cout << "|" << foo[i];
    }

    cout << "|" << endl;

    cout << "Thank you for using the array program! ";

    return 0;
}