//Jonathon Stillson CSC201 CW 22APR The person sorter using functions
//and passing pointers
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person{   
    
    string pname;
    long SSN; 

    char gender;  
    string DOB;
    
    float height; 
    float weight;
    
    string fName;
    string mName;
    
    person* next; 
    
};
  
// Program to create a simple linked list from a file
int main(){ 
    
    person* head = new person; // independent person 
    head->next = NULL; 
    
    person* current = head; person* newPerson ;  
    // assign data values 
    string fLine;
    ifstream fMovStar;
    fMovStar.open("moviestars.txt"); 
    
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
        current->fName = fLine;
        getline( fMovStar, fLine); 
        current->mName = fLine;
        
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
        << current->height << " | " << current->weight << " | " << current->fName << " | "  << current->mName << " | " <<  endl ;
        current = current->next; 
    }

    current = head; 
    cout << endl; 
    
    return 0;
    
}