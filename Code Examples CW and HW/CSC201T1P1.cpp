//CSC201 Test 1 P 1 - convert string into separate ints and check format
//yyyy/MM//dd hh:mm:ss become six sep ints yy, MM, dd, hh, mm and ss
//the function returns 0 for successful conversion and 1 otherwise
//The main function calls the above function and after that the main function
//reports the separate integer values
#include <iostream>
#include <string> 
using namespace std;

int myStrScanner(string, int&, int&, int&, int&, int&, int&);


int main(){

    string myDateTime = "1988/10/08 12:35:22";
    //cout << "Please enter a date-time in the format yyyy/MM/dd hh:mm:ss :" << endl;
    //getline(cin, myDateTime);

    int yy, mon, dd, hh, min, ss; 

    int status = myStrScanner(myDateTime, yy, mon, dd, hh, min, ss);
    
    if (status == 0){
        cout << yy << " " << mon << " " << dd << " " << hh << " " << min << " " << ss << endl;
    } else cout << "Conversion Unsuccessful.";

    return 0;
}

int myStrScanner(string myDateTime, int& yy, int& mon, int& dd, int& hh, int& min, int& ss){
    if ((myDateTime[0] < 48) || (myDateTime[0] > 57)) return 1;
    if ((myDateTime[1] < 48) || (myDateTime[1] > 57)) return 1;
    if ((myDateTime[2] < 48) || (myDateTime[2] > 57)) return 1;
    if ((myDateTime[3] < 48) || (myDateTime[3] > 57)) return 1;
    if (myDateTime[4] != 47) return 1;

    if ((myDateTime[5] < 48) || (myDateTime[5] > 57)) return 1;
    if ((myDateTime[6] < 48) || (myDateTime[6] > 57)) return 1;
    if (myDateTime[7] != 47) return 1;

    if ((myDateTime[8] < 48) || (myDateTime[8] > 57)) return 1;
    if ((myDateTime[9] < 48) || (myDateTime[9] > 57)) return 1;
    if (myDateTime[10] != 32) return 1;

    if ((myDateTime[11] < 48) || (myDateTime[11] > 57)) return 1;
    if ((myDateTime[12] < 48) || (myDateTime[12] > 57)) return 1;
    if (myDateTime[13] != 58) return 1;

    if ((myDateTime[14] < 48) || (myDateTime[14] > 57)) return 1;
    if ((myDateTime[15] < 48) || (myDateTime[15] > 57)) return 1;
    if (myDateTime[16] != 58) return 1;

    if ((myDateTime[17] < 48) || (myDateTime[17] > 57)) return 1;
    if ((myDateTime[18] < 48) || (myDateTime[18] > 57)) return 1;

    yy = stoi(myDateTime.substr(0, 4));
    mon = stoi(myDateTime.substr(5, 2));
    dd = stoi(myDateTime.substr(8, 2));

    hh = stoi(myDateTime.substr(11, 2));
    min = stoi(myDateTime.substr(14, 2));
    ss = stoi(myDateTime.substr(17, 2));

    return 0;

}