#include<bits/stdc++.h>
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
//Time complexity-O(n),space complexity-O(n)
void inorder(node*root){
    stack<node*>s;
    node*temp=root;
    while(temp!=NULL || !s.empty()){
       while(temp!=NULL){
        //reach to left most leaf node
         s.push(temp);
         temp=temp->left;
       }

       temp=s.top();
       s.pop();
       cout<<temp->data<<" ";
       //now it's right subtree turn
       temp=temp->right;
    }
}

void iterativepreorder(node*root){
    if(root==NULL) return;
    stack<node*>st;
    st.push(root);
    while(!st.empty()){
        node*temp=st.top();
        cout<<temp->data<<" ";
        st.pop();
        if(root->right) st.push(root->right);
        if(root->left) st.push(root->left);
    }
}


int main(){

node*root=new node(5);
root->left=new node(4);
root->right=new node(3);
root->left->left=new node(1);
root->left->right=new node(2);

// inorder(root);

iterativepreorder(root);
return 0;
}