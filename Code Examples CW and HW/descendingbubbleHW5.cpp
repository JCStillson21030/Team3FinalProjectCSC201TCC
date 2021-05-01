/******************************************************************************
Jonathon Stillson CSC201 HW5
Read a set of numbers from a file named "numbers.txt".
Sort the numbers in DESCENDING order and save them into a new file named 
"numbers_desc.txt". You have to create an array of the right size for the given
set of numbers. Do NOT create arrays of general size such as myArray[100]; 
*******************************************************************************/
#include <iostream>
#include <array>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    ifstream myInpFile;
    myInpFile.open("numbers.txt");

    cout<<"Welcome to the descending order sorter"<<endl<<endl;

    int myArray[8] = {32, 46, 12, 75, 53, 84, 66, 97}; // 97

    cout<<"This is the array: "<<endl;
    for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
        cout<< myArray[i] << " | ";
    }
    cout << endl;

    int tmp;
    ofstream myOpFile;
    myOpFile.open("numbers2.txt", ios::app);
    //BUBBLE SORT 
    for (int j = 0; j < sizeof(myArray) / sizeof(int); j++){
        for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
            if(myArray[i] > myArray[i - 1]){
                tmp = myArray[i];
                myArray[i] = myArray[i - 1];
                myArray[i - 1] = tmp;
            }
        }
    }
    // END BUBBLE SORT 

    cout<<"This is the array sorted DES: "<<endl;
    for (int i = 0; i < sizeof(myArray) / sizeof(int); i++){
        cout<< myArray[i] << " | ";
        myOpFile<<myArray[i]<<endl;
    }
    cout << endl;

    return 0;
}