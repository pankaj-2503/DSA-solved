#include<iostream>
using namespace std;

class Qnode{
 public:
  
   int data;
   Qnode*next;

   Qnode(int d){
    
     data=d;
     next=NULL;
   }
};

class Queue{
 public:
    Qnode*front,*rear;

    Queue(){
        front=rear=NULL;
    }

    void enqueue(int x){
        Qnode*temp=new Qnode(x);

        // if empty
        if(rear==NULL){
            rear=front=temp;
            return;
        }
        rear->next=temp;
        rear=temp;

    }

    void deque(){
        if(rear==NULL) return;

        Qnode*temp=front;
        front=front->next;
        //if front is null then make front and rear null
        if(front==NULL)  rear=NULL;
        delete temp;
    }

    void display(){
        if(front==rear) return;
        int count=0;
        while(front!=NULL){
            cout<<front->data<<"<-";
            front=front->next;
            count++;
        }
        cout<<endl;
        cout<<"size is:"<<count<<endl;
    }

};



int main(){
Queue q;
q.enqueue(3);
q.enqueue(7);
q.enqueue(4);
q.enqueue(9);
q.deque();
cout<<"q front is:"<<(q.front)->data<<endl;
cout<<"q rear is:"<<(q.rear)->data<<endl;
q.display();



return 0;
}