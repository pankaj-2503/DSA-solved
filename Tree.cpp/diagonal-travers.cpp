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

vector<int>diagonal(node*root){
    vector<int>ans;
    if(root==NULL) return ans;
    queue<node*>leftQueue;
    
    node*temp=root;
    while(temp){
        ans.push_back(temp->data);
        if(temp->left) leftQueue.push(temp->left);
        if(temp->right) temp=temp->right;
        else{
            if(!leftQueue.empty()){
                temp=leftQueue.front();
                leftQueue.pop();
            }
            else{
                temp=NULL;
            }
        }

    }
    return ans;

}

int main(){
node*root=new node(1);
root->left=new node(2);
root->right=new node(3);
root->left->left=new node(4);
root->left->right=new node(5);
root->right->left=new node(6);
root->right->right=new node(7);


vector<int>res=diagonal(root);
for(int i=0;i<res.size();i++){
    cout<<res[i]<<" ";
}

return 0;
}