/******************************************************************************
Jonathon Stillson CSC201 CW 23FEB
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    string fName = "numbers.txt";

    ifstream myInpFile;
    string myLine;
    
    string userInp;
    int lineCount = 0;
    
    myInpFile.open (fName);
    while (!myInpFile.eof()){
        getline (myInpFile, myLine);
        lineCount++;
    }
    
    myInpFile.close();
    
    int myArray[lineCount];
    
    myInpFile.open (fName);
    
    for (int i = 0; i < lineCount; i++){
        myInpFile >> myArray[i];
    }
    
    myInpFile.close();
    
    for (int i = 0; i < lineCount; i++){
        cout << myArray[i] << " | ";
    }
    
    return 0;
}
