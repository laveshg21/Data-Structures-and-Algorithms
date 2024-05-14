#include<iostream>
#include<queue>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size() !=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter num children of" << front->data << endl; 
        int numChild;
        cin >> numChild;

        for(int i=0; i< numChild; i++){
            int childData;
            cout << "Enter " << i << "th child of " << front-> data << endl; 
            cin >> childData;

            TreeNode<int>* child = new TreeNode<int>(childData);
            front-> children.push_back(child);
            pendingNodes.push(child);
        } 
    }

    return root; 
}

TreeNode<int>* takeInputRecursive(){
    int rootData;
    cout << "Enter Data: ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter num(children) of " << rootData << ":";
    cin >> n;

    for(int i=0; i<n; i++){
        TreeNode<int> * child = takeInputRecursive();
        root->children.push_back(child);
    }
    return root; 
}

void printTree(TreeNode<int>*root){

    /* EDGE CASE: * NO BASE CASE */
    if(root == NULL){
        return;
    }
    
    cout << root->data << ":";
    for(size_t i=0; i< root->children.size(); i++){
        cout << root->children[i]->data << ",";
    }
    cout << endl; 

    for(size_t i=0; i < root->children.size(); i++){
        printTree(root->children[i]);
    }
}

void printLevelWise(TreeNode<int>* root){
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(pendingNodes.size() !=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();

        cout << front-> data << ": "; 

        for(int i=0; i < front->children.size(); i++){
            TreeNode<int>* child = front->children[i];
            cout << child->data << ",";
            pendingNodes.push(child);
        }
        cout << endl; 
    }
}


int main(){

    // BASIC WAY TO DECLARE NODES ONE BY ONE AND CONNECT THEM LATER TO MAKE TREE
    // TreeNode<int>* root = new TreeNode<int>(1);
    // TreeNode<int>* node1 = new TreeNode<int>(2);
    // TreeNode<int>* node2 = new TreeNode<int>(3);
    // TreeNode<int>* node3 = new TreeNode<int>(4);

    // root->children.push_back(node1); 
    // root->children.push_back(node2); 
    // node1->children.push_back(node3);

    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);

} 