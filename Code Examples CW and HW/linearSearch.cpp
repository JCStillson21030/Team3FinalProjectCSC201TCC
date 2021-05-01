/******************************************************************************
Jonathon Stillson CSC201 CW 25MAR 
1. Linear Search
*******************************************************************************/
#include <iostream>
using namespace std;

int main(){
    
    int myArray[8] = {21, 54, 78, 66, 43, 69, 82, 96};
    int searchNum;
    
    cout << "Please enter the number to search: ";
    cin >> searchNum;
    
    for (int i = 0; i < sizeof(myArray); i++){
        if (myArray[i] == searchNum){
            cout << searchNum << " found at position: " << i + 1 << endl;
            return 0;
        }
    }
    
    cout << searchNum << " not found." << endl;
    
    return 0;
}

