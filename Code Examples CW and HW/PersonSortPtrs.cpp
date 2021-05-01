//Jonathon Stillson CSC201 20APR Person Sort using pointers to people
#include <iostream>
#include <string>
using namespace std;

struct person{ //define the UDT

    string pName;
    long pSSN;
    char gender;
    string DOB;
    float height;
    float weight;
    string fName;
    string mName;
};

int main(){
    //person mySelf; // static
    person* mySelf = new person; //mySelf is a pointer to a person
    //initialize the members of the UDT
    mySelf->pName = "Roger Waters"; //mySelf dereferences a pointer to a person
                                    //that means (mySelf) is a person
    mySelf->gender = 'M';
    mySelf->DOB = "1956/03/15"; // yyyy/mm/dd
    mySelf->height = 68.34; //inches
    mySelf->weight = 174.83; //pounds
    mySelf->fName = "Peter J. Waters";
    mySelf->mName = "Emma Stone-Waters";
    //end initialization
    //access the members of the UDT
    cout << mySelf->pName << " | " << mySelf->gender << " | " << mySelf->DOB << " | " 
    << mySelf->height << " | " << mySelf->weight << " | " << mySelf->fName << " | "
    << mySelf->mName << endl;

    delete mySelf;
    mySelf = NULL;

    return 0;
}