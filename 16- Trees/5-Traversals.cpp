#include<iostream>
#include<queue>
#include<vector>
// #include "TreeNode.h"
using namespace std;

template <typename T>
class TreeNode{
    public:
    T data;
    vector<TreeNode<T>*> children; 

    TreeNode(T data){
        this-> data = data;
    }
};

TreeNode<int>* takeInputLevelWise(){
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while(pendingNodes.size() !=0){
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for(int i=0; i< numChild; i++){
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front-> children.push_back(child);
            pendingNodes.push(child);
        } 
    }

    return root; 
}


void PreOrderTraversal(TreeNode<int>*root){

    /* EDGE CASE: * NO BASE CASE */
    if(root == NULL){
        return;
    }
    cout << root->data << " "; 
    for(size_t i=0; i < root->children.size(); i++){
        PreOrderTraversal(root->children[i]);
    }
}

void PostOrderTraversal(TreeNode<int>*root){

    /* EDGE CASE: * NO BASE CASE */
    if(root == NULL){
        return;
    }

    if(root->children.size() ==0){
        cout << root->data << " "; 
    }

    for(size_t i=0; i < root->children.size(); i++){
        PreOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    // PreOrderTraversal(root);
    cout<< endl; 
    PostOrderTraversal(root);
}