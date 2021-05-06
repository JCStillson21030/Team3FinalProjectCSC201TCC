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

}

//Welcome and goodbye message modules
void show_welcomeMsg(){

    cout << "Welcome to the Team 3 CSC201 Final Program." << endl;
    cout << "Created by: Jonathon Stillson, Marc Bruno, Jamin White, Brandon Byrd, and Brandon Burns" << endl;

}

void show_goodbyeMsg(){

    cout << "Thank you for using the Program." << endl;
    cout << "BMannyB, JasJag, Navelfuzz, Burb, and Junki wish you well ;) " << endl;

}
//End greeting and salutation modules





//Main Driver
int main(){

    show_welcomeMsg();








    show_goodbyeMsg();

    return 0;
}
































