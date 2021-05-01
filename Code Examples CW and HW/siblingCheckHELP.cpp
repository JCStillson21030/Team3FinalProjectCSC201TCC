#include <iostream>  // console input and output.
#include <fstream>   // file input and output.
#include <string>    // string related function templates.
using namespace std; // global declaration of prefix "std"
struct person
{
    string pname;     // person's name.
    long SSN;         // social security number. It's a 'long' because our SSN numbers go above the max 'int' limit.
    
    char gender;      // person's gender.
    string DOB;       // "date of brith".
    
    float height;     // person's height.
    float weight;     // person's weight.
    
    string father;    // father's name.
    long fName;       // father's SSN.
    
    string mother;    // mother's name.
    long mName;       // mother's SSN.
};

float get_RBMI(int, int, person[]); // function prototype for calculating RBMI.

int main()
{
    // function opening.
    cout << "Hello! Welcome to the same parent and child finding program. The current list of people and their information are: ";
    cout << endl << endl;
    string fName = "fauxPerson.txt";  string fLine; // file name and file lines are declared.
    
    int totalcount = 0;
    int linecount = 0;                              // obtains the amount of lines in the file.    
    ifstream fauxPerson;                            // fauxPerson opens any file we choose. 
    fauxPerson.open(fName);                         // opens the text file "moviestars.txt".
    
    while(!fauxPerson.eof())    
    {
        getline(fauxPerson, fLine);
        linecount++;
        if (linecount == 10)
        {
            linecount = 0;
            totalcount++;
        }
    }
    fauxPerson.close();
    person client[totalcount]; 
    int pcount = 0; 
    
    fauxPerson.open(fName);
    while(!fauxPerson.eof()) // obtains the peoples' info from the file.
    {
    getline(fauxPerson, fLine); client[pcount].pname = fLine;
    
    // getline converts text from the file to a string. 'Stol' converts the string to a long data type.
    getline(fauxPerson, fLine); client[pcount].SSN = stol(fLine);
    
    getline(fauxPerson, fLine); client[pcount].gender = fLine[0];
    getline(fauxPerson, fLine); client[pcount].DOB = fLine;
    
    // getline converts text from the file to a string. 'Stof' converts the string to a float data type.
    getline(fauxPerson, fLine); client[pcount].height = stof(fLine);
    
    getline(fauxPerson, fLine); client[pcount].weight = stof(fLine);
    getline(fauxPerson, fLine); client[pcount].father = fLine;
    getline(fauxPerson, fLine); client[pcount].fName = stol(fLine);
    getline(fauxPerson, fLine); client[pcount].mother = fLine;
    getline(fauxPerson, fLine); client[pcount].mName = stol(fLine);

    pcount++; // pcount represents how many people the file has. Increases everytime a person's information is inputted.
    }
    fauxPerson.close();

    for (int i = 0; i < pcount; i++) // displays the current list for the user to see.
    {
        cout << client[i].pname << " | " << client[i].SSN 
        << " | " << client[i].gender << " | " << client[i].DOB << " | " 
        << client[i].height << " inches" << " | " << client[i].weight << " pounds" << " | " 
        << client[i].father << " | " << client[i].fName << " | " 
        << client[i].mother << " | " << client[i].mName << " | " << endl;
    }

    int index1, index2; // indx1 used to store a person's line of information associated with their SSN.
    cout << endl << "The current list of children and their parents are: " << endl;

    for (int i = 0; i < pcount; i++) 
    {
        for(int j = i + 1; j < pcount; j++)
        {
            if ((client[i].fName == client[j].fName || client[i].mName == client[j].mName) 
            && client[i].fName != 0 && client[j].fName != 0 
            && client[i].mName != 0 && client[j].mName != 0)
            {
                index1 = i;
                index2 = j;
                
                cout << "Parents: " << "| " << client[index1].father 
                << " | " << client[index1].mother << " | " << endl;
                
                cout << "Children: " << "| " << client[index1].pname << " | " <<
                client[index1].gender << " | " << client[index2].pname << " | " <<
                client[index2].gender << endl << endl;
                
            }
            
        }
    }
    cout << "Thank you for using this program. Please try it again with new people!";
    return 0;
}