//Jonathon Stillson CSC201 CW 22APR Write a C++ program that creates a linked list 
//of 3 nodes (int data, next ptr) and sorts the nodes by integer data ascending. 
#include <iostream>
using namespace std; 

struct Node {
    int data; // data part 
    Node* next; // next part 
};
  
// Program to create a simple linked list with 3 nodes
int main(){ 
    
    Node* head = new Node(); // independent node 
    Node* second = new Node(); // independent node 
    Node* third = new Node(); // independent node 
    
    // link the nodes: 
    head->next = second; 
    second->next = third; 
    third->next = NULL; 
    
    // assign data values 
    head->data = 23; 
    second->data = 14; 
    third->data = 52; 
    
    Node* current = head; 

    while (current != NULL){
        cout << current->data << endl;
        current = current->next; 
    }

    current = head; 
    cout << endl; 
            
    Node* index = NULL; int temp; 
    
    // classical bubble sort 
    while(current != NULL) {  
        //Node index will point to node next to current  
        index = current->next;  
          
        while(index != NULL) {  
            //If current node's data is greater than index's node data, swap the data between them  
            if(current->data > index->data) {  
                temp = current->data;  
                current->data = index->data;  
                index->data = temp;  
            }  
            index = index->next;  
        }  
        current = current->next;  
    }      

    current = head; 
    
    while (current != NULL){
        cout << current->data << endl;
        current = current->next; 
    }

    current = head; 
    cout << endl; 
    
    return 0;
    
}