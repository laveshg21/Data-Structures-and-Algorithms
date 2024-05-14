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

Node* CreateFromInput(){ // O(n)
    // -1 as terminator

    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;

    while(data != -1){
        Node* n = new Node(data);

        // Update head only one time, initally head = NULL 
        if(head == NULL){
            head = n;
            tail = n;  
        }
        else{
            tail -> next = n; 
            tail = tail -> next;
            // tail = n; 
        }

        cin >> data; 

    }

    return head; 
}

int LL_Length_From_Input(){ // O(n)
    // -1 as terminator

    int data;
    cin >> data;
    int length = 0;  
    Node *head = NULL;
    Node *tail = NULL;
    while(data != -1){
        length++;
        Node* n = new Node(data);
        // Update head only one time, initally head = NULL 
        if(head == NULL){
            head = n;
            tail = n;  
        }
        else{
            tail -> next = n; 
            tail = tail -> next;
            // tail = n; 
        }
        cin >> data;
         
    }
    return length; 
}


void printLinkedList(Node* head){
    Node * temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next; 
    }
    cout << endl; 
    }

int main(){
    int t;
    cin >> t;

    while(t--){
    
        int ll_length = LL_Length_From_Input();
        cout << ll_length << endl; 

    }
    
    return 0;

}
