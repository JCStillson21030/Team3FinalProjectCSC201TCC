// Str as array of char 15APR CW
#include <iostream>
using namespace std;

int main(){

    string str1 = "A string";
    cout << &str1 << endl;
    cout << str1 << endl << endl;

    char str2[] = {'A', ' ', 's', 't', 'r', 'i', 'n', 'g'};
    cout << &str2 << endl;
    cout << str2 << endl << endl;

    char* pc1 = &str1[0];
    cout << *pc1 << " " << *(pc1 + 3) << endl;
    cout << str1[0] << " " << str1[3] << endl << endl;

    char* pc2 = str2;
    cout << *pc2 << " " << *(pc2 + 3) << endl;
    
    cout << str2[0] << " " << str2[3] << endl;

    return 0;
}