//CSC110 08OCT20 How to modularize C++
#include <iostream>
using namespace std;

void show_welcomeMsg(){
    cout << "Welcome to the Number Addition Program!" << endl;
}
int add_two(int a, int b){   //'int' => return type, 'add_two' => name, 'int a', 'int b' input values (Arguments or Parameters)
    
    int y = a + b;
    return y; // RETURN value
}
int get_input(){
    int a; 
    cout << "Please enter a number: ";
    cin >> a;
    return a; 
}
void show_output(int a){
    cout << "The total of " << a << endl;
}
void show_GoodbyeMsg(){
    cout << "Thank you for using the Number Addition Program.";
}
int main()
{
    int firstNumber;  //camel casing; or underscore (first_num etc)
    int secondNumber;  //the values of variables generally come from outside sources
    int sum;   //(in order of importance/sophistication) user input, files on storage, other programs (IPC, network), database 
    
    show_welcomeMsg();
    
    firstNumber = get_input();
    secondNumber = get_input();
    
    sum = add_two(firstNumber, secondNumber); //function call
    
    show_output(sum);
    
    show_GoodbyeMsg();

    return 0;
}