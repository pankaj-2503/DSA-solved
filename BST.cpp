#include<iostream>
#include<queue>

using namespace std;

class Node{
    public:
    int data;
    Node*left;
    Node*right;

    Node(int d){  //constructor
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

void inorder(Node*root){   //LNR
    //base case
    if(root==NULL) return ;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(Node*root){   //NLR
    //base case
    if(root==NULL) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node*root){   //LRN
    //base case
    if(root==NULL) return ;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


void levelorderTraversal(Node*root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node*temp= q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else {
            cout<<temp->data<<" ";
            if(temp->left)  q.push(temp->left);
            if(temp->right)  q.push(temp->right);
        }
    }
}

Node* insertIntoBST(Node* &root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }

    if(d> (root->data)){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}


void takeInput(Node*&root){
    int data;cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minVal(Node*root){
    Node*temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* maxVal(Node*root){
    Node*temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp;
}

Node*deleteFromBST(Node*root,int val){
   //base case 
   if(root==NULL) return root;
   if(root->data==val){
    //0 child
   if(root->left==NULL && root->right==NULL){
          delete root; return root;
    }
    //1 child
    if(root->left!=NULL && root->right==NULL){
       Node*temp=root->left;delete root;return temp;
    }
    if(root->left==NULL && root->right!=NULL){
       Node*temp=root->right;delete root;return temp;
    }
    //2 child
    if(root->left!=NULL && root->right!=NULL){
       int mini=minVal(root->right)->data;
       root->data=mini;
       root->right=deleteFromBST(root->right,mini);
       return root;
    }
   }
   else if(root->data>val){
     root->left=deleteFromBST(root->left,val);
     return root;
   }
   else{
    root->right=deleteFromBST(root->right,val);
     return root;
   }
}


int main(){
        Node*root=NULL;
        cout<<"Enter data to create BST"<<endl;
        takeInput(root);
        cout<<"Printing BST"<<endl;
        levelorderTraversal(root);
        cout<<"Inorder Traversal:";
        inorder(root);cout<<endl;
        cout<<"Preorder Traversal:";
        preorder(root);cout<<endl;
        cout<<"Postorder Traversal:";
        postorder(root);cout<<endl;
        
        cout<<"Min value is :"<<minVal(root)->data<<endl;
        cout<<"Max value is :"<<maxVal(root)->data<<endl;
        cout<<endl;

        deleteFromBST(root,9);
         cout<<"Printing BST"<<endl;
        levelorderTraversal(root);

    return 0;
}