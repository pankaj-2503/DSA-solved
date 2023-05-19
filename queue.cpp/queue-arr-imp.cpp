#include<iostream>
#include<queue>
using namespace std;
// in queue we pop from front(using front) and push from back(using rear)
class Queue{
    public:
      int *arr;
      int qfront;
      int rear;
      int size;
      
      //constructor
      Queue(){
          size=1000001;
          arr=new int[size];
          qfront=0;
          rear=0;
      }


    bool isEmpty(){
      if(qfront==rear){
        cout<<"Empty or not:";
       return true;
       }
    else{ 
        cout<<"Empty or not:";
            return false;
            }
    }

    void enqueue(int data){
       if(rear==size){
        cout<<"Queue is full"<<endl;
       }
       else{
        arr[rear]=data;
        rear++;
       }
    }

    int deque(){
       if(qfront==rear) return -1;
       else{
        int ans=arr[qfront];
        arr[qfront]=-1;
        qfront++;
        //if the element to delete is at last position 
        if(qfront==rear){
            qfront=0;rear=0;
        }
        return ans;
       }
    }

    int front(){
        if(qfront==rear){
            return -1;
        }
        else return arr[qfront];
    }

    void display(){
        if(qfront==rear){
            return ;
        }
        else{
            for(int i=qfront;i<rear;i++){
                cout<<arr[i]<<"<-";
            }
            cout<<endl;
        }
    }

};




int main(){
Queue q;
q.enqueue(5);
q.enqueue(2);
q.enqueue(9);
q.enqueue(3);
q.enqueue(1);
cout<<q.deque()<<endl;
cout<<q.front()<<endl;
cout<<q.isEmpty()<<endl;
q.display();





/* 
//queue implementation using stl
queue<int>q;
q.push(3);
q.push(5);
q.push(1);
q.push(9);
cout<<q.size()<<endl;
cout<<q.front()<<endl;
q.pop();
cout<<q.front()<<endl;
if(q.empty()){
    cout<<"q is empty"<<endl;
}
else cout<<"q is not empty"<<endl;
*/
return 0;
}