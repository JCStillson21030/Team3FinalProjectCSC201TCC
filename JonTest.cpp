/**********************************************************************
CSC 201 Final - Group Project -- Linked List Person Struct w/functions
Program MUST INCLUDE: One File, One Function, One Struct, One Pointer
One Array, One Header File
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
Person* populateList(Person*);                                  //Utility Function
//Node Swap
struct Person* swapPerson(struct Person*, struct Person*);      //Utility Function
//User Input
int userInput();                                                //Utility Function
//Menu Function which will automatically display
bool menuDisplay();                                             //Utility and Information Function
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
//---------------------May requie some variable adjustments--------------------------//
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

    //end variable declarations

    //initialize struct pointers/linked list Person* is the node 
    Person* head = new Person; //independent person
    head -> next = NULL; //NULL == end of list

    Person* current = head;
    Person* newPerson;
    //end linked list head creation

    //standard main functions that will be used without user input
    //print_PersonList();
    
    //goodbye message function call
    show_goodbyeMsg();

    return 0;
}

//---------------------------------------------Function Definitions--------------------------------------------//

//Print List Function Definition
void print_PersonList(){
    return;
}
//Populate Linked List from people.txt Function definition
Person* populateList(){

    return 0;
}
//Node Swap Function Definition
struct Person* nodeSwap(){
    return 0;
}
//User input funciton Definiton
int userInput(){
    return 0;
}
//Menu Display function Definiton
bool menuDisplay(){
    return true;
}
//Node Count function Definition
int nodeCount(){
    return 0;
}
//------------------------------------------Menu Option Function Definitions-------------------------------------//

//Sort by SSN 
Person* sortSSN(){                                                      //Menu Option 1
    return 0;
}
//Remove Person 
Person* removePerson(){                                                 //Menu Option 2
    return 0;
}
//Add Person
Person* addPerson(){                                                    //Menu Option 3
    return 0;
}
//Add Supplemental File
Person* addSupplemental(){                                              //Menu Option 4
    return 0;
}
//Edit Person
void editPerson(){                                                      //Menu Option 5
    return;
}
//Eligible for Social Security, Over the age of 65
void over65(){                                                          //Menu Option 6
    return;
}
//High BMI, at risk for cardiovascular disease
void highBMI(){                                                         //Menu Option 7
    return; 
}
//Ratio of Men to Women per 1000
void theRatio(){                                                        //Menu Option 8
    return;
}
//Find Parents
void findParents(){                                                     //Menu Option 9
    return; 
}
//Find Children
void findChildren(){                                                    //Menu Option 10
    return;
}
//Find Siblings
void findSiblings(){                                                    //Menu Option 11
    return;
}
//Find Extended Family
void findExtendedFamily(){                                              //Menu Option 12
    return;
}


































