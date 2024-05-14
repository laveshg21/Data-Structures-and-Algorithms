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

    // CONSTRUCTOR
    TreeNode(T data){
        this-> data = data;
    }

    // DESTRUCTOR - POST ORDER TRAVERSAL
    ~TreeNode(){
        for(int i=0; i <children.size(); i++){
            delete children[i]; 
        }
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


void DeleteTree(TreeNode<int>* root){
    for(int i =0; i < root->children.size(); i++){
        DeleteTree(root->children[i]);
    }
    delete root; 
}

int main(){
    TreeNode<int>* root = takeInputLevelWise();
    cout << root->data << endl;
    // DeleteTree(root); 
    delete root; 
    cout << root->data;  // GARBAGE VALUE

}