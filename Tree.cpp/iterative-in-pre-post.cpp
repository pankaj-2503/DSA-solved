#include<bits/stdc++.h>
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
void solve(node*root){
    stack<pair<node*,int>>s; //(value,state)
    s.push({root,1});
    string pre="";
    string in="";
    string post="";
    while(!s.empty()){
        int state=s.top().second;
        node*temp=s.top().first;
        if(state==1){
            pre+=to_string(temp->data);
            s.top().second=state+1;
            if(temp->left) s.push({temp->left,1});
        }
        else if(state==2){
            in+=to_string(temp->data);
            s.top().second=state+1;
            if(temp->right) s.push({temp->right,1});
        }
        else{
            post+=to_string(temp->data);
            s.pop();
        }
    }
    cout<<"Preorder is:"<<pre<<' '<<endl;
    cout<<"Inorder is:"<<in<<' '<<endl;
    cout<<"Postorder is:"<<post<<' '<<endl;

}



int main(){
node*root=NULL;
root=buildTree(root);
solve(root);


return 0;
}