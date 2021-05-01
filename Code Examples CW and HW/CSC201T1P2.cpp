//CSC201 Test 1 Problem 2 a? 
//Write a program to read a file and store the lines into an array.
//a. extend the program to delete a specific line from a file.
#include <iostream>
#include <string> 
#include <fstream>
using namespace std;

int main(){

    string fLine;
    int lineCount = 0;

    ifstream fInp;
    fInp.open("lines.txt");

    while (!fInp.eof()){
        getline( fInp, fLine);
        lineCount++;
        cout << lineCount << ": " << fLine << endl;
    }

    fInp.close();
    cout << lineCount << endl;

    string myStrArray[lineCount];

    fInp.open("lines.txt");
    for (int i = 0; i < lineCount; i++){
        getline(fInp, myStrArray[i]);
    }

    cout << "Please enter a line number to delete(1 to " << lineCount << "): ";
    getline(cin, fLine);
    int userLine = stoi(fLine);
    ofstream fOut;
    fOut.open("lines.txt");

    for (int i = 0; i < lineCount; i++){
        if (i + 1 != userLine){
            fOut << myStrArray[i] << endl;
        } 
    }
    fOut.close();

    cout << "Done editing the file." << endl;

    return 0;
}