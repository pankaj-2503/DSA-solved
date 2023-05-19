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

bool isFoldableUtil(node*n1,node*n2);
bool isFoldable(node*root){
   if(root==NULL) return true;
   isFoldableUtil(root->left,root->right);
}

bool isFoldableUtil(node*n1,node*n2){
    if(n1==NULL && n2==NULL) return true;
    if(n1==NULL && n2!=NULL) return false;
    if(n1!=NULL && n2==NULL) return false;
    return isFoldableUtil(n1->left,n2->right) && isFoldableUtil(n1->right,n2->left);
}

int main(){
node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->right=new node(4);
root->right->left=new node(6);
if(isFoldable(root)==true){
    cout<<"foldable"<<endl;
}
else cout<<"not foldable"<<endl;



return 0;
}