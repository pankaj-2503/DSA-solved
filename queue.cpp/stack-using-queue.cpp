#include<bits/stdc++.h>
using namespace std;

class Stack{
    //two inbuilt queue
    queue<int>q1,q2;
  public:
    // we need 2 queue
    // it is 3 step process
    //add x to q2
    //put q1 to q2
    //swap q1 and q2
    void push(int x){
        q2.push(x);
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        //swap
        queue<int>q=q1;
        q1=q2;
        q2=q;
    }

    void pop(){
        if(q1.empty()) return ;
        q1.pop();
    }
    int top(){
        if(q1.empty()) return -1;
        return q1.front();
    }
    int size(){
       return q1.size();
    }


};
int main(){
Stack s;
s.push(2);
s.push(5);
s.push(7);
cout<<s.top()<<endl;
s.push(9);
cout<<s.size()<<endl;
s.pop();
cout<<s.size()<<endl;
cout<<s.top()<<endl;

return 0;
}