/******************************************************************************
Jonathon Stillson CSC201 CW 18FEB
*******************************************************************************/
#include <iostream>
#include <array>
using namespace std;

int main()
{
    cout<<"Welcome to the largest interager in array program "<<endl<<endl;

    int myArray[8] = {32, 46, 12, 75, 53, 84, 66, 97}; // 97

    cout<<"This is the array: "<<endl;
    for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
        cout<< myArray[i] << " | ";
    }
    cout << endl;

    int tmp;

    //BUBBLE SORT 
    for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
        for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
            if(myArray[i] < myArray[i - 1]){
                tmp = myArray[i];
                myArray[i] = myArray[i - 1];
                myArray[i - 1] = tmp;
            }
        }
    }
    // END BUBBLE SORT 

    cout<<"This is the array sorted ASC: "<<endl;
    for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
        cout<< myArray[i] << " | ";
    }
    cout << endl;

    return 0;
}