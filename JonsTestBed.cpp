#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Person struct declaration module
struct Person{  
    
    string pname;
    long SSN; 

    char gender; 
    string DOB;
    
    float height; 
    float weight;
    
    long mSSN;
    long fSSN;
    
    Person* next;                                         
};

void show_welcomeMsg();

void show_goodbyeMsg();

int user_input();                                   // Utility -- user input

bool menuFunction(bool, Person*);                      // Main menu

Person* populateList(string);                    // Initial dataset

struct Person* swapPerson(struct Person*,          // Utility -- swap nodes
                           struct Person*);

int nodeCount(Person*);                         // Utility

void printPersons(Person*);                    // Utility

Person* sortSSN(struct Person**);                // Option 1

Person* deletePerson(Person**);                    // Option 2

Person* newPerson(Person**);                  // Option 3

Person* addSupplemental(Person**);                   // Option 4

void editPerson(Person*);                      // Option 5

void displaySSEligibility(Person*);                  // Option 6


// End function prototypes








void show_WelcomeMsg(){

}
void show_GoodbyeMSG(){

}

//read file and make list
Person* populateList(string myPeople){

    Person* head = new Person;
    head -> next = NULL;

    Person* current = head;
    Person* newPerson;

    ifstream myPersonFile;
    myPersonFile.open(myPeople);

    string fLine;

    while(!myPersonFile.eof()){

        getline(myPersonFile, fLine);
        current -> pname = fLine;
        getline(myPersonFile, fLine);
        current -> SSN = stol(fLine);
        getline(myPersonFile, fLine);
        current -> gender = fLine[0];
        getline(myPersonFile, fLine);
        current -> DOB = fLine;
        getline(myPersonFile, fLine);
        current -> height = stof(fLine);
        getline(myPersonFile, fLine);
        current -> weight = stof(fLine);
        getline(myPersonFile, fLine);
        current -> mSSN = stol(fLine);
        getline(myPersonFile, fLine);
        current -> fSSN = stol(fLine);
        
        newPerson = new Person;
        current -> next = newPerson;
        current = newPerson;
    }

    myPersonFile.close();

    current = head;

    Person* prevPerson;

    while(current -> next != NULL){
        prevPerson = current;
        current = current -> next;
    }

    prevPerson -> next = NULL;

    delete newPerson;
    
    current = head;

}

//utility usage for counting persons
int nodeCount(Person* head){

    Person* temp = head;

    int nodeCount = 0;

    while(temp != NULL){
        nodeCount++;
        temp = temp -> next;
    }

    return nodeCount;
}

//utitily usage for swap and sort

struct Person* swapPerson(struct Person* nodeOne, struct Person* nodeTwo){
    struct Person* temp = nodeTwo -> next;
    nodeTwo -> next = nodeOne;
    nodeOne -> next = temp;

    return nodeTwo;
}

//Creat new person and add to list
Person* newPerson(Person** head){
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

//sort by ascending SSN 
Person* sortSSN(struct Person** head){
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

//sort by age 65+
void displaySSEligibility(Person* head){
    Person* current{head};

    cout << "Eligible for Social Security: " << endl;

    while(current -> next != NULL){
        if(2021 - stoi(current -> DOB.substr(0,4)) >= 65){ //does the substr need to be 0, 3 ??
            cout << current -> pname << ": Age: " << 2021 - stoi(current -> DOB.substr(0,4)) << endl;
        }
        current = current -> next;
    }
}

//Edit Person
void editPerson(Person* head){
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

//print person nodes
void printPersons(Person* head){

    Person* current = head;

    cout << endl;

    cout << "Here are the people in a linked list: " << endl;

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

//delete person from the list
Person* deletePerson(Person** head){

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

//utility function for the menu selection process
int user_input() {
    
    int inp = 0;
    
    while (cin >> inp) {
        
        return inp;
    } 
}

//menu
bool menuFunction(bool quit, Person* head){

cout << "Choose a function." << endl << endl;

    int choice = 0;
    
    bool dontQuit = true;

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

    while(cin && dontQuit == true){

        cout << "Enter numeric option or anything else to exit." << endl;

        choice = user_input();

        switch(choice){
             
            case 1:

                cout << "Function 1: Display Persons in Ascending SSN Order." << endl;

                sortSSN(&head);
                printPersons(head);

                break;

            case 2: 

                cout << "Function 2: Remove Person (User Input SSN)." << endl;

                cin.clear();

                printPersons(head);
                head = deletePerson(&head);
                printPersons(head);

                break;

            case 3: 

                cout << "Function 3: Add New Person." << endl;

                newPerson(&head);
                printPersons(head);

                break;

            case 4: 

                cout << "Function 4: Add Persons from Supplemental File." << endl;
                //in evanescencev2
                
                head = addSupplemental(&head);
                sortSSN(&head);
                printPersons(head);

                break;

            case 5: 

                cout << "Function 5: Edit Person." << endl;

                printPersons(head);
                editPerson(head);
                printPersons(head);

                break;

            case 6:

                cout << "Function 6: Display All Persons Eligible for Social Security (Over Age 65)." << endl;

                displaySSEligibility(head);

                break;

            case 7: 

                cout << "Function 7: Display All Persons at High Risk of Cardiovascular Disease (BMI 27 and higher)." << endl;

                //incomplete

                break;

            case 8:

                cout << "Function 8: Display the Male to Female Ratio in the County (females per thousand males)." << endl;

                //incomplete
                //in jamins mom
                break;

            case 9:

                cout << "Function 9: Find the Parents of a Person (User Input SSN)." << endl;

                //incomplete
                //in jamins mom
                break;

            case 10: 

                cout << "Function 10: Find all the Children of a Person (User Input SSN)." << endl;

                //incomplete

                break;

            case 11:

                cout << "Function 11: Find all Siblings of a Person (User Input SSN)." << endl;

                //incomplete

                break;

            case 12:

                cout << "Function 12: Find all Uncles, Aunts, Nephews and Nieces of a Person (User Input SSN)." << endl;

                //incomplete

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

                return dontQuit;
        }
    }
    return dontQuit;
}

Person* addSupplemental(Person** head){
    
    string suppLine;
          string fileName = "supplemental.txt";
    
    Person* current = *head; 

    while (current -> next != NULL) {
        current = current -> next;
    } 
    
    ifstream dataFile;
    dataFile.open(fileName);

    while (!dataFile.eof()) { 
        
        Person* newPerson = new Person;
        current -> next = newPerson;    
        current = newPerson;
        
        getline(dataFile, suppLine);
        current -> pname = suppLine;
        
        getline(dataFile, suppLine);
        current -> SSN = stol(suppLine);
                
        getline(dataFile, suppLine);
        current -> gender = suppLine[0]; 
        
        getline(dataFile, suppLine);
        current -> DOB = suppLine; 
    
        getline(dataFile, suppLine);
        current -> height = stof(suppLine);

        getline(dataFile, suppLine);
        current -> weight = stof(suppLine);
    
        getline(dataFile, suppLine);
        current -> mSSN = stol(suppLine);

        getline(dataFile, suppLine);
        current -> fSSN = stol(suppLine);
    }
    
    dataFile.close();
    
    current = *head;
  
    cout << "Bulk addition operation successful!" << endl;
    
    cout << "Updating database..." << endl;
    
    return *head;
}

int main(){

    //Welcome Message
    show_WelcomeMsg();

    //variable declarations
    bool quit = false; //used in some functions (multiple)
    string myPeople = "people.txt"; 

    //end variable declarations

    //initialize struct pointers/linked list
    Person* head = new Person; //independent person
    head -> next = NULL; //NULL equals the end of the list

    //Person* current = head;
    //Person* newPerson;
    //End struct pointers/linked list

    //baseline functions that allow the program to work, getting us to the point of user interaction
    //create list using the struct 
    populateList(myPeople);

    //sort by SSN
    sortSSN(&head);

    //initial print
    printPersons(head);

    //main menu loop
    //is this even necessary?
    while(quit == false && cin){
        quit = menuFunction(quit, head);
    }

    //goodbye
    show_GoodbyeMSG();

    return 0;
    
}
