/******************************************************************************
Jonathon Stillson CSC201 HW 7 
*******************************************************************************/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct person{  // define the UDT 
    
    string pName;
    long SSN; 

    char gender; // 127 different genders 
    string DOB;
    
    float height; 
    float weight;
    
    string fName;
    string mName;
    
};

int main() {
    
    string fLine;
    int pcount = 0; 
    
    ifstream fMovStar;
    fMovStar.open("moviestars.txt");
    
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
    
    person myFavMovieStar[pcount]; 
    
    fMovStar.open("moviestars.txt");
    
    cout << pcount << endl;
    
    for (int i = 0; i < pcount; i++) {
        
        getline( fMovStar, fLine); 
        myFavMovieStar[i].pName = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar[i].SSN = stol(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar[i].gender = fLine[0];
        getline( fMovStar, fLine); 
        myFavMovieStar[i].DOB = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar[i].height = stof(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar[i].weight = stof(fLine);
        getline( fMovStar, fLine); 
        myFavMovieStar[i].fName = fLine;
        getline( fMovStar, fLine); 
        myFavMovieStar[i].mName = fLine;
        
    }
    
    fMovStar.close(); 
    
    cout << "Done reading the file." << endl;
    
    for (int i = 0; i < pcount; i++){
                cout << myFavMovieStar[i].pName << " | " << myFavMovieStar[i].SSN << " | " << myFavMovieStar[i].gender << " | " << myFavMovieStar[i].DOB << " | " 
                << myFavMovieStar[i].height << " | " << myFavMovieStar[i].weight << " | " << myFavMovieStar[i].fName << " | "  << myFavMovieStar[i].mName << " | " <<  endl ; 
    }
    
    string fullSibs[pcount]; // fullSibs[0] = "Robert DeNiro, Alec Guinness"; fullSibs[1] = "nnn, mmmm, bbbb"; 
    
    int k = -1; int sibFound = 0;
    
    for (int i = 0; i < pcount; i++){
        k++;
        for (int j = i + 1; j < pcount; j++){
                // cout << myFavMovieStar[i].pName + ", " + myFavMovieStar[j].pName << endl; //trace line str1.compare(str2) != 0
                if (myFavMovieStar[i].fName == myFavMovieStar[j].fName && myFavMovieStar[i].mName == myFavMovieStar[j].mName){
                    cout << "Found! i: " << i << endl;
                    if (sibFound > 0) {fullSibs[k] = fullSibs[k] + ", "  + myFavMovieStar[j].pName + ", " + myFavMovieStar[j].gender;}
                    else {fullSibs[k] = myFavMovieStar[i].pName + ", " + myFavMovieStar[j].pName + ", " + myFavMovieStar[j].gender;}
                    sibFound = 1;
                }
        }
        
        if (sibFound > 0) {sibFound = 0; } //cout << "Sib found! i = " << i << endl;}
        else {k--; cout << "Sib NOT found! i = " << i << endl;}
    }
    
    cout << "k: " << k << endl;
    
    for (int q = 0; q < k; q++){
        cout << "q: " << q << endl;
        cout << fullSibs[q] << endl;
    }
    
    cout << endl; 
    
    return 0;
}