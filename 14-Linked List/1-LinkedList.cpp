#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            next = NULL; 
        }
};

int main(){

    // Statically create node
    Node n1(1);

    // Save address of head. 
    Node *head = &n1; /* head = 8 bytes pointer variable */

    // Another node. 
    Node n2(2); 

    // Connect the nodes.
    n1.next = &n2;   

    // Print LL using Nodes
    cout << n1.data << " " << n2.data << endl; 

    // Printing LL using only head.
    cout << head->data << " " << head->next->data; 


    // Dynamic Creation of Node
    Node *n3 = new Node(3);
    Node *n4 = new Node(4);

    // connect nodes
    n3->next = n4; 

    // store address of head
    Node* head2 = n3;



    return 0;

}
