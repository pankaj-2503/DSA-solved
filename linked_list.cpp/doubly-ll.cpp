#include<iostream>
using namespace std;

class node{
   public:
      int data;
      node*next;
      node*prev;
    //constructor
     node(int val){
        data=val;
        next=NULL;
        prev=NULL;
     }
    
};

void insertAtHead(node*&head,int val){
    node*n=new node(val);
    n->next=head;
    if(head!=NULL){
       head->prev=n;
    }
    head=n;
}

void insertAtTail(node*&head,int val){
    //0 node is present
    if(head==NULL){
        insertAtHead(head,val);
        return;
    }
    //creating new node 
    node*n=new node(val);
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    //pointing to new node the curr position
    temp->next=n;
    n->prev=temp;
}

void insertAfter(node*&head,int key,int val){
    // 0 or 1 node
    if(head==NULL){
        insertAtTail(head,val);return;
    }
    node*n=new node(val);
    node*temp=head;
    while(temp->data!=key){
        temp=temp->next;
    }
    n->next=temp->next;
    n->prev=temp;
    temp->next=n;
    temp->next->prev=n;
   
}

void deleteAtHead(node*&head){
    node*todelete=head;
    head=head->next;
    head->prev=NULL;
    delete todelete;
}

void display(node*head){
    node*temp=head;
    cout<<"NULL<-->";
    while(temp!=NULL){
        cout<<temp->data<<"<-->";
        temp=temp->next;
    }cout<<"NULL"<<endl;;
}
void deletion(node*&head, int pos){
    if(pos==1){
        deleteAtHead(head);
        return;
    }

    node*temp=head;
    int count=1;
    while(temp!=NULL && count!=pos){
        temp=temp->next;
        count++;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    delete temp;
}

int main(){
node*head=NULL;
insertAtHead(head,2);
insertAtHead(head,3);
insertAtHead(head,4);
insertAtTail(head,8);
insertAfter(head,3,5);
deleteAtHead(head);
deletion(head,3);

display(head);
return 0;
}