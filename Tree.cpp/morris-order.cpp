#include<iostream>
using namespace std;

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
//inorder traversal using moris traversal
void MorisTraversal(node*root){
    node*curr,*prev;
    if(root==NULL) return ;
    curr=root;
    while(curr!=NULL ){
        if(curr->left==NULL){//if no left subtree then move to right 
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{//storing  left node and moving to right subtree
            prev=curr->left;
            while(prev->right!=NULL && prev->right!=curr){
                prev=prev->right;
            }
            if(prev->right==NULL){//creating thread and moving curr to left
                prev->right=curr;
                curr=curr->left;
            }
            else{//cutting thread and moving to right
                prev->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }
}
int main(){
node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
MorisTraversal(root);

return 0;
}