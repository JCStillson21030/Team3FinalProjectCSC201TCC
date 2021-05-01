//Jonathon Stillson CSC201 CW 20APR POINTERS TO array of STRUCTS - Modularized
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person{  // define the UDT 
    
    string pname;
    long SSN; 

    char gender; 
    string DOB;
    
    float height; 
    float weight;
    
    string fName;
    string mName;
    
};

int get_numPersons(string); 
void populate_persons(person*, string, int); 
void report_persons(person*, int); 
void do_sort(person*, int); 

int main(){
    
    string fName = "moviestars.txt";
    
    int pcount = get_numPersons(fName);
    
    cout << pcount << endl;

    person* myFavMovieStar = new person[pcount]; 
    
    populate_persons(myFavMovieStar, fName, pcount);
    
    cout << "Done reading the file." << endl;
    
    report_persons(myFavMovieStar, pcount);
    
    do_sort(myFavMovieStar, pcount);
    
    report_persons(myFavMovieStar, pcount);
        
    cout << endl; 
    
    return 0;
    
}

int get_numPersons(string fName){ 
    
    int pcount = 0; 
    
    ifstream fMovStar;
    fMovStar.open(fName);
    
    string fLine; 
    
    while (!fMovStar.eof()){
        
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].pname = fLine;
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].SSN = stol(fLine);
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].gender = fLine[0];
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].DOB = fLine;
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].height = stof(fLine);
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].weight = stof(fLine);
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].fName = fLine;
        getline( fMovStar, fLine); 
        //myFavMovieStar[pcount].mName = fLine;
        
        pcount++;
    }
    
    fMovStar.close(); 
    
    return pcount;
} 

void populate_persons(person* myFavMovieStar, string fName, int pcount){ 
    
    ifstream fMovStar;
    fMovStar.open(fName);
    
    string fLine; 
    
    for (int i = 0; i < pcount; i++) {
        
        getline( fMovStar, fLine); 
        myFavMovieStar->pname = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar->SSN = stol(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar->gender = fLine[0];
        getline( fMovStar, fLine); 
        myFavMovieStar->DOB = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar->height = stof(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar->weight = stof(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar->fName = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar->mName = fLine;
        
        myFavMovieStar++;
        
    }
    // myFavMovieStar-=pcount; // reset the pointer to the start of the array 
    fMovStar.close(); 
    return; 
} 

void report_persons(person* myFavMovieStar, int pcount){ 
    
    for (int i = 0; i < pcount; i++){
                cout << myFavMovieStar->pname << " | " << myFavMovieStar->SSN << " | " << myFavMovieStar->gender << " | " << myFavMovieStar->DOB << " | " 
                << myFavMovieStar->height << " | " << myFavMovieStar->weight << " | " << myFavMovieStar->fName << " | "  << myFavMovieStar->mName << " | " <<  endl ; 
    
        myFavMovieStar++;
    }
    cout << endl; 
    //myFavMovieStar-=pcount; // reset the pointer to the start of the array 
} 

void do_sort(person* myFavMovieStar, int pcount){
    
    person* tmp[pcount]; 
     
    for (int i = 0; i < pcount; i++){
        tmp[i] = myFavMovieStar;
        myFavMovieStar++;
    }
    
    person* swapper;
    
     for(int i = 0; i < pcount; i++){
        for(int j = 1; j < pcount; j++){
            if(tmp[j]->SSN < tmp[j - 1]->SSN){
                swapper = tmp[j];
                tmp[j] = tmp[j - 1];
                tmp[j - 1] = swapper; 
            }
        }
    }
    //Done sorting persons by SSN 
    
    for (int i = 0; i < pcount; i++){
                cout << tmp[i]->pname << " | " << tmp[i]->SSN << " | " << tmp[i]->gender << " | " << tmp[i]->DOB << " | " 
                << tmp[i]->height << " | " << tmp[i]->weight << " | " << tmp[i]->fName << " | "  << tmp[i]->mName << " | " <<  endl ; 
    }
    cout << endl; 
   
    //Done printing persons by SSN
    
}