/******************************************************************************
Jonathon Stillson CSC201 HW8 
For each person, find and report all the children that person has. 
*******************************************************************************/
#include <iostream> 
#include <fstream> 
#include <string>  
using namespace std; 
struct person
{
    string pname;    
    long SSN;       
    
    char gender;    
    string DOB;    
    
    float height;     
    float weight;   
    
    long fName;
    long mName;
    string father;
    string mother;
};

float get_RBMI(int, int, person[]);

int main()
{

    cout << "Welcome to the Paternity and Maternity Checker.";
    cout << endl << endl;
    string fName = "moviestars.txt";  string fLine; 
    
    int totalcount = 0;
    int linecount = 0;         
    ifstream fMovStar;             
    fMovStar.open(fName);                       
    
    while(!fMovStar.eof())    
    {
        getline(fMovStar, fLine);
        linecount++;
        if (linecount == 10)
        {
            linecount = 0;
            totalcount++;
        }
    }
    fMovStar.close();
    person MyFavMovieStar[totalcount]; 
    int pcount = 0; 
    
    fMovStar.open(fName);
    while(!fMovStar.eof())
    {
    getline(fMovStar, fLine); MyFavMovieStar[pcount].pname = fLine;
    getline(fMovStar, fLine); MyFavMovieStar[pcount].SSN = stol(fLine);
    
    getline(fMovStar, fLine); MyFavMovieStar[pcount].gender = fLine[0];
    getline(fMovStar, fLine); MyFavMovieStar[pcount].DOB = fLine;
    
    getline(fMovStar, fLine); MyFavMovieStar[pcount].height = stof(fLine);
    getline(fMovStar, fLine); MyFavMovieStar[pcount].weight = stof(fLine);
    
    getline(fMovStar, fLine); MyFavMovieStar[pcount].father = fLine;
    getline(fMovStar, fLine); MyFavMovieStar[pcount].fName = stol(fLine);
    getline(fMovStar, fLine); MyFavMovieStar[pcount].mother = fLine;
    getline(fMovStar, fLine); MyFavMovieStar[pcount].mName = stol(fLine);
    


    pcount++;
    }
    
    fMovStar.close();

    int index1, index2;


    cout << "Fathers and their children: " << endl << endl;
    
    for (int i = 0; i < pcount; i++) 
    {   for(int j = i + 1; j < pcount; j++){
        
        if ((MyFavMovieStar[i].fName == MyFavMovieStar[j].fName) 
            && MyFavMovieStar[i].fName != 0 && MyFavMovieStar[j].fName != 0){
                
                index1 = i;
                index2 = j;
                
                cout << "The Father: " << MyFavMovieStar[index1].father << endl;
            
            cout << "has the kids: "<< MyFavMovieStar[index1].pname << " | " <<
            MyFavMovieStar[index2].pname << endl << endl;
                
            }
        }
    }
    
    cout << "Mothers and their children: " << endl << endl;
    
    for (int i = 0; i < pcount; i++) 
    {   for(int j = i + 1; j < pcount; j++){
        
        if ((MyFavMovieStar[i].mName == MyFavMovieStar[j].mName) 
            && MyFavMovieStar[i].mName != 0 && MyFavMovieStar[j].mName != 0){
                
                index1 = i;
                index2 = j;
                
                cout << "The Mother: " << MyFavMovieStar[index1].mother << endl;
            
            cout << "has the kids: "<< MyFavMovieStar[index1].pname << " | " <<
            MyFavMovieStar[index2].pname << endl << endl;
                
            }
        }
    }
    return 0;
}