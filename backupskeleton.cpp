/**********************************************************************
CSC 201 Final - Group Project -- Linked List Person Struct w/functions
Program MUST INCLUDE: One File, One Function, One Struct, One Pointer
One Array, One Header File. ALL PRIMARY FUNCTIONS COMPLETED
**********************************************************************/

//Includes and Namespace
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//end includes 

//Struct Declaration --- Remember that the word Person will always be capitalized
struct Person{

    string pname; //names in file are saved as First Last
    long SSN; //9 digit number --- dont forget to use 'stol'
    char gender; //single letter char
    string DOB; //format as yyyy/mm/dd
    float height; //format as XX.XX --- don't forget to use 'stof'
    float weight;  //format as XXX.XX --- don't forget to use 'stof'
    long mSSN; //9 digit number --- dont forget to use 'stol'
    long fSSN; //9 digit number --- dont forget to use 'stol'

    //Connect struct to linked list using the next pointer
    Person* next; 
};

//Welcome and goodbye message modules
void show_welcomeMsg(){

    cout << "Welcome to the Team 3 CSC201 Final Program." << endl;
    cout << "Created by: Jonathon Stillson, Marc Bruno, Jamin White, Brandon Byrd, and Brandon Burns" << endl;

};

void show_goodbyeMsg(){

    cout << "Thank you for using the Program." << endl;
    cout << "BMannyB, JasJag, Navelfuzz, Burb, and Junki wish you well ;) " << endl;

};
//End greeting and salutation modules

//Funtion Prototypes ------------------------------

//Print List Prototype
void print_PersonList(Person*);                                 //Utility Function

//Populate Linked List Prototype from people.txt
//Person* populateList(Person*);                                  //Utility Function

//Node Swap
struct Person* swapPerson(struct Person*, struct Person*);      //Utility Function

//User Input
int userInput();                                                //Utility Function

//Menu Function which will automatically display
bool menuDisplay(bool, Person*);                                             //Utility and Information Function

//Node Counter 
int nodeCount(Person*);                                         //Utility Function

//------------------------------Menu Option Prototypes------------------------------//
//Sort by SSN
Person* sortSSN(struct Person**);                               //Menu Option 1

//Remove a person
Person* removePerson(Person**);                                 //Menu Option 2

//Add a new person
Person* addPerson(Person**);                                    //Menu Option 3

//Add a supplementary file containing at least 5 people -- supplemental.txt
Person* addSupplemental(Person**);                              //Menu Option 4

//Edit a Person
void editPerson(Person*);                                       //Menu Option 5

//Display persons eligible for Social Security (Over 65)
void over65(Person*);                                           //Menu Option 6

//Display all persons at high risk for cardiovascular disease (BMI 27 and higher)
void highBMI(Person*);                                          //Menu Option 7

//Display male:female ratio per 1000 
void theRatio(Person*);                                         //Menu Option 8

//Find Parents of person
void findParents(Person*);                                      //Menu Option 9

//Find children of person
void findChildren(Person*);                                    //Menu Option 10

//Find all siblings of a person
void findSiblings(Person*);                                    //Menu Option 11

//Find extended family of a person
void findExtendedFamily(Person*);                              //Menu Option 12
//---------------------------------------------------------------------------------//

//Main Driver
int main(){
    //welcome message function call
    show_welcomeMsg();

    //declaring variables
    bool quit = false;
    //end variable declarations

    //initialize struct pointers/linked list Person* is the node 
    Person* head = new Person; //independent person
    head -> next = NULL; //NULL == end of list

    Person* current = head;
    Person* newPerson;
    //end linked list head creation

    //Read File and begin the linked list
    string fLine;
    int pcount = 0;
    ifstream peopleFile;
    peopleFile.open("people.txt"); 
    
    while (!peopleFile.eof()){
        
        getline(peopleFile, fLine); 
        current -> pname = fLine;
        getline(peopleFile, fLine); 
        current -> SSN = stol(fLine);
        getline(peopleFile, fLine); 
        current -> gender = fLine[0];
        getline(peopleFile, fLine); 
        current -> DOB = fLine;
        getline(peopleFile, fLine); 
        current -> height = stof(fLine);
        getline(peopleFile, fLine); 
        current -> weight = stof(fLine);
        getline(peopleFile, fLine); 
        current -> mSSN = stol(fLine);
        getline(peopleFile, fLine); 
        current -> fSSN = stol(fLine);
        
        newPerson = new Person; // independent person 
        current -> next = newPerson; // linking persons 
        current = newPerson; 
        pcount++;
    }
    
    peopleFile.close(); 
    current = head; 
    Person* prevPerson ;  

    while (current -> next != NULL){  // (current != null) vs. (current->next != NULL)
        prevPerson = current;
        current = current->next;
    } 
    
    prevPerson->next = NULL; 
    delete newPerson; 
    
    current = head; 
    
    // display 
    while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->mSSN << " | "  << current->fSSN << " | " <<  endl ;
        current = current->next; 
    }
    
    cout << pcount << endl;
    current = head; 
    cout << endl;

    //standard main functions that will be used without user input
    
    //Menu Function
    while(quit == false && cin){
        quit = menuDisplay(quit, head);
    }
    //goodbye message function call
    show_goodbyeMsg();

    return 0;
}

//---------------------------------------------Function Definitions--------------------------------------------//

//Print List Function Definition
void print_PersonList(Person* head){
    
    Person* current = head;

    cout << "Here is the Linked List of people." << endl;

     while(current != NULL){
        cout << current -> pname << " | "
             << current -> SSN << " | "
             << current -> gender << " | "
             << current -> DOB << " | "
             << current -> height << " | "
             << current -> weight << " | "
             << current -> mSSN << " | "
             << current -> fSSN << " | "
             << endl;
        current = current -> next;
    }
    cout << endl;  
}
//Populate Linked List from people.txt Function definition
/*Person* populateList(){

    return 0;
}*/
//Node Swap Function Definition
struct Person* swapPerson(struct Person* nodeOne, struct Person* nodeTwo){
    struct Person* temp = nodeTwo -> next;
    nodeTwo -> next = nodeOne;
    nodeOne -> next = temp;

    return nodeTwo;
}
//User input funciton Definiton
int userInput(){
    return 0;
}
//Menu Display function Definiton
bool menuDisplay(bool quit, Person* head){

    int choice = 0;
    
    bool dontQuitMenu = true;

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
    cout << " 13) Secret Function." << endl;
    cout << " 99) Repeat Menu." << endl;

//---------------------------------

    while(cin && dontQuitMenu == true){

        cout << "Enter numeric option or anything else to exit. (99 to display menu again)." << endl;
        int userInp;
        cin >> userInp;
        choice = userInp;

        switch(choice){
             
            case 1:

                cout << "Function 1: Display Persons in Ascending SSN Order." << endl;

                sortSSN(&head);
                print_PersonList(head);

                break;

            case 2: 

                cout << "Function 2: Remove Person (User Input SSN)." << endl;

                cin.clear();

                print_PersonList(head);
                head = removePerson(&head);
                print_PersonList(head);

                break;

            case 3: 

                cout << "Function 3: Add New Person." << endl;

                addPerson(&head);
                print_PersonList(head);

                break;

            case 4: 

                cout << "Function 4: Add Persons from Supplemental File." << endl;
                                
                addSupplemental(&head);
                sortSSN(&head);
                print_PersonList(head);

                break;

            case 5: 

                cout << "Function 5: Edit Person." << endl;

                print_PersonList(head);
                editPerson(head);
                sortSSN(&head);
                print_PersonList(head);

                break;

            case 6:

                cout << "Function 6: Display All Persons Eligible for Social Security (Over Age 65)." << endl;

                over65(head);
                
                break;

            case 7: 

                cout << "Function 7: Display All Persons at High Risk of Cardiovascular Disease (BMI 27 and higher)." << endl;

                highBMI(head);

                break;

            case 8:

                cout << "Function 8: Display the Male to Female Ratio in the County (females per thousand males)." << endl;

                theRatio(head);
                break;

            case 9:

                cout << "Function 9: Find the Parents of a Person (User Input SSN)." << endl;

                findParents(head);
                break;

            case 10: 

                cout << "Function 10: Find all the Children of a Person (User Input SSN)." << endl;

                findChildren(head);

                break;

            case 11:

                cout << "Function 11: Find all Siblings of a Person (User Input SSN)." << endl;

                findSiblings(head);

                break;

            case 12:

                cout << "Function 12: Find all Uncles, Aunts, Nephews and Nieces of a Person (User Input SSN)." << endl;

                findExtendedFamily(head);

                break;

            case 13: 

                cout << "Function 13: The Sauce" << endl;

                //incomplete

                break;

            case 99:

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
                cout << " 13) Secret Function." << endl;
                cout << " 99) Repeat Menu." << endl;

                break;
            
            default: 

                cout << "Goodbye." << endl;

                return dontQuitMenu;
        }
    }
    return dontQuitMenu;
}

//Node Count function Definition 
int nodeCount(Person* head){
    Person* temp = head;

    int nodeCount = 0;

    while(temp != NULL){
        nodeCount++;
        temp = temp -> next;
    }

    return nodeCount;
}
//------------------------------------------Menu Option Function Definitions-------------------------------------//

//Sort by SSN 
Person* sortSSN(struct Person** head){                                                      //Menu Option 1
    struct Person** headPointer;
    int PersonCount = nodeCount(*head);

    bool sorted = false,
        done = false;
    
    for(int i = 0; i <= PersonCount; i++){
        headPointer = head;

        for(int j = 0; j < (PersonCount - i - 1); j++){
            struct Person* nodeOne = *headPointer;
            struct Person* nodeTwo = nodeOne -> next;

            if(nodeOne -> SSN > nodeTwo -> SSN){
                *headPointer = swapPerson(nodeOne, nodeTwo);
                sorted = true;
                done = true;
            }
            headPointer = &(*headPointer) -> next;
        }
        if(done == false){
            sorted = true;
        }
    }
    return *head;
}
//Remove Person 
Person* removePerson(Person** head){                                                        //Menu Option 2

    bool keyFound = false;
    
    string currentLine;

    cin.ignore();

    cout << "Enter the SSN of the person you would like to delete: " << endl;

    getline(cin, currentLine);
    long key = stol(currentLine);

    Person* temp = *head;
    Person* prev = NULL;

    if(temp != NULL && temp -> SSN == key){
        *head = temp -> next;
        delete temp;
    } else{
        while(temp != NULL && temp -> SSN != key){
            prev = temp;
            temp = temp -> next;
            keyFound = true;
        }
    }

    if (temp == NULL){
        cout << "Entered SSN was not found." << endl;
        keyFound = false;
        cin.ignore();
        
        return *head;
    }

    prev -> next = temp -> next;
    delete temp;

    cout << "Deletion completed." << endl;
    cout << "Person " << temp -> SSN << " deleted." << endl;

    return *head;
}

//Add Person
Person* addPerson(Person** head){                                                           //Menu Option 3
    string usrInp;

    cin.ignore();

    int count = 0;

    Person* usrInpPerson = new Person;

    //entering information

    cout << "Enter Name to Add (Format: First Last): ";
    getline(cin, usrInp);
    usrInpPerson -> pname = usrInp;
    cout << "Enter SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    usrInpPerson -> SSN = stol(usrInp);
    cout << "Enter Gender of Person (Format: M/F Case Sensitive): ";
    getline(cin, usrInp);
    usrInpPerson -> gender = usrInp[0];
    cout << "Enter DOB of Person (Format: yyyy/mm/dd): ";
    getline(cin, usrInp);
    usrInpPerson -> DOB = usrInp;
    cout << "Enter Height of Person (Format: XX.XX): ";
    getline(cin, usrInp);
    usrInpPerson -> height = stof(usrInp);
    cout << "Enter Weight of Person (Format: XXX.XX): ";
    getline(cin, usrInp);
    usrInpPerson -> weight = stof(usrInp);
    cout << "Enter Mother SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    usrInpPerson -> mSSN = stol(usrInp);
    cout << "Enter Father SSN of Person (Format: XXXXXXXXX): ";
    getline(cin, usrInp);
    usrInpPerson -> fSSN = stol(usrInp);

    Person* current = *head;

    struct Person** headPointer;

    headPointer = head;

    while(current -> next != NULL){
        if(current -> SSN < usrInpPerson -> SSN){
            if(current -> next -> SSN > usrInpPerson -> SSN){
                Person* prev = current;
                usrInpPerson -> next = prev -> next;
                prev -> next = usrInpPerson;
                break;
            }
        } else{
            usrInpPerson -> next = (*headPointer);
            (*headPointer) = usrInpPerson;
            break;
        }
        current = current -> next;
    }
    if(current -> next == NULL){
        usrInpPerson -> next = NULL;
        current -> next =usrInpPerson;
    }
    cout << "New Person has been added to the list!" << endl;
    cout << "Person " << usrInpPerson -> SSN << " added." << endl;
    return *head;
}

//Add Supplemental File
Person* addSupplemental(Person** head){                                                     //Menu Option 4
    Person* current = *head; 

    while (current -> next != NULL) {
        current = current -> next;
    } 
    
    ifstream suppFile;
    suppFile.open("supplemental.txt");

    string suppLine;

    while (!suppFile.eof()) { 
        
        Person* newPerson = new Person;
        current -> next = newPerson;    
        current = newPerson;
        
        getline(suppFile, suppLine);
        current -> pname = suppLine;
        
        getline(suppFile, suppLine);
        current -> SSN = stol(suppLine);
                
        getline(suppFile, suppLine);
        current -> gender = suppLine[0]; 
        
        getline(suppFile, suppLine);
        current -> DOB = suppLine; 
    
        getline(suppFile, suppLine);
        current -> height = stof(suppLine);

        getline(suppFile, suppLine);
        current -> weight = stof(suppLine);
    
        getline(suppFile, suppLine);
        current -> mSSN = stol(suppLine);

        getline(suppFile, suppLine);
        current -> fSSN = stol(suppLine);
    }
    
    suppFile.close();
    
    current = *head;
  
    cout << "Bulk addition operation successful!" << endl;
    
    cout << "Updating database..." << endl;
    
    return *head;
}
//Edit Person
void editPerson(Person* head){                                                              //Menu Option 5
    Person* current{head};

    long editSSN{0};

    string usrInp;
    string newData{""};

    cin.ignore();

    cout << "Enter the SSN of the Person you would like to edit: ";
    getline(cin, usrInp);

    editSSN = stol(usrInp);

    while(current -> next != NULL){
        if(current -> SSN == editSSN){
            cout << "SSN is: " << current -> pname << endl;
            cout << "Edit initialized. Enter 0 to keep orginial information" << endl;

            cout << "Enter new name: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> pname = newData;
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new SSN: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> SSN = stol(newData);
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new Gender: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> gender = newData[0];
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new DOB: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> DOB = newData;
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new height: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> height = stof(newData);
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new weight: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> weight = stof(newData);
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new Mother SSN: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> mSSN = stol(newData);
            } else{
                cout << "Keeping originial information" << endl;
            }
            cout << "Enter new Father SSN: ";
            getline(cin, newData);
            if(newData[0] != '0'){
                current -> fSSN = stol(newData);
            } else{
                cout << "Keeping originial information" << endl;
            }
        }
        current = current -> next;
    }
    cout << "Editing Complete" << endl;
}

//Eligible for Social Security, Over the age of 65
void over65(Person* head){                                                          //Menu Option 6
    cout<< "The People Eligible for Social Security are :" << endl << endl;
    Person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
    Person* current = head;
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
//High BMI, at risk for cardiovascular disease
void highBMI(Person* head){                                                         //Menu Option 7
    float BMI;
    
    Person* current = head;

    Person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
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
//Ratio of Men to Women per 1000
void theRatio(Person* head){                                                        //Menu Option 8
    int m = 0;
    int f = 0;
    Person* current = head;
    while(current != NULL)
    {
        if(current->gender == 'M')
        {
           m++;
        }
        else f++;
        current = current->next;
    }
    
    cout << m << endl;
    cout << f << endl;
    float x = f;
    float y = m;
    float answer = ((x / y) * 1000);
    cout << "The male to female ratio for every 1000 males to 1 female is: " << answer << ":1000" << endl;
}
//Find Parents
void findParents(Person* head){                                                     //Menu Option 9
    string personname;
    long personSSN;
    long momSSN;
    long dadSSN;
    Person* current = head;

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
//Find Children
void findChildren(Person* head){                                                    //Menu Option 10
    string kidname;
    string parentname;
    long personSSN;
    Person* current = head;

    Person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
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
//Find Siblings
void findSiblings(Person* head){                                                    //Menu Option 11
    Person* current = head;
    
    Person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
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
//Find Extended Family
void findExtendedFamily(Person* head){                                              //Menu Option 12
    
    Person* current = head;
    Person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; long temp7; long temp8;
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


































