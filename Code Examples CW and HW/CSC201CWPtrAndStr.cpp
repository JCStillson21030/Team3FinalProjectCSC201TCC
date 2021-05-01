/* 15 APR 
3. STRING AS ARRAY OF CHAR
a. ACCESSING INDIVIDUAL ELEMENTS OF A STRING 
*/ 

#include <iostream>
using namespace std;

int main(){
    
    int x = 125; // 92d8, 92d9, 92da, 92db 
    int y = 356; // 92dc, 92dd, 92de, 92df
    
    int* ptr1; // declaring pointer 
    
    ptr1 = &x;  // referencing pointer 
    cout << "ptr1: " << ptr1 << endl;
    
    int d = *ptr1;  // de-referencing pointer
    cout << "d: " << d << endl; 
    
    int f = *ptr1 / 5;  // operation with de-referenced pointer
    cout << "f: " << f << endl; 
    
    ptr1++; // incrementing pointer (operation with pointer) 
    cout << "ptr1: " << ptr1 << endl;  
    
    d = *ptr1;  // de-referencing pointer
    cout << "d: " << d << endl; 
    
    return 0;
}