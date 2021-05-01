//CSC201 Test 1 Problem 3
//Modify the binary search program to sort the array in descending order
//and then search for the given number
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(){

    const int ARR_SIZE = 8;

    int numArray[ARR_SIZE] = {21, 54, 78, 89, 56, 32, 13, 46};

    //sort array
    int tmp;
    for (int i = 1; i < ARR_SIZE; i++){
        for (int j = 1; j < ARR_SIZE; j++){
            if (numArray[j] > numArray[j - 1]){
                tmp = numArray[j];
                numArray[j] = numArray[j -1];
                numArray[j - 1] = tmp;
            }
        }
    }

    cout << "Array: " << endl;

    for (int i = 0; i < ARR_SIZE; i++){
        cout << numArray[i] << " | ";
    }

    cout << endl;

    int searchNum;

    while(true){
        cout << "Please enter the number to search (type 0 to quit): ";
        cin >> searchNum;
        if(searchNum == 0)
        break;
        bool isfound = false;
        int L;
        int R;
        int indx;

        L = 0;
        R = ARR_SIZE - 1;

        while (L <= R){
            indx = (L + R)/2;
            if(numArray[indx] == searchNum){
                isfound = true;
                cout << "Found at position: " << indx + 1 << ". " << endl;
                break;
            }
            if(numArray[indx] > searchNum)
            L = indx + 1;
            if(numArray[indx] < searchNum)
            R = indx - 1;
        }
        //end of binary search routine

        if(!(isfound)) cout << "Not found in the array." << endl;
    }
    cout << endl;
    cout << "Thank you for using the array descending order program" << endl;
    
    return 0;
}