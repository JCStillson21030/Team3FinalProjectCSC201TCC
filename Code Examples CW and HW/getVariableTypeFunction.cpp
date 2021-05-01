/******************************************************************************
Jonathon Stillson CSC201 HW8 Problem 3 
Modify the get_type function to work for negative numbers as well. 
It should work for the following examples in addition to the examples in various.txt:
-145
-.632
-37.96
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int getNumLines(string);
void readFile(string, string[], int);
int getType(string);

int main(){

    int arrSize = getNumLines("various.txt"); 

    string fArray[arrSize];

    readFile("various.txt", fArray, arrSize);

    for (int i = 0; i < arrSize; i++){
        cout << "Line # " << i + 1 << ": '" << fArray[i] << "' is a ";
        if (getType(fArray[i]) == 0) cout << " string. ";
        else  if (getType(fArray[i]) == 1 ) cout << " INTEGER.  ";
        else if (getType(fArray[i]) == 2 ) cout << " FLOAT. ";
        else cout << " NEGATIVE.";
        cout << endl;
    }

    cout << endl;

    return 0;
}

int getNumLines (string fName){

    string fLine;
    int lineCount = 0;

    ifstream fVarious;
    fVarious.open(fName);

    while (!fVarious.eof()){

        getline( fVarious, fLine);

        lineCount++;
    }

    fVarious.close();

    cout << "Done counting the lines in the file." << endl;
    return lineCount;
}

void readFile(string fName, string fArray[], int arrSize){

    ifstream fVarious;
    fVarious.open(fName);

    for (int i = 0; i < arrSize; i++) {
        getline ( fVarious, fArray[i]);

    }

    fVarious.close();
    cout << "Done reading the file into the data structure." << endl;
}

int getType(string fLine)
{
    int getType (string fLine);
    int typeInt;
    bool hasPeriod = false;
    bool hasNegative = false;

    for (int i = 0; i < fLine.size(); i++)
    {
        if (fLine[i] == 45)
        {
            hasNegative = true;
            continue;
        }
        if (fLine[i] == 46)
        {
            hasPeriod = true;
            continue;
        }

        if ((fLine[i] < 48) || (fLine[i] > 57))
        {
            return 0;
        }
    }

    if (hasNegative)
    return 3;
    else if (hasPeriod)
    return 2;
    else
    return 1;
}