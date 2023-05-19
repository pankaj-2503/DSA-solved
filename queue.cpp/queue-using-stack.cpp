#include<bits/stdc++.h>
using namespace std;

class Queue{
    stack<int>s,p;
    public:
    void enqueue(int x){
        //3 step processs 
        //first put all element from s1 to s2
        //2.push element to s1
        //3.put all element from s2 to s1
        while(!s.empty()){
            p.push(s.top());
            s.pop();
        }
        s.push(x);
        while(!p.empty()){
            s.push(p.top());
            p.pop();
        }
    }
    int deque(){
        if(s.empty()){
            cout<<"Q is empty"<<endl;
        }
        int top=s.top();
        s.pop();
        return top;
    }
       
};
int main(){
Queue q;
q.enqueue(3);
q.enqueue(1);
q.enqueue(8);
cout<<q.deque()<<endl;
cout<<q.deque()<<endl;
return 0;
}