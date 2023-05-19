#include<iostream>
using namespace std;

// as linked list is dynamic in nature so no overflow condition is possible here
class Stacknode{
    public:
       int data;
       Stacknode*next;
      
};

Stacknode*top=NULL;

void push(int val){
  Stacknode*n=new Stacknode();
  n->data=val;
  n->next=top;
  top=n;
}

void pop(){
    if(top==NULL)  cout<<"Stack underflow"<<endl;
    else {
        cout<<"Popped data is:"<<top->data<<endl;
        top=top->next;
    }
}


void display(){
 Stacknode*temp;
 if(top==NULL) cout<<"stack is empty"<<endl;
 else{
    temp=top;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
 }
}
int main(){
  push(3);
  push(5);
  push(8);
  
  display();
  pop();
  pop();
  pop();
  pop();
  display();
  

return 0;
}