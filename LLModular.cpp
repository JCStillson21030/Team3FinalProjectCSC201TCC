#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Person struct declaration module
struct Person{  
    
    string personName,
           personDOB;
           
    long personSSN,
         fatherSSN,
         motherSSN;
    
    char personGender;
    
    float personHeight,
          personWeight;
    
    Person* next;                                         
};
void show_WelcomeMsg(){

}




int main(){

    //Welcome Message
    show_WelcomeMsg();

    //variable declarations

    string myPeople = "people.txt"; 

    //end variable declarations

    //initialize struct pointers/linked list
    Person* head = new Person; //independent person
    head -> next = NULL;

    Person* current = head;
    Person* newPerson;
    //End struct pointers/linked list

    




}




















