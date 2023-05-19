#include<iostream>
#include<stack>
using namespace std;

class Stack{
 public:
   int *arr;
   int top;
   int size;
   //constructor
   Stack(int size){
    this->size=size;
    top=-1;
    arr=new int[size];
   }
   

void push(int element){
    if(size-top>1){  //i.e space is available
        top++;
        arr[top]=element;
    }
    else{
        cout<<"stack overflow"<<endl;
    }
}

void pop(){
    if(top>=0) top--;
    else cout<<"Stack underflow"<<endl;
}

int peak(){
    if(top>=0 && top<size) return arr[top];
    else {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
}

bool isEmtpy(){
    if(top==-1){
        return true;
    }
    else return false;
}

};
int main(){
 
 Stack st(5);
 st.push(22);
 st.push(8);
 st.push(12);
 st.push(34);
 cout<<st.peak()<<endl;
 st.pop();
 cout<<st.peak()<<endl;
 st.pop();
 if(st.isEmtpy()){
    cout<<"stack is emtpy"<<endl;
 }
 else cout<<"stack is not empty"<<endl;

 /*
 stl implementation of stack
stack<int>s;
s.push(3);
s.push(1);
s.push(5);
s.push(8);
cout<<s.top()<<endl;
s.pop();
cout<<s.size()<<endl;

 */

return 0;
}