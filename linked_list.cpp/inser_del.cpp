#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*next;
   //constructor call
    node(int val){
        data=val;
        next=NULL;
    }
};

void insertAtHead(node*&head,int val){
    node*n=new node(val);  //creating new node
    n->next=head;
    head=n;

}

void insertAfter(node*head,int key,int val){
    node*n=new node(val);
    if(key==head->data){    // if data equal to data to enter after
        n->next=head->next;
        head->next=n;
        return;
    }

    node*temp=head;
    while(temp->data!=key){  //traverse till we reach to data after which to insert
        temp=temp->next;
        if(temp==NULL){
            return;
        }
    }
    n->next=temp->next;  //cutting and pointing new node
    temp->next=n;
}

void insertAtTail(node*&head,int val){
    //1.creating new node
    node*n=new node(val);
    //2. check if ll is empty make it new node
    if(head==NULL){
        head=n;
        return;
    }
    node*temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }

    //3. point last node to new node
    temp->next=n;
}

void deleteAtHead(node*&head){
    node*todelete=head;
    head=head->next;
    delete todelete;
}

void deletion(node*&head,int val){
    // 0 node is present
    if(head==NULL) return;
    // 1 node is present
    if(head->next==NULL){
        deleteAtHead(head);
    }

    //creating node
    node*temp=head;
    while(temp->next->data!=val){
        temp=temp->next;
    }
    //deleting node
    node*todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}

void print(node*&head){
    
    while(head!=NULL){
        cout<<head->data<<"->";
        head=head->next;
    }cout<<"NULL"<<endl;
}

int main(){
//empty linked list
node*head=NULL;
insertAtHead(head,1);
insertAtHead(head,2);
insertAtHead(head,3);
insertAtHead(head,4);
insertAtHead(head,5);
insertAtTail(head,7);
insertAtTail(head,8);
insertAfter(head,4,9);
deleteAtHead(head);
deletion(head,9);
print(head);


return 0;
}   