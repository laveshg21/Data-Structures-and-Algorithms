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


void print_ll(Node* head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl; 
    }

int main(){


    // Create a linked list statically with 5 nodes. 
    Node n1(1);
    Node n2(2);
    Node n3(3);
    Node n4(4);
    Node n5(7);

    Node* head = &n1;
    n1.next = &n2;
    n2.next =&n3;
    n3.next = &n4;
    n4.next = &n5;
    // n5.next = NULL; by default NULL due to constructor

    print_ll(head->next); 


    Node* d1 = new Node(1);
    Node* d2 = new Node(1);
    Node* d3 = new Node(1);
    Node* d4 = new Node(1);
    Node* d5 = new Node(2);

    Node* head2 = d1;
    d1-> next = d2;
    d2 -> next = d3;
    d3 -> next = d4;
    d4 -> next = d5;

    print_ll(d2); 


    return 0;

}
