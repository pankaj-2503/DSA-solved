#include<iostream>
#include<queue>
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

void levelOrderTraversal(node*root){
    if(root==NULL) return;
    queue<node*>q;
    q.push(root);
    while(!q.empty()){
        node*temp=q.front();
        cout<<temp->data<<" ";
        q.pop();

        //push left
        if(temp->left!=NULL) q.push(temp->left);
        //push right
        if(temp->right!=NULL) q.push(temp->right);
    }
}
int main(){
node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->right->right=new node(5);
cout<<"Level Order Traversal is:";
levelOrderTraversal(root);

return 0;
}