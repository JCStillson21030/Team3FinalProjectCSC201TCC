/******************************************************************************
Jonathon Stillson CSC201 CW 23FEB
Learning to use a STRUCT which is a user defined data type i.e. a derived data
type (INT FLOAT DOUBLE CHAR STRING BOOL = system defined data types/prmitive)

Find the BMI of the person
*******************************************************************************/

#include <iostream>
#include <fstream>
using namespace std;

struct person{ //define the udt
    
    string pname;
    char gender;  //127 different genders
    string DOB;
    
    float height; 
    float weight;
    
    string fName;
    string mName;
};

int main(){
    
    person mySelf; //instantiate the udt
    person yourSelf; //another instance of the UDT
    
    person myPeople[12]; // an array of 12 persons
    
    //initialize the member of the UDT
    mySelf.pname = "Roger Waters";
    mySelf.gender = 'M';
    mySelf.DOB = "1956/03/15"; // yyyy/mm/dd 
    
    mySelf.height = 68.34; //inches
    mySelf.weight = 174.83; //pounds
    
    mySelf.fName = "Peter J. Waters";
    mySelf.mName = "Emma Stone-Waters";
    //end initialization
    
    // access the members of the UDT
    cout<<mySelf.pname << " "
    << mySelf.gender << " "
    << mySelf.DOB << " | "
    << mySelf.height << " | "
    << mySelf.weight << " | "

    << mySelf.fName << " | "
    << mySelf.mName << endl;
    
    //BMI = Weight in KG / Heigh in CM-Squared
    //Weight in KG = Weight in LBS * 0.45; Height in Meters = Height in Inches * 0.0254
    cout << "The BMI of " << mySelf.pname << " is " 
    << ((mySelf.weight) * 0.45) / (((mySelf.height) * 0.0254) * ((mySelf.height) * 0.0254)) << endl;
    return 0;
}