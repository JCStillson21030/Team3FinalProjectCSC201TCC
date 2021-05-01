//15 APR CW Dynamic Memory - The 'new' Keyword
#include <iostream>
using namespace std;

int main(){

    int* ptr1 = new int; //dynamically created int USING 'new'

    *ptr1 = 15;//assigning value to dynamic variable

    cout << *ptr1 << endl;

    int a = -5;
    if (a > 0){
        int x; //static
    }
    else{
        int* ptr2 = new int;//dynamic
    }

    return 0;
}