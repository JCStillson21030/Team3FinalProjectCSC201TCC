/*15 APR 
3. STRING AS ARRAY OF CHAR
a. ACCESSING INDIVIDUAL ELEMENTS OF A STRING 
*/ 

#include <iostream>
using namespace std;

int main(){
    
    int myArray[8] = {23, 12, 34, 54, 68, 97, 86, 42}; 
    
    int* ptr1 = myArray; // myArray is a pointer to the first element of the array 
                         // myArray[5] means the compiler is doing myArray + 5 
    
    for (int i = 0; i < 8; i++){
        cout << *ptr1 << " ";
        ptr1++;
    }
    cout << endl; 
    
    ptr1 = myArray; 
    cout << ptr1 << endl; // starting address of the array 
    cout << ptr1 + 5 << " " << *( ptr1 + 5) << endl; // address and value of the 6th element in the array 
    
    return 0;
}