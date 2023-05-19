#include<iostream>
#include<queue>
using namespace std;

class node{
  public:
     int data;
     node*left;
     node*right;
     //constructor
     node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
     }
  
};


node*buildTree(node*root){
    cout<<"Enter the data:";
    int data;cin>>data;
    root=new node(data);
    if(data==-1) return NULL;
    cout<<"Enter data for inserting in left of :"<<data<<endl;
    
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of: "<<data<<endl;
    
    root->right=buildTree(root->right);
    return root;
}

node*deletion(node*root,int key){
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL){
            if(root->data==key) return NULL;
            else return root;
        }
        
        node*last;
        node*temp;
        node*key_node=NULL;
        queue<node*>q;
        q.push(root);
        while(!q.empty()){
            node*temp=q.front();
            q.pop();
            if(temp->data==key) key_node=temp;
            if(temp->left!=NULL) {last=temp;q.push(temp->left);}
            if(temp->right!=NULL) {last=temp;q.push(temp->right);}
        }
        if(key_node!=NULL){
            key_node->data=temp->data;
        if(last->right==temp) last->right=NULL;
        else last->left=NULL;
        delete temp;
    }

    return root;

}
//inorder traversal
void inorder(node*root){
    if(root==NULL) return ;//base case
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void preorder(node*root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node*root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void levelorderTraversal(node*root){
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}
 bool isBST(node* root) 
    {
        // Your code here
        if(root==NULL) return true;
        if(root->left!=NULL && root->left->data>root->data) return false;
        if(root->right!=NULL && root->right->data<root->data) return false;
        if(!isBST(root->left)|| !isBST(root->right))  return false;
        
        return true;
    }

int main(){
node*root=NULL;
root=buildTree(root);
cout<<endl;
inorder(root);cout<<"\n";
/*
preorder(root);cout<<"\n";
postorder(root);cout<<"\n";

levelorderTraversal(root);cout<<"\n";
isBST(root);
*/
return 0;
}