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



int numNodes(TreeNode<int>* root){
    if(root==NULL)
        return 0; 
        
    int num=1; // for root node

    for(int i=0; i < root->children.size(); i++){
        num+= numNodes(root->children[i]);
    }

    return num; 
}

/*
Given a generic tree, find and return the sum of all nodes present in the given tree.
Input format :
The first line of input contains data of the nodes of the tree in level order form. 
The order is: data for root node, number of children to root node, data of each of child nodes and so on
and so forth for each node. The data of the nodes of the tree is separated by space.
Output Format :
The first and only line of output prints the sum of all nodes of the given generic tree.
*/

int sumNodes(TreeNode<int>* root){
    int sum = root-> data; 

    for(int i =0; i < root->children.size(); i++){
        sum += sumNodes(root->children[i]);
    }

    return sum; 
}

int largestNode(TreeNode<int>* root){
    int max = root -> data;
    
    for(int i =0; i < root->children.size(); i++){
        if(largestNode(root->children[i]) > max){
            max = largestNode(root->children[i]);
        }
    }
    return max;  
}

int HeightOftree(TreeNode<int>* root){
    int height=0;

    if(root ==NULL){
        return 0; 
    }

    if(root->children.size()==0){
        return 1; 
    }

    for(int i =0; i < root->children.size(); i++){
        if(HeightOftree(root->children[i]) > height){
            height = HeightOftree(root->children[i]);
        }
    }
    height+=1;           
    return height;  
}

int main(){

    TreeNode<int>* root = takeInputLevelWise();
    cout << "Nodes = " << numNodes(root) << endl;
    cout << "Sum = " << sumNodes(root) << endl;
    cout << "Max = " << largestNode(root) << endl; 
    cout << "Height = " << HeightOftree(root) << endl; 

}