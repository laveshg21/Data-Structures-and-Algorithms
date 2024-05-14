#include<iostream>
#include<queue>
#include<vector>
// #include "TreeNode.h"  / Doesn't work with build command
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

void PrintAtLevelK(TreeNode<int>* root, int k){
    if(k==0){
        cout << root->data << " ";
        return;
    }

    for(int i =0; i< root->children.size(); i++){
        PrintAtLevelK(root->children[i], k-1);
    } 
}


int numLeafNodes(TreeNode<int>* root){
    int numLeaf=0; 

    if(root->children.size()==0){
        return 1; 
    }

    for(int i =0; i< root->children.size(); i++){
        numLeaf+=numLeafNodes(root->children[i]);
    }

    return numLeaf; 
}


int main(){

    TreeNode<int>* root = takeInputLevelWise();

    PrintAtLevelK(root, 2); 
    cout << endl; 
    cout << numLeafNodes(root); 
     

}