//Jonathon Stillson CSC201 HW 26APR #1 
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>

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
    
    /*----------------------------------------------------adds the new person
    ofstream outfile;
    string a1, a2, a3, a4, a5, a6, a7, a8;
    //string a1; long a2; char a3; string a4; float a5, a6; string a7, a8;
    outfile.open("moviestars.txt", std::ios_base::app);
    
    cout<<"Please enter the name of the person you want to add:";
    getline(cin, a1);
    cout<<"Please enter the ssn of the person you want to add:";
    getline(cin, a2);
    cout<<"Please enter the gender of the person you want to add:";
    getline(cin, a3);
    cout<<"Please enter the DOB of the person you want to add:";
    getline(cin, a4);
    cout<<"Please enter the height of the person you want to add:";
    getline(cin, a5);
    cout<<"Please enter the weight of the person you want to add:";
    getline(cin, a6);
    cout<<"Please enter the father of the person you want to add:";
    getline(cin, a7);
    cout<<"Please enter the mother of the person you want to add:";
    getline(cin, a8);
    
    outfile << endl;
    outfile << a1 << endl;
    outfile << a2 << endl;
    outfile << a3 << endl;
    outfile << a4 << endl;
    outfile << a5 << endl;
    outfile << a6 << endl;
    outfile << a7 << endl;
    outfile << a8 << endl;
    
    outfile.close(); 
    //---------------------------------------------------------------------*/
    
    person* head = new person; // independent person 
    head->next = NULL; 
    
    person* current = head; person* newPerson ;  
    // assign data values 
    string fLine;
    fstream fMovStar("moviestars.txt");
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
    
    
     person* index = NULL; int temp; string temp2; char temp3; string temp4; float temp5, temp6; string temp7, temp8;
     
     //classical bubble sort 
    while(current != NULL)
    {
        //Node index will point to node next to current 
        index = current->next;
        
        while(index != NULL)
        {
            //if current nodes data is greater than indexs node data, swap the data between them
            if(current->SSN > index->SSN)
            {
                temp = current->SSN;//ssn buble
                current->SSN = index->SSN;
                index->SSN = temp;
                
                temp2 = current->pname;//first name bubble
                current->pname = index->pname;
                index->pname = temp2;
                
                temp3 = current->gender;//gender bubble
                current->gender = index->gender;
                index->gender = temp3;
                
                temp4 = current->DOB;//date of birth bubble
                current->DOB = index->DOB;
                index->DOB = temp4;
                
                temp5 = current->height;//height bubble
                current->height = index->height;
                index->height = temp5;
                
                temp6 = current->weight;//weight bubble
                current->weight = index->weight;
                index->weight = temp6;
                
                temp7 = current->fName;//fathers name bubble
                current->fName = index->fName;
                index->fName = temp7;
                
                temp8 = current->mName;//mothers name bubble
                current->mName = index->mName;
                index->mName = temp8;
                
            }
            index = index->next;
        }
        current = current->next;
    }
    
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
