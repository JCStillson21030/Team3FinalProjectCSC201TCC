#include <iostream>
#include <string>
#include <fstream>
using namespace std;


//------------Person Struct-----------
struct person{  // define the UDT 
    
    string pname;
    long SSN; 

    char gender; 
    string DOB;
    
    float height; 
    float weight;
    
    long fSSN;
    long mSSN;
    
    person* next;
//-------------------------------------    
};


void displayPersons(){
    
    int pcount = 0; string fLine; int linecount;

    ifstream people;
    people.open("people.txt");
    
    while(!people.eof())    
    {
        getline(people, fLine);
        linecount++;
    }
    
    people.close();
    person Persons[linecount]; 
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
    Persons[pcount].fSSN = stol(fLine);
    getline( people, fLine);
    Persons[pcount].mSSN = stol(fLine);

     pcount++;
    }

    float tmp2;
    string tmp3;
    ofstream myOpFile;
    //bubble sort
    for(int j = 0; j < pcount; j++)
    {
        for (int i = 1; i < pcount; i++)
        {
            if (Persons[i].SSN < Persons[i - 1].SSN)
            {
                tmp2 = Persons[i].SSN;
                Persons[i].SSN = Persons[i - 1].SSN;
                Persons[i - 1].SSN = tmp2;
                
                tmp3 = Persons[i].pname;
                Persons[i].pname = Persons[i - 1].pname;
                Persons[i - 1].pname = tmp3;
            }
        }
    }
    //end bubble sort
    people.close();

     for (int i = 0; i < pcount; i++)
     {
        cout << Persons[i].pname << " | " << Persons[i].SSN << " | " << Persons[i].gender << " | " << Persons[i].DOB <<
        " | " << Persons[i].height << " | " << Persons[i].weight << " | " << Persons[i].fSSN << " | " << Persons[i].mSSN << " | " << endl << endl;
     }

    
}

void removePerson(){

}

void addPerson(){

}

void addBulk(){

}

void editPerson(){

}

void socialSecurity(){

}

void cardioDisease(){

}

void genderRatio(){

}

void findParents(){

}

void findChildren(){

}

void findSiblings(){

}

void findRelatives(){

}

int main(){

int choice;

cout << "Choose a function." << endl << endl;

//--------------Options------------ 
cout << "  1)  Display persons. " << endl;
cout << "  2)  Remove a person. " << endl;
cout << "  3)  Add a person. " << endl;
cout << "  4)  Add new people in bulk by reading supplementary file.  " << endl;
cout << "  5)  Edit a person. " << endl;
cout << "  6)  Display those eligible for social security (65+). " << endl;
cout << "  7)  Display all persons at high risk for cardiovascular disease. (BMI 27+) " << endl;
cout << "  8)  Display male:female ratio. " << endl;
cout << "  9)  Find parents of a person. " << endl;
cout << " 10) Find children of a person. " << endl;
cout << " 11) Find siblings of a person. " << endl;
cout << " 12) Find uncles, aunts, cousins, nephews, and nieces of a person. " << endl;
//---------------------------------

cin >> choice;

//-------Function List----------

if (choice = 1){
    displayPersons();
}
if (choice = 2){
    removePerson();
}
if (choice = 3){
    addPerson();
}
if (choice = 4){
    addBulk();
}
if (choice = 5){
    editPerson();
}
if (choice = 6){
    socialSecurity();
}
if (choice = 7){
    cardioDisease();
}
if (choice = 8){
    genderRatio();
}
if (choice = 9){
    findParents();
}
if (choice = 10){
    findChildren();
}
if (choice = 11){
    findSiblings();
}
if (choice = 12){
    findRelatives();
}

return 0;
}




