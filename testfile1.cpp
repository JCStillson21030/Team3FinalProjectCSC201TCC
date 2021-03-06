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

void displayPersons(person *head, person *current, person *previous){

    cout << "Function 1: Display Persons in Ascending SSN Order." << endl;
    
    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
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
};
void removePerson(person *head, person *current, person *previous){
    cout << "Function 2: Remove Person (User Input SSN)." << endl;
    long remPerson;
    cout << "Please enter the SSN of the person you would like to remove from the list: ";
    cin >> remPerson;

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

    displayPersons(head, current, previous);

    return;
};
void addPerson(person *head, person *current, person *previous, person *newPerson){
    cout << "Function 3: Add Person." << endl;
    
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
    
    displayPersons(head, current, previous);    
    
    return;

}
void addBulk(){
    cout << "Function 4: Add Bulk." << endl;
}

void editPerson(person* head, person *current, person *previous){
    cout << "Function 5: Edit Person." << endl;

    long SSNinput;
    string useredit;
    string edittemp;
    cin.ignore();
    
    string edittemp1, edittemp2;
    
    cout << "Enter the SSN of the desired person to be edited: ";
    cin >> SSNinput;
    
    while(current != NULL)
    {
        if(current->SSN == SSNinput)
        {
            cout << "Enter first name of person: ";
            cin >> edittemp1;
            cout << "Enter last name of person: ";
            cin >> edittemp2;
            edittemp = edittemp1 + " " + edittemp2;
            current->pname = edittemp;
            
            cout << "Enter new height for person: ";
            cin >> edittemp;
            current->height = stof(edittemp);
            
            cout << "Enter new weight for person: ";
            cin >> edittemp;
            current->weight = stof(edittemp);
        }
        current = current->next;
    }
    
    displayPersons(head, current, previous); 
    
}

void socialSecurity(person *head, person *current){
    cout << "Function 6: Display All Persons Eligible for Social Security (Over 65)." << endl << endl;

   

    cout<< "The People Eligible for Social Security are :" << endl << endl;
    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
    {  
        index = current->next;  

        while(index != NULL)
        {  
            if(current->DOB > index->DOB)
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
    
    while(current->next != NULL)
    {
        if( 2021 - stoi(current->DOB.substr(0,4)) >= 65 )
        {
            cout << current->pname << ": Age: " << 2021 - stoi(current->DOB.substr(0,4)) << endl;
        }
        
        current = current->next;
    }
}
void cardioDisease(person* head, person *current, person *previous){
    cout << "Function 7: Display All Persons at High Risk of Cardiovascular Disease (BMI 27 and higher)." << endl;
    
    //BMI = WEIGHT IN KG / (HEIGHT IN M)-SQUARED
    // WIGHT IN KG = WEIGHT IN POUNDS * 0.45 ; HEIGHT IN METERS = HEIGHT IN INCHES * 0.0254
    //Formula: 703 x weight (lbs) / [height (in)]^2
    //cout<<"The BMI of " << mySelf.pname << " is " << ((mySelf.weight) * 0.45) / (((mySelf.height) * 0.0254) * ((mySelf.height) * 0.0254))<<endl;

    float BMI;
    
     person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
    {  
        index = current->next;  

        while(index != NULL)
        {  
            if(current->weight < index->weight)
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
    
    while(current != NULL)      
    {  
        BMI = ((current->weight) * 0.45) / (((current->height) * 0.0254)) * ((current->height) * 0.0254);
         
     if(BMI > 26.99)
        {
            
        cout << "The BMI of " << current->pname << " is " << BMI << endl;
        
        }
        current = current->next;
    }
    current = head;   
}
void genderRatio(person *head, person *current, person *previous){
    cout << "Function 8: Display the Male to Female Ratio in the County (females per thousand males)." << endl;
    
    int m = 0;
    int f = 0;
    
    while(current != NULL)
    {
        if(current->gender == 'M')
        {
           m++;
        }
        else f++;
        current = current->next;
    }
    
    //cout << m << endl;
    //cout << f << endl;
    float x = f * 1000;
    float answer = m / x;
    cout << "The male to female ratio for every 1000 males to 1 female is: " << answer << endl;
    
    //displayPersons(head, current, previous); 
    
}
void findParents(person *head, person *current, person *previous){
    cout << "Function 9: Find the Parents of a Person (User Input SSN)." << endl;
    //only outputs mother
    string personname;
    long personSSN;
    long momSSN;
    long dadSSN;
    
    cout << "Please enter the SSN of the person you want to find the parents of: "; cin >> personSSN;
    
    
    while(current != NULL)
    {
        if(current->SSN == personSSN)
        {
            personname = current->pname;
            momSSN = current->mSSN;
            dadSSN = current->fSSN;
        }
        // 195483298*/
        current = current->next;
    }
    current = head;
    
    
    //mum
    while(current != NULL)
    {
        if(current->SSN == momSSN)
        {
            cout << personname << " has the mother: " << current->pname << endl;
            
        }
        current = current->next;
    }
    current = head;
    
    
    //dad
    while(current != NULL)
    {
        if(current->SSN == dadSSN)
        {
            cout << personname << " has the father: " << current->pname << endl;
            
        }
        current = current->next;
    }
    
    cout << endl;
    
}
void findChildren(person *head, person *current, person *previous){
    cout << "Function 10: Find all the Children of a Person (User Input SSN)." << endl;


    string kidname;
    string parentname;
    long personSSN;


    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
    {  
        index = current->next;  

        while(index != NULL)
        {  
            if(current->DOB > index->DOB)
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

    cout << "Please enter the SSN of the person you want to find the children of: "; cin >> personSSN;

    while(current != NULL)
    {
        if(current->SSN == personSSN)
        {
            parentname = current->pname;
        }
        // 195483298*/
        current = current->next;
    }
    
    current = head;
    
    while(current !=NULL)
    {
        if((current->fSSN == personSSN) || (current->mSSN == personSSN)) 
        {
            kidname = current->pname;
            cout << endl;
            cout << kidname << " || Born: " << current->DOB << " is the kid of: " << parentname;
        }
        // 195483298*/
        current = current->next;
    }
    current = head;
    
    cout << endl;   
}
void findSiblings(person *head, person *current, person *previous){
    cout << "Function 11: Find all Siblings of a Person (User Input SSN)." << endl;


    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
    {  
        index = current->next;  

        while(index != NULL)
        {  
            if(current->DOB > index->DOB)
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
    
    string personname;
    long personSSN;
    long momSSN;
    long dadSSN;
    
    
    cout << "Please enter the SSN of the person you want to find the siblings of: "; cin >> personSSN;
    
    while(current != NULL)
    {
        if(current->SSN == personSSN)
        {
            personname = current->pname;
            momSSN = current->mSSN;
            dadSSN = current->fSSN;
        }
        // 195483298*/
        current = current->next;
    }
    current = head;
    
    while(current != NULL)
    {
        if((((current->mSSN == momSSN) && (current->SSN != personSSN)) || ((current->fSSN == dadSSN) && (current->SSN != personSSN))))
        {
        cout << current->pname << " || Born: " << current->DOB << " is the sibling of: " << personname << endl;
        }
        current = current->next;
    }
    
    
}
void findRelatives(person *head, person *current, person *previous){
    cout << "Function 12: Find all Uncles, Aunts, Nephews and Nieces of a Person (User Input SSN)." << endl;
    
    //----------displays the geezers first----------
    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    while(current != NULL)      // Why does this work when current is not declared/undefined? 
    {  
        index = current->next;  

        while(index != NULL)
        {  
            if(current->DOB > index->DOB)
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
    //----------displays the geezers first^^^----------
    string personname;
    long personSSN;
    long momSSN;
    long dadSSN;
    
    long momsmomSSN;
    long momsdadSSN;
    
    long dadsmomSSN;
    long dadsdadSSN;
    
    long siblingSSN;
    
    long auntuncleSSN;
    
    cout << "Please enter the SSN of the person you want to find the aunts, uncles, nephews, and nieces of: "; cin >> personSSN;
    cout << endl;
    
    while(current != NULL)
    {
        if(current->SSN == personSSN)
        {
            personname = current->pname;
            momSSN = current->mSSN;
            dadSSN = current->fSSN;
        }
        // 195483298*/
        current = current->next;
    }
    current = head;
    
    //----------mum----------
    while(current != NULL)
    {
        if(current->SSN == momSSN)
        {
            momsmomSSN = current->mSSN;
            momsdadSSN = current->fSSN;
        }
        current = current->next;
    }
    current = head;
    
    //----------dad----------
    while(current != NULL)
    {
        if(current->SSN == dadSSN)
        {
            dadsmomSSN = current->mSSN;
            dadsdadSSN = current->fSSN;
        }
        current = current->next;
    }
    current = head;
    
    //----------finds aunts and uncles----------
    while(current != NULL)
    {
        if((((current->mSSN == dadsmomSSN) && (current->SSN != dadSSN)) || ((current->fSSN == dadsdadSSN) && (current->SSN != dadSSN))) || (((current->mSSN == momsmomSSN) && (current->SSN != momSSN)) || ((current->fSSN == momsdadSSN) && (current->SSN != momSSN))))
        {
            auntuncleSSN = current->SSN;
            cout << personname << " has the aunts and uncles (in descending order of age): " << current->pname << " || Born: " << current->DOB << endl;
        }
        current = current->next;
    }
    current = head;
    cout << endl;
    
    //----------finds persons siblings----------
    while(current != NULL)
    {
        if((((current->mSSN == momSSN) && (current->SSN != personSSN)) || ((current->fSSN == dadSSN) && (current->SSN != personSSN))))
        {
        siblingSSN = current->SSN;
        //cout << personname << " has the siblings: " << current->pname << endl;
        }
        current = current->next;
    }
    current = head;
    
    //----------finds nieces and nephews----------
    while(current != NULL)
    {
        if((current->mSSN == siblingSSN) || (current->fSSN == siblingSSN))
        {
            cout << personname << " has the nieces and nephews (in descending order of age): " << current->pname << " || Born: " << current->DOB << endl;
        }
        current = current->next;
    }
    current = head;
    cout << endl;
    
    //----------finds cousins----------
    while(current != NULL)
    {
        if(         (current->mSSN == auntuncleSSN) || (current->fSSN == auntuncleSSN)        )
        {
            cout << personname << " has the cousins (in descending order of age): " << current->pname << " || Born: " << current->DOB << endl;
        }
        current = current->next;
    }
    current = head;
    cout << endl;
}
main(){

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
//---------------------------------
int choice;
cin >> choice;

//-------Function List----------

if (choice == 1){
    displayPersons(head, current, previous);
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
    editPerson(head, current, previous);
}
else if (choice == 6){
    socialSecurity(head, current);
}
else if (choice == 7){
    cardioDisease(head, current, previous);
}
else if (choice == 8){
    genderRatio(head, current, previous);
}
else if (choice == 9){
    findParents(head, current, previous);
}
else if (choice == 10){
    findChildren(head, current, previous);
}
else if (choice == 11){
    findSiblings(head, current, previous);
}
else if (choice == 12){
    findRelatives(head, current, previous);
}

    char continuation;
    cout << "Would you like to continue? Y/N (Case Sensitive): ";
    cin >> continuation;
    if(continuation == 'Y'){
        goto lup;
    } else
    return 0;
}
