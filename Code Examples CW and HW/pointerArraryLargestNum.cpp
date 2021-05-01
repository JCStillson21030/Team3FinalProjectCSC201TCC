/******************************************************************************
Jonathon Stillson CSC201 HW9 28MAR21
Write a C++ program that creates an integer array of size 'n'. The program will
ask the user to input the value of 'n', and each value in the array. Then the 
program finds and reports the largest integer. The program should use only 
pointers to search through the array. 
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
    
    for(int i = 1; i < *intPtr1; ++i){
        if(foo[0] < foo[i])
            foo[0] = foo[i];
    }
    
    cout << "Largest element in the array: " << foo[0] << endl;
    
    cout << "Thank you for using the array program! ";

    return 0;
}
