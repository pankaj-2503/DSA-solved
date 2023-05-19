#include<iostream>
using namespace std;
// full tree is one which has 0 or 2 nodes
// we can check that if a tree is binary tree or not as max no. of node is 2^(h+1) -1 if there are this much of nodes then complete binary tree else not
class node{
    public:
    int data;
    node*left;
    node*right;
    node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

bool isFulltree(node*root){
    if(root==NULL) true;
    if(root->left==NULL && root->right==NULL) return true;
    if(root->left && root->right){
        return (isFulltree(root->left) && isFulltree(root->right));
    }
    
    //if not full 
    return false;
}  
int main(){

node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);

if(isFulltree(root)){
    cout<<"Full tree!!";
}
else cout<<"Not full tree!";

return 0;
}