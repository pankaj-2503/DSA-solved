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

bool isCompleteTree(node*root){
    if(root==NULL) return true;
    queue<node*>q;
    //do level order traversal and find if root left or right exist or not
    //if left exist then find right also exist or not 
    //if right exist without left then return false
    q.push(root);
    bool flag=false;
    while(!q.empty()){
        node*temp=q.front();
        q.pop();
        if(temp->left){
            if(flag==true){
               return false;
            }

            q.push(temp->left);
        }
        else flag=true;


        if(temp->right){
              if(flag==true) return false;
              q.push(temp->right);
        }
        else flag=true;
    }
    return true;
}

int main(){
 node*root =new node(3);
 root->left=new node(4);
 root->right=new node(5);
 
 if(isCompleteTree(root)==true) cout<<"Balanced:";
 else cout<<"Not balanced";


return 0;
}

