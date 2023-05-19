
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int key;
    node*right,*left;
    node(int k){
        this->key = k;
        this->right = this->left = NULL;
    }
};
//O(n^2)  solution
int height(node*root){
    if(root==NULL) return 0;
    return 1+max(height(root->left),height(root->right));
}

bool isBalanced(node*root){
    if(root==NULL) return true;

    int lh=height(root->left);
    int rh=height(root->right);

    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right)) return true;


    return false;
}

// or we can use this function which will do in O(n) time complexity
/*
// Function to check if tree is height balanced
int isBalanced(Node* root)
{
    if (root == NULL)
        return 0;
    int lh = isBalanced(root->left);
    if (lh == -1)
        return -1;
    int rh = isBalanced(root->right);
    if (rh == -1)
        return -1;
 
    if (abs(lh - rh) > 1)
        return -1;
    else
        return max(lh, rh) + 1;
}
 

*/

int main(){
    
    node*root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    if(isBalanced(root)){
        cout<<"Balanced:";
    }
    else cout<<"Not balanced";

    return 0;
}