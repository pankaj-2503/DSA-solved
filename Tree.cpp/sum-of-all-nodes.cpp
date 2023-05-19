#include<bits/stdc++.h>
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
//using recursive call and finding sum
long long int sum(node*root){
    if(root==NULL) return 0;
    return (root->data+sum(root->left)+sum(root->right));
}

//using level order traversal finding sum

long long sumBt(node*root){
  long long sum=0;
  queue<node*>q;
  q.push(root);
  while(!q.empty()){
    node*temp=q.front();
    q.pop();
    sum+=temp->data;
    if(temp->left) q.push(temp->left);
    if(temp->right)  q.push(temp->right);
  }
  return sum;
}

//sum of all parent node having child node value equal to x

void sumofParentUtil(node*root,int sum,int x){
    if(!root) return;
    if((root->left && root->left->data==x)|| (root->right&& root->right->data==x))
      sum+=root->data;

      sumofParentUtil(root->left,sum,x);
      sumofParentUtil(root->right,sum,x);
}


int sumofParent(node*root,int x){
    int sum=0;
    sumofParentUtil(root,sum,x);
    return sum;
}

//sum of all left leaves of binary tree

bool isLeaf(node*root){
    if(root==NULL) return false;
    if(root->left==NULL && root->right==NULL) return true;

    return false;
}

int leftLeafSum(node*root){
    int res=0;
    if(root!=NULL){
        if(isLeaf(root->left)) res+=root->left->data;
        else  res+=leftLeafSum(root->left);

        res+=leftLeafSum(root->right);
    }
    return res;
}


int main(){

node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);

cout<<sum(root)<<endl;
cout<<sumofParent(root,5)<<endl;
cout<<leftLeafSum(root)<<endl;
    return 0;
}