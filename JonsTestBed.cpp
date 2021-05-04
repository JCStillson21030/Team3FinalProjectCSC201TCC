/**********************************************************************
CSC 201 Final - Group Project -- Linked List Person Struct w/functions
Program MUST INCLUDE: One File, One Function, One Struct, One Pointer
One Array, One Header File
**********************************************************************/
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

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
};
//the parenthese up here include the entire pointer that is being 'borrowed' from the main()
void displayPersons(person* head){

    cout << "Function 1: Display Persons in Ascending SSN Order." << endl;

    //person* head = new person; // independent person 
    //person* head;
    head->next = NULL; 
    person* current = head; person* newPerson ;
    
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
                current->fSSN = index->fSSN;
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
    return;
};
void removePerson(){
    cout << "Function 2: Remove Person (User Input SSN)." << endl;

    person* head = new person; // independent person 
    head->next = NULL; 
    person* current = head; person* newPerson ;

    long remPerson;
    cout << "Please enter the SSN of the person you would like to remove from the list: ";
    cin >> remPerson;
    
    current = head; person* previous ;  
    while (current->next != NULL){  // (current != null) vs. (current->next != NULL)
        previous = current;
        current = current->next;
    } 
    
    previous->next = NULL; 
    delete newPerson; 
    
    current = head; 

    if(remPerson == head->SSN){
        previous = head;
        head = head->next;
        delete previous;
        return;
    }
    previous = head;
    current = head->next;
    while(current && (remPerson != current->SSN)){
        previous = current;
        current = current->next;
    }
    if(current == 0){
        return;
    }
    previous->next = current->next;
    delete current;

    displayPersons(head);

    return;
};
void addPerson(){
    cout << "Function 3: Add Person." << endl;
    
    person* head = new person; // independent person 
    head->next = NULL; 
    person* current = head; person* newPerson ;

    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    string usrInp;
    cin.ignore();
    int count = 0;
    //Person* current = newPerson;
    cout << "Enter Name to Add (Format: First Last): ";
    getline(cin, usrInp);
    current->pname = usrInp; 
    cout << "Enter SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    current->SSN = stol(usrInp);
    cout << "Enter Gender of Person (Format: M/F Case Sensitive): ";
    getline(cin, usrInp);
    current->gender = usrInp[0];
    cout << "Enter Date of Birth of Person (Format: yyyy/mm/dd): ";
    getline(cin, usrInp);
    current->DOB = usrInp;
    cout << "Enter Height of Person (Format: XX.XX): ";
    getline(cin, usrInp);
    current->height = stof(usrInp);
    cout << "Enter Weight of Person (Format: XXX.XX): ";
    getline(cin, usrInp);
    current->weight = stof(usrInp);
    cout << "Enter the Mother SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    current->mSSN = stol(usrInp);
    cout << "Enter the Father SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    current->fSSN = stol(usrInp);
     /*   
    current->pname = temp2;
    current->SSN = temp;
    current->gender = temp3;
    current->DOB = temp4;
    current->height = temp5;
    current->weight = temp6;
    current->mSSN = temp7;
    current->fSSN = temp8;
    */
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
                current->fSSN = index->fSSN;
                index->fSSN = temp8;
            }  
            index = index->next;  
        }  
        current = current->next;
    }  
    
    displayPersons(head);    
    
    return;
}
void addBulk(){
    cout << "Function 4: Add Bulk." << endl;
}
void editPerson(){
    cout << "Function 5: Edit Person." << endl;
}
void socialSecurity(){
    cout << "Function 6: Display All Persons Eligible for Social Security (Over 65)." << endl;
}
void cardioDisease(){
    cout << "Function 7: Display All Persons at High Risk of Cardiovascular Disease (BMI 27 and higher)." << endl;
}
void genderRatio(){
    cout << "Function 8: Display the Male to Female Ratio in the County (females per thousand males)." << endl;
}
void findParents(){
    cout << "Function 9: Find the Parents of a Person (User Input SSN)." << endl;
}
void findChildren(){
    cout << "Function 10: Find all the Children of a Person (User Input SSN)." << endl;
}
void findSiblings(){
    cout << "Function 11: Find all Siblings of a Person (User Input SSN)." << endl;
}
void findRelatives(){
    cout << "Function 12: Find all Uncles, Aunts, Nephews and Nieces of a Person (User Input SSN)." << endl;
}
//add function for menu
//add function for linked list creation with getlines
//add function for 'switchboard'
void displayMenu(person* head){

//working

lup:
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

int choice;
cin >> choice;

//-------Function List----------

if (choice == 1){
    displayPersons(head); //these parentheses are populated with the variables that are called upon, this will change as we update main()
}
else if (choice == 2){
    removePerson();
}
else if (choice == 3){
    addPerson();
}
else if (choice == 4){
    addBulk();
}
else if (choice == 5){
    editPerson();
}
else if (choice == 6){
    socialSecurity();
}
else if (choice == 7){
    cardioDisease();
}
else if (choice == 8){
    genderRatio();
}
else if (choice == 9){
    findParents();
}
else if (choice == 10){
    findChildren();
}
else if (choice == 11){
    findSiblings();
}
else if (choice == 12){
    findRelatives();
}

    
    char continuation;
    cout << "Would you like to continue? Y/N (Case Sensitive): ";
    cin >> continuation;
    if(continuation == 'Y'){
        goto lup;
    } else
    return;

}
void readFile(person* head){

//working with additional cout for verification


//readfile and getlines should be its own function
    
    //person* head = new person; // independent person 
    head->next = NULL; 
    person* current = head; person* newPerson ;
    
    string fLine;
    ifstream fMovStar;
    fMovStar.open("people.txt"); 
    
    while (!fMovStar.eof()){
        //be sure to copy this this and change fMovStar to cin, for other modules
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
        current->mSSN = stol(fLine);
        getline( fMovStar, fLine); 
        current->fSSN = stol(fLine);
        
        newPerson = new person; // independent person 
        current->next = newPerson; // linking persons 
        current = newPerson; 
        
    }
    
    fMovStar.close(); 
    
    current = head; person* previous ;  
    while (current->next != NULL){  // (current != null) vs. (current->next != NULL)
        previous = current;
        current = current->next;
    } 
    
    previous->next = NULL; 
    delete newPerson; 
    
    current = head; 
    
    // display 
    while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->mSSN << " | "  << current->fSSN << " | " <<  endl ;
        current = current->next; 
    }

    current = head; 
    cout << endl; 

    return;
}



main(){
//the creation of the head for our linked list needs to occur in the main 
//the nodes are created in modules
person* head = new person; // independent person 
    //head->next = NULL; 
    //person* current = head; person* newPerson ;  

    readFile(head);
    displayMenu(head);
    // assign data values 
/*
    //readfile and getlines should be its own function
    string fLine;
    ifstream fMovStar;
    fMovStar.open("people.txt"); 
    
    while (!fMovStar.eof()){
        //be sure to copy this this and change fMovStar to cin, for other modules
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
        current->mSSN = stol(fLine);
        getline( fMovStar, fLine); 
        current->fSSN = stol(fLine);
        
        newPerson = new person; // independent person 
        current->next = newPerson; // linking persons 
        current = newPerson; 
        
    }
    
    fMovStar.close(); 
    //this will be within modules 
    current = head; person* previous ;  
    while (current->next != NULL){  // (current != null) vs. (current->next != NULL)
        previous = current;
        current = current->next;
    } 
    
    previous->next = NULL; 
    delete newPerson; 
    
    current = head; 
    */
    //this not necessesary for the project turn in, all this will be in modules, however it is a took to make sure our main is working
    /*
    while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->mSSN << " | "  << current->fSSN << " | " <<  endl ;
        current = current->next; 
    }

    current = head; 
    cout << endl; 
    */


    /*
lup: //crude loop will be replaced

//the entire menu will be it's own function
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
//function 'choice =='s' will be updated with the switch function
int choice;
cin >> choice;

//-------Function List----------

if (choice == 1){
    displayPersons(head, current, previous); //these parentheses are populated with the variables that are called upon, this will change as we update main()
}
else if (choice == 2){
    removePerson(head, current, previous);
}
else if (choice == 3){
    addPerson(head, current, previous, newPerson);
}
else if (choice == 4){
    addBulk();
}
else if (choice == 5){
    editPerson();
}
else if (choice == 6){
    socialSecurity();
}
else if (choice == 7){
    cardioDisease();
}
else if (choice == 8){
    genderRatio();
}
else if (choice == 9){
    findParents();
}
else if (choice == 10){
    findChildren();
}
else if (choice == 11){
    findSiblings();
}
else if (choice == 12){
    findRelatives();
}

    
    char continuation;
    cout << "Would you like to continue? Y/N (Case Sensitive): ";
    cin >> continuation;
    if(continuation == 'Y'){
        goto lup;
    } else
    */
    return 0;
}