/******************************************************************************
Jonathon Stillson CSC201 CW 25MAR21
2. Binary Search
*******************************************************************************/
#include <iostream>
using namespace std;

int main(){
    
    const int ARR_SIZE = 8;
    
    int myArray[ARR_SIZE] = {21, 54, 78, 66, 43, 69, 82, 96};
    
    //sort the array 
    int tmp;
    for (int i = 1; i < ARR_SIZE; i++){
        for (int j = 1; j < ARR_SIZE; j++){
            if (myArray[j] < myArray[j - 1]){
                tmp = myArray[j];
                myArray[j] = myArray[j - 1];
                myArray[j - 1] = tmp;
            }
        }
    }
    cout << "Array: " << endl;
    for (int i = 0; i < ARR_SIZE; i++) cout << myArray[i] << " | ";
    cout << endl;
    
    int searchNum;
    
    while (true){
        cout << "Please enter the number to search (type 0 to quit): ";
        cin >> searchNum;
        if (searchNum == 0) break;
        bool isfound = false; int L; int R; int indx;
        L = 0;
        R = ARR_SIZE-1;
        
        while (L <= R){
            indx = (L + R) / 2;
            if (myArray[indx] == searchNum) {isfound = true; cout << " Found at position " << indx + 1 << ". " << endl; break;}
            if (myArray[indx] < searchNum) L = indx + 1;
            if (myArray[indx] > searchNum) R = indx - 1;
        }
        //end of binary search routine
        if (!(isfound)) cout << "Not found in the array." << endl;
    }
    
    return 0;
}