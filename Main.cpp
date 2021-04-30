#include <iostream>
using namespace std;


//------------Person Struct-----------
struct person{  // define the UDT 
    
    string pName;
    long pSSN; 

    char gender; 
    string DOB;
    
    float height; 
    float weight;
    
    long fSSN;
    long mSSN;
//-------------------------------------    

    person* next;
};


void displayPersons(){
    
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




