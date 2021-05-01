/******************************************************************************
Jonathon Stillson CSC201 HW 6 
WRITE A PROGRAM THAT TAKES SIX PERSONS , AND LISTS THEM IN:
A) ASCENDING ORDER OF HEIGHT , AND B) DESCENDING ORDER OF WEIGHT
USE struct PERSON from the classwork. The data file should have 8 lines per 
person to match the struct. The data file should have at least 6 persons 
(at least 48 lines in all). 
*******************************************************************************/
#include <iostream>
#include <fstream>
using namespace std;
struct person{

    string pname;
    long SSN;

    char gender;
    string DOB;

    float height;
    float weight;

    string fName;
    string mName;
};

int main()
{
    person Persons[6]; int pcount = 0; string fLine;

    ifstream people;
    people.open("people.txt");

    while(!people.eof()){

    getline( people, fLine);
    Persons[pcount].pname = fLine;
    getline( people, fLine);
    Persons[pcount].SSN = stol(fLine);
    getline( people, fLine);
    Persons[pcount].gender = fLine[0];
    getline( people, fLine);
    Persons[pcount].DOB = fLine;
    getline( people, fLine);
    Persons[pcount].height = stof(fLine);
    getline( people, fLine);
    Persons [pcount].weight = stof(fLine);
    getline( people, fLine);
    Persons[pcount].fName = fLine;
    getline( people, fLine);
    Persons[pcount].mName = fLine;

     pcount++;
    }
    cout << "Here is Persons Height in ascending order: " << endl << endl;
    
    float tmp1;
    string tmp2;
    ofstream myOpFile;
    
    //bubble sort
    for(int j = 0; j < pcount; j++)
    {
        for (int i = 1; i < pcount; i++)
        {
            if (Persons[i].height < Persons[i - 1].height)
            {
                tmp1 = Persons[i].height;
                Persons[i].height = Persons[i - 1].height;
                Persons[i - 1].height = tmp1;

                tmp2 = Persons[i].pname;
                Persons[i].pname = Persons[i - 1].pname;
                Persons[i - 1].pname = tmp2;
            }
        }
    }
    //end bubble sort
    people.close();
    
     for (int i = 0; i < pcount; i++)
     {
        cout << Persons[i].pname << " | "
        << Persons[i].height << " | " << endl<<endl;
     }
    // people.close();

    return 0;