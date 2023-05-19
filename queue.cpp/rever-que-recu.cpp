#include<bits/stdc++.h>
using namespace std;

void printQueue(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}

void reverseQueue(queue<int>&q){
    //check if empty
    if(q.empty()) return ;
    //take first element and pop it
   int top=q.front();
   q.pop();
   //recursive call to function
   reverseQueue(q);
   //push the front to last
   q.push(top);

}
int main(){
queue<int>q;
q.push(3);
q.push(0);
q.push(5);
q.push(7);
q.push(9);
cout<<"Normal queue is  :";
printQueue(q);
reverseQueue(q);
cout<<"Reversed queue is:";
printQueue(q);

return 0;
}