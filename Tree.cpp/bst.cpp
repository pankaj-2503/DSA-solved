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

void inorder(node*root){
    if(!root) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
//note: inorder of bst is sorted


node*insertIntoBst(node*root,int k){
    if(root==NULL) {
        root=new node(k);
        return root;
    }

    if(k>root->data){
        root->right=insertIntoBst(root->right,k);
    }
    else{
        root->left=insertIntoBst(root->left,k);
    }
    return root;
}


void takeInput(node*&root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBst(root,data);
        cin>>data;
    }
}

bool searchIntoBst(node*root,int x){
    if(root==NULL){
        return false;
    }

    if(root->data==x) return true;
    if(root->data>x) return searchIntoBst(root->left,x);
    else  return searchIntoBst(root->right,x);
}

node*minVal(node*root){
    node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

node*maxVal(node*root){
    node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

node*deletioninBST(node*root,int val){
    if(root==NULL){
        return root;
    }

    if(root->data==val){
        //0 child
        if(root->left==NULL && root->right==NULL) return NULL;
        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){
            node*temp=root->left;
            delete root;
            return temp;
        }
        //right child
         if(root->left==NULL && root->right!=NULL){
            node*temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){
            int mini=minVal(root->right)->data;  //finding minimum from right part or from left part
            root->data=mini;            //copying value
            root->right=deletioninBST(root->right,mini); //recursive call to right
            return root;
        }
    }

    else if(root->data>val){
        root->left=deletioninBST(root->left,val);
        return root;
    }
    else {
        root->right=deletioninBST(root->right,val);
        return root;
    }
    
}

int main(){

node*root=NULL;
cout<<"Enter the data to create BST:"<<endl;
takeInput(root);
inorder(root);
return 0;
}