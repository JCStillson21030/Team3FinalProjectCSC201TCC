/*15 APR 
DYNAMIC MEMORY - THE 'new' KEYWORD 
*/ 

#include <iostream>
#include <string>

using namespace std;

struct person{  // define the UDT 
    
    string pName;
    long pSSN; 

    char gender; 
    string DOB;
    
    float height; 
    float weight;
    
    string fName;
    string mName;
    
};

int main() {
    
    // person mySelf; // static 
    
    person* mySelf = new person; // mySelf is a pointer to a person 
    
    // initialize the members of the UDT
    (*mySelf).pName = "Roger Waters"; // *myself dereferences a pointer to a person
                                      // that means (*myself) is a person 
    (*mySelf).gender = 'M';
    (*mySelf).DOB = "1956/03/15"; // yyyy/mm/dd 
    
    (*mySelf).height = 68.34; // inches 
    (*mySelf).weight = 174.83; // pounds
    
    (*mySelf).fName = "Peter J. Waters";
    (*mySelf).mName = "Emma Stone-Waters";
    // end initialization 
    
    // accees the members of the UDT
     cout << (*mySelf).pName  << " | "
     << (*mySelf).gender  << " | "
     << (*mySelf).DOB  << " | "
     << (*mySelf).height  << " | "
     << (*mySelf).weight << " | "
    
     << (*mySelf).fName << " | "
     << (*mySelf).mName  << endl;    
    
    return 0;
}