#include<iostream>
using namespace std;

class node{
  public:
      int data;
      node*next;

      //constructor
      node(int val){
        data=val;
        next=NULL;
      }
};

void insertNode(node*&tail,int key,int val){
    //empty linked list
    if(tail==NULL) {
        node*temp=new node(val);
        tail=temp;
        temp->next=temp; //circular
    }
    else{
        //non empty list
        node*curr=tail;
        while(curr->data!=key){
            curr=curr->next;
        }
        node*n=new node(val);
        n->next=curr->next;
        curr->next=n;

    }
}

void deleteNode(node*&tail,int val){
    //empty list
    if(tail==NULL){
        cout<<"list is empty:"<<endl;
        return;
    }
    else{
        //non empty list,assuming that the value is present in list
        node*prev=tail;
        node*curr=prev->next;
        while(curr->data!=val){
            prev=curr;
            curr=curr->next;
        }
        //cutting links
        prev->next=curr->next;
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}

void printlist(node*tail){
    node*temp=tail;
    do{// so that it executes once
        cout<<temp->data<<"-";
        temp=temp->next;
    }while(tail!=temp);
}

int main(){
node*tail=NULL;
insertNode(tail,0,4);
insertNode(tail,4,7);
insertNode(tail,7,9);
insertNode(tail,9,11);

printlist(tail);


return 0;
}