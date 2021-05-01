//15 APR CW Dynamic Memory - The 'new' Keyword
#include <iostream>
using namespace std;

int main(){

    int* ptr1 = new int; //dynamically created int USING 'new'

    *ptr1 = 15;//assigning value to dynamic variable

    cout << *ptr1 << endl;

    int* ptr2 = new int(7);//dynamically created int initialized with value 7
    cout << *ptr2 << endl;
    *ptr2 = *ptr2 + 34;
    cout << *ptr2 << endl;

    float* ptr3 = new float[3];//dynamically created array
    *ptr3 = 1.1; ptr3++;
    *ptr3 = 2.2; ptr3++;
    *ptr3 = 3.3; ptr3++;
    cout << *ptr3 << endl; ptr3--;
    cout << *ptr3 << endl; ptr3--;
    cout << *ptr3 << endl;

    *(ptr3 + 2) = 5.5;
    cout << *(ptr3 + 2) << endl;

    float* ptr4 = new float[3]{1.1, 2.2, 3.3};//dynamic array create and initialize values

    cout << *ptr4 << endl; ptr4++;
    cout << *ptr4 << endl; ptr4++;
    cout << *ptr4 << endl; 

    return 0;
}