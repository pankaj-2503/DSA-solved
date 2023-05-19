
#include <bits/stdc++.h>
using namespace std;

class newNode{
    public:
    int key;
    newNode*right,*left;
    newNode(int k){
        this->key = k;
        this->right = this->left = NULL;
    }
};
 
// This functions gets the size of binary tree

int getLength(newNode* root){
    if(root == NULL)
        return 0;
    return 1 + getLength(root->left) + getLength(root->right);
}
 
// Returns True if length of binary tree is a power of 2 else False
bool isPerfect(newNode* root){
    int length = getLength(root);
    return length & (length-1) == 0;
}

/*
by level order traversal we will find at each level power of 2 if not then return false
queue<Node*>q;
       q.push(root);
       int lev=0;
       while(!q.empty()){
           int size=q.size();
           if(size!=pow(2,lev)) return false;
           while(size--){
               Node* temp=q.front();
               q.pop();
               if(temp->left){
                   q.push(temp->left);
               }
               if(temp->right){
                   q.push(temp->right);
               }
           }
           lev++;
       }
       return true;
   



*/
 
int main()
{
    newNode* root = new newNode(10);
    root->left = new newNode(20);
    root->right = new newNode(30);

 
    if (isPerfect(root))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
}
 