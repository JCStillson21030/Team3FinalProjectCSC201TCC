/******************************************************************************
Jonathon Stillson CSC201 CW 
3. Passing a reference and changing the value
*******************************************************************************/
#include <iostream>
#include <ctime> 
using namespace std;

void getSeconds(unsigned long *par);

int main()
{
    unsigned long sec; 
    getSeconds( &sec );
    
    //print the actual value
    cout << "Number of seconds: " << sec << endl;

    return 0;
}

void getSeconds(unsigned long *par){
    // get the current number of seconds
    *par = time( NULL );
    
    return;
}
