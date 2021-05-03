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
    
    long mSSN;
    long fSSN;
    
    person* next;
//-------------------------------------    
};


void displayPersons(){
    
    person* head = new person; // independent person 
    head->next = NULL; 
    
    person* current = head; person* newPerson ;  
    // assign data values 
    string fLine;
    ifstream people;
    people.open("people.txt"); 
    
    while (!people.eof()){
        
        getline( people, fLine); 
        current->pname = fLine;
        getline( people, fLine); 
        current->SSN = stol(fLine);
        getline( people, fLine); 
        current->gender = fLine[0];
        getline( people, fLine); 
        current->DOB = fLine;
        getline( people, fLine); 
        current->height = stof(fLine);
        getline( people, fLine); 
        current->weight = stof(fLine);
        getline( people, fLine); 
        current->mSSN = stol(fLine);
        getline( people, fLine); 
        current->fSSN = stol(fLine);
        
        newPerson = new person; // independent person 
        current->next = newPerson; // linking persons 
        current = newPerson; 
        
    }
    
    people.close(); 
    
    current = head; person* prevPerson ;  
    while (current->next != NULL){  // (current != null) vs. (current->next != NULL)
        prevPerson = current;
        current = current->next;
    } 
    
    prevPerson->next = NULL; 
    delete newPerson; 
    
    current = head;
    
    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    
     
    while(current != NULL)
    {  
        
        index = current->next;  
          
        while(index != NULL)
        {  
            
            if(current->SSN > index->SSN)
            {  
                temp = current->SSN;  
                current->SSN = index->SSN;  
                index->SSN = temp; 
                
                temp2 = current->pname;
                current->pname = index->pname;
                index->pname = temp2;
                
                temp3 = current->gender;
                current->gender = index->gender;
                index->gender = temp3;
                
                temp4 = current->DOB;
                current->DOB = index->DOB;
                index->DOB = temp4;
                
                temp5 = current->height;
                current->height = index->height;
                index->height = temp5;
                
                temp6 = current->weight;
                current->weight = index->weight;
                index->weight = temp6;
                
                temp7 = current->mSSN;
                current->mSSN = index->mSSN;
                index->mSSN = temp7;
                
                temp8 = current->fSSN;
                current->mSSN = index->fSSN;
                index->fSSN = temp8;
                
            }  
            index = index->next;  
        }  
        current = current->next;
    }      

    current = head; 
    
     while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->fSSN << " | "  << current->mSSN << " | " <<  endl ;
        current = current->next; 
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
//First priority will be to program a Linked List within the main for each one of the funtions to refernce. 

person* head = new person; // independent person 
    head->next = NULL; 
    
    person* current = head; person* newPerson ;  
    // assign data values 
    string fLine;
    ifstream fMovStar;
    fMovStar.open("people.txt"); 
    
    while (!fMovStar.eof()){
        
        getline( fMovStar, fLine); 
        current->pname = fLine;
        getline( fMovStar, fLine); 
        current->SSN = stol(fLine);
        getline( fMovStar, fLine); 
        current->gender = fLine[0];
        getline( fMovStar, fLine); 
        current->DOB = fLine;
        getline( fMovStar, fLine); 
        current->height = stof(fLine);
        getline( fMovStar, fLine); 
        current->weight = stof(fLine);
        getline( fMovStar, fLine); 
        current->fSSN = stol(fLine);
        getline( fMovStar, fLine); 
        current->mSSN = stol(fLine);
        
        newPerson = new person; // independent person 
        current->next = newPerson; // linking persons 
        current = newPerson; 
        
    }
    
    fMovStar.close(); 
    
    current = head; person* prevPerson ;  
    while (current->next != NULL){  // (current != null) vs. (current->next != NULL)
        prevPerson = current;
        current = current->next;
    } 
    
    prevPerson->next = NULL; 
    delete newPerson; 
    
    current = head; 
    
    // display 
    while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->fSSN << " | "  << current->mSSN << " | " <<  endl << endl;
        current = current->next; 
    }

    current = head; 
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




