//Jonathon Stillson CSC201 HW 26APR #1 
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
    string data;
    
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
    
    person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5; float temp6; string temp7; string temp8;
    
    // classical bubble sort 
    while(current != NULL) {  
        //Node index will point to node next to current  
        index = current->next;  
          
        while(index != NULL) {  
            //If current node's SSN is greater than index's node data, swap the data between them  
            if(current->SSN > index->SSN) {  
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
                
                temp7 = current->fName;
                current->fName = index->fName;
                index->fName = temp7;
                
                temp8 = current->mName;
                current->mName = index->mName;
                index->mName = temp8;
                
            }  
            index = index->next;  
        }  
        current = current->next;
        
        
    }      

    current = head; 
    
     while (current != NULL){
        cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
        << current->height << " | " << current->weight << " | " << current->fName << " | "  << current->mName << " | " <<  endl ;
        current = current->next; 
    }
   

    
    cout << endl; 
    
    
    //while (current != NULL){
        //cout << current->pname << " | " << current->SSN << " | " << current->gender << " | " << current->DOB << " | " 
       // << current->height << " | " << current->weight << " | " << current->fName << " | "  << current->mName << " | " <<  endl ;
       // current = current->next; 
    //}
    
    
   // current = head; 
    //cout << endl; 
    
    return 0;
    
}
