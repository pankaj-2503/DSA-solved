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



int height(node*root){
    if(root==NULL) return 0;
    int left=height(root->left);
    int right=height(root->right);
    int ans=max(left,right)+1;
    return ans;
}

void printCurrentLevel(node*root,int level){
    if(root==NULL) return;  //base case
    if(level==1) cout<<root->data<<" ";
    else if(level>1){
        //recursive call to left and right part
        printCurrentLevel(root->left,level-1);
        printCurrentLevel(root->right,level-1);
    }
}

void LevelOrder(node*root){
    int h=height(root);
    for(int i=1;i<=h;i++){
        printCurrentLevel(root,i);
    }
}
int main(){
node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->right->right=new node(5);
cout<<"LevelOrderTraversal:";
LevelOrder(root);


return 0;
}