#include<iostream>
using namespace std;

class node{
 public:
    int data;
    node*next;
};

void print(node*n){
    while(n!=NULL){
        cout<<n->data<<"->";
        n=n->next;
    }cout<<"NULL"<<endl;
}

int main(){
//creating 3 nodes 
node*head=NULL;
node*second=NULL;
node*third=NULL;

//allocating nodes into heap
head=new node();
second=new node();
third= new node();

//assigning and pointing to next node
head->data=1;
head->next=second;

second->data=2;
second->next=third;

third->data=3;
third->next=NULL;

print(head);


return 0;
}