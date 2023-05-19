#include<bits/stdc++.h>
using namespace std;
//using one queue
class Stack{
   queue<int>q;
   public:
      void push(int x);
      void pop();
      int top();
      bool empty();
};

void Stack::push(int x){
    //put 1st element then 
    //push next element upto previous size and pop all
    int s=q.size();
    q.push(x);
    for(int i=0;i<s;i++){
        q.push(q.front());
        q.pop();
    }
    
}

void Stack::pop(){
    if(q.empty()) cout<<"No element:"<<endl;
    else q.pop();
}

int Stack::top(){
    return (q.empty())?-1:q.front();
}

bool Stack::empty(){
    return (q.empty());
}
int main(){
Stack st;
st.push(3);
st.push(6);
st.push(8);
cout<<st.top()<<endl;
cout<<st.empty()<<endl;
st.pop();
cout<<st.top()<<endl;
return 0;
}